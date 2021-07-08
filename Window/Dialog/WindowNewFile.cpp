#include "WindowNewFile.h"
#include "ui_WindowNewFile.h"
#include <QToolBox>
#include <QDebug>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QMap>
#include <QList>

#include <ProjectManager.h>
#include <Window/WindowWorker.h>

WindowNewFile::WindowNewFile() :
    QDialog(WindowWorker::getInstance()),
    ui(new Ui::WindowNewFile)
{
    ui->setupUi(this);

    QStandardItemModel* group = new QStandardItemModel(ui->lst_group);
    ui->lst_group->setModel(group);

    QStandardItemModel* types = new QStandardItemModel(ui->lst_types);
    ui->lst_types->setModel(types);

    this->setLayout(ui->gridLayout_2);
}


static WindowNewFile* internal_getInstance()
{
    static WindowNewFile* instance = new WindowNewFile;
    return instance;
}

WindowNewFile::~WindowNewFile()
{
    delete ui;
}

static QList<NewFileTypeInfo>* internal_fileTypeInfos()
{
    static auto p = new QList<NewFileTypeInfo>;
    return p;
}

static QMap<QString, QList<NewFileTemplateInfo>>* internal_infos()
{
    static auto info = new QMap<QString, QList<NewFileTemplateInfo>>;
    return info;
}

void WindowNewFile::clearTypeList()
{
    QStandardItemModel* typesModel = static_cast<QStandardItemModel*>(ui->lst_types->model());
    //clear typesList
    int count = typesModel->rowCount();
    for (int i = 0; i < count; i++) {
        delete typesModel->takeItem(0);
        typesModel->removeRow(0);
    }
}

void WindowNewFile::clearState()
{
    ui->txt_filename->setText(QString());
    ui->cmb_path->setCurrentText(QString());
    ui->lbl_type->setText(QString());
    ui->lbl_description->setText(QString());
}

void WindowNewFile::registerFileType(const NewFileTypeInfo& type)
{
    internal_fileTypeInfos()->push_back(type);
    QStandardItemModel* model = static_cast<QStandardItemModel*>(internal_getInstance()->ui->lst_group->model());
    model->appendRow(new QStandardItem(type.name));
}

void WindowNewFile::registerFileTemplate(const QString& type, const NewFileTemplateInfo& info)
{
    (*internal_infos())[type].append(info);
}



QString WindowNewFile::newFile()
{
    auto self = internal_getInstance();
    self->hasResult = false;
    self->clearState();
    self->clearTypeList();
    self->exec();
    if (!self->hasResult || self->ui->txt_filename->text().isNull() || self->ui->txt_filename->text().isEmpty()) {
        return QString{};
    }
    return self->ui->cmb_path->currentText() + "/" + self->ui->txt_filename->text();
}

void WindowNewFile::on_lst_group_clicked(const QModelIndex& index)
{
    this->clearTypeList();
    QStandardItemModel* typesModel = static_cast<QStandardItemModel*>(ui->lst_types->model());

    auto selType = internal_fileTypeInfos()->at(index.row()).type;

    for (auto& itemInfo : internal_infos()->operator[](selType)) {
        auto item = new QStandardItem(itemInfo.name);
        item->setSizeHint(QSize(10, 36));
        typesModel->appendRow(item);
    }

}


void WindowNewFile::on_lst_types_clicked(const QModelIndex& index)
{
    auto selType = internal_fileTypeInfos()->at(ui->lst_group->currentIndex().row()).type;
    auto tmplInfo = internal_infos()->operator[](selType)[index.row()];

    ui->lbl_type->setText(tr("类型：") + tmplInfo.name);
    ui->lbl_description->setText(tmplInfo.desc);
    ui->txt_filename->setText(tmplInfo.file);
}



void WindowNewFile::on_btn_cancel_clicked()
{
    this->hide();
}


void WindowNewFile::on_btn_ok_clicked()
{
    if (ui->txt_filename->text().isEmpty()) {
        QMessageBox::warning(nullptr, "alert", tr("请输入文件名"));
        return;
    }

    QString path = ProjectManager::projectPath() + "/" + ui->cmb_path->currentText();
    if (!QDir(path).exists()) {
        QMessageBox::warning(nullptr, "alert", tr("文件夹不存在"));
        return;
    }
    QString filename = path + "/" + ui->txt_filename->text();
    QFile file(filename);
    if (file.exists()) {
        QMessageBox::warning(nullptr, "alert", tr("文件存在"));
        return;
    }

    this->hasResult = true;
    this->close();
}
#include "WindowNewFile.h"
#include "ui_WindowNewFile.h"
#include <QToolBox>
#include <QDebug>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <ProjectManager.h>

WindowNewFile::WindowNewFile() :
    QDialog(nullptr),
    ui(new Ui::WindowNewFile)
{
    ui->setupUi(this);
    //this->setModal(true);
    //this->setWindowModality(Qt::WindowModality::WindowModal);

    QStandardItemModel* group = new QStandardItemModel(ui->lst_group);
    ui->lst_group->setModel(group);

    QStandardItemModel* types = new QStandardItemModel(ui->lst_types);
    ui->lst_types->setModel(types);

    this->setLayout(ui->gridLayout_2);
}


static WindowNewFile* getInstance()
{
    static WindowNewFile* instance = new WindowNewFile;
    return instance;
}

WindowNewFile::~WindowNewFile()
{
    delete ui;
}
static NewFileData* infos()
{
    static NewFileData* info = new NewFileData;
    return info;
}

void WindowNewFile::clearTypeList()
{
    QStandardItemModel* typesModel = static_cast<QStandardItemModel*>(ui->lst_types->model());
    //clear typesList
    for (int i = 0; i < typesModel->rowCount(); i++) {
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

void WindowNewFile::registerFileType(const NewFileInfo& info)
{
    infos()->prepareGroup(info.group)->items.push_back(info);
    QStandardItemModel* model = static_cast<QStandardItemModel*>(getInstance()->ui->lst_group->model());
    model->appendRow(new QStandardItem(info.group));
}

QString WindowNewFile::newFile()
{
    auto self = getInstance();
    self->isCheck = false;
    self->clearState();
    self->clearTypeList();
    self->exec();
    if (!self->isCheck || self->ui->txt_filename->text().isNull() || self->ui->txt_filename->text().isEmpty()) {
        return QString::Null();
    }
    return self->ui->cmb_path->currentText() + "/" + self->ui->txt_filename->text();
}

void WindowNewFile::on_lst_group_clicked(const QModelIndex& index)
{
    this->clearTypeList();
    QStandardItemModel* typesModel = static_cast<QStandardItemModel*>(ui->lst_types->model());

    for (auto& itemInfo : infos()->groups[index.row()].items) {
        auto item = new QStandardItem(itemInfo.typeName);
        item->setSizeHint(QSize(10, 36));
        typesModel->appendRow(item);
    }

}


void WindowNewFile::on_lst_types_clicked(const QModelIndex& index)
{
    NewFileInfo info = infos()->groups[ui->lst_group->currentIndex().row()].items[index.row()];

    ui->lbl_type->setText(tr("类型：") + info.typeName);
    ui->lbl_description->setText(info.description);
    ui->txt_filename->setText(info.defaultName);
    ui->cmb_path->setCurrentText(info.defaultPath);
}



void WindowNewFile::on_btn_cancel_clicked()
{
    this->hide();
}


void WindowNewFile::on_btn_ok_clicked()
{
    if(ui->cmb_path->currentText().isEmpty()) {
        QMessageBox::warning(nullptr, "alert", tr("请选择文件模板或输入文件名"));
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

    this->isCheck = true;
    this->close();
}


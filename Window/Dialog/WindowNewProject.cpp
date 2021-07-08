#include "WindowNewProject.h"
#include "ui_WindowNewProject.h"
#include <Window/WindowWorker.h>
#include <QStandardItemModel>
#include <QDebug>
#include <QMessageBox>
#include <QStandardPaths>
#include <QDir>

static WindowNewProject* getInstance()
{
    static WindowNewProject* instance = new WindowNewProject;
    return instance;
}
static QList<NewProjectInfo>* infos()
{
    static auto info = new QList<NewProjectInfo>;
    return info;
}

WindowNewProject::WindowNewProject() :
    QDialog(WindowWorker::getInstance()),
    ui(new Ui::WindowNewProject)
{
    ui->setupUi(this);
    auto items = new QStandardItemModel(this);
    ui->listView->setModel(items);
}

WindowNewProject::~WindowNewProject()
{
    delete ui;
}


void WindowNewProject::registerProjTemplate(const NewProjectInfo& info)
{
    infos()->push_back(info);
    auto self = getInstance();
    auto model = static_cast<QStandardItemModel*>(self->ui->listView->model());
    model->appendRow(new QStandardItem{ info.name });
}

void WindowNewProject::clearList()
{
    QStandardItemModel* typesModel = static_cast<QStandardItemModel*>(ui->listView->model());
    //clear typesList
    for (int i = 0; i < typesModel->rowCount(); i++) {
        delete typesModel->takeItem(0);
        typesModel->removeRow(0);
    }
}

void WindowNewProject::resetState()
{
    this->projName = QString();
    this->projPath = QString();
    this->hasResult = false;
    ui->projName->setText(QString("NewSolution"));
    auto homePath = QStandardPaths::writableLocation(QStandardPaths::StandardLocation::HomeLocation);
    auto path = homePath + "/" + QApplication::applicationName();
    ui->projPath->setText(path);
}


NewProjectResult WindowNewProject::newProject()
{
    WindowNewProject* self = getInstance();
    self->resetState();
    self->exec();
    if (!self->hasResult) {
        return { false };
    }

    return { true, self->projName, self->projPath , self->projFullPath };
}

static bool isFolderEmpty(const QString& folder)
{
    QDir dir{ folder };
    dir.setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    return dir.entryInfoList().count() <= 0;
}

void WindowNewProject::on_submit_clicked()
{
    if (ui->listView->currentIndex().row() < 0) {
        QMessageBox::information(this, "info", tr("请选择项目模板"));
        return;
    }

    this->projName = ui->projName->text();
    this->projPath = ui->projPath->text();

    if (this->projName.isEmpty() || this->projPath.isEmpty())
    {
        QMessageBox::information(this, "info", tr("请输入项目名与位置"));
        return;
    }

    this->projFullPath = this->projPath + "/" + this->projName;

    QDir dir;
    if (!dir.exists(this->projPath))
    {
        dir.mkpath(this->projPath);
    }

    QDir projDir{ this->projFullPath };
    if (projDir.exists())
    {
        if (!isFolderEmpty(this->projFullPath))
        {
            QMessageBox::information(this, "info", tr("该项目路径已被其他项目占用"));
            return;
        }
    }
    else
    {
        projDir.mkdir(this->projFullPath);
    }

    const NewProjectInfo& info = infos()->at(ui->listView->currentIndex().row());

    if (info.createCb != nullptr && !info.createCb(this->projName, this->projPath))
    {
        return;
    }

    this->hasResult = true;
    this->close();
}

void WindowNewProject::on_listView_clicked(const QModelIndex& index)
{
    const NewProjectInfo& info = infos()->at(ui->listView->currentIndex().row());
    ui->description->setText(info.description);
}


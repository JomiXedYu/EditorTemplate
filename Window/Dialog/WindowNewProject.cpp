#include "WindowNewProject.h"
#include "ui_WindowNewProject.h"
#include <QStandardItemModel>
#include <QDebug>

WindowNewProject::WindowNewProject() :
    QDialog(nullptr),
    ui(new Ui::WindowNewProject)
{
    ui->setupUi(this);
    //this->setWindowModality(Qt::WindowModality::WindowModal);

    auto items = new QStandardItemModel(this);
    for(int i = 0; i < 5; i++) {
        items->appendRow(new QStandardItem(i));
    }
    ui->listView->setModel(items);
}

WindowNewProject::~WindowNewProject()
{
    delete ui;
}

static WindowNewProject* getInstance()
{
    static WindowNewProject* instance = new WindowNewProject;
    return instance;
}

QString WindowNewProject::newProject()
{
    WindowNewProject* self = getInstance();
    self->show();
    self->exec();
    return QString();
}



#include "WindowProject.h"
#include "ui_WindowProject.h"

#include <QCloseEvent>
#include <QShowEvent>

#include <AssetDataBase.h>

WindowProject::WindowProject() :
    ui(new Ui::WindowProject)
{
    ui->setupUi(this);
    //this->setLayout(ui->layout_central);
}

WindowProject::~WindowProject()
{
    delete ui;
}

QString WindowProject::windowType()
{
    return "Project";
}

QString WindowProject::getCurDir()
{
    return QString();
}

void WindowProject::onDataRefresh()
{

}

void WindowProject::showEvent(QShowEvent *e)
{
    AssetDataBase::onRefresh().AddListener(this, &WindowProject::onDataRefresh);

}

void WindowProject::closeEvent(QCloseEvent *e)
{
    e->accept();
    AssetDataBase::onRefresh().RemoveListener(this, &WindowProject::onDataRefresh);
}

QString WindowProject::getWindowType() const
{
    return windowType();
}

void WindowProject::onWindowSave()
{

}

bool WindowProject::onWindowClosing()
{
    return true;
}

void WindowProject::onWindowClosed()
{

}

#include "WindowWorker.h"
#include "ui_WindowWorker.h"
#include <QMessageBox>
#include <QFile>
#include <QDir>

#include <Window/Dialog/WindowNewProject.h>
#include <Window/Dialog/WindowNewFile.h>
#include <Window/WindowProject.h>
#include <Window/WindowStage.h>
#include <Window/WindowOutliner.h>
#include <Window/WindowPropertyControls.h>

#include <DockManager.h>
#include <ProjectManager.h>

WindowWorker::WindowWorker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WindowWorker)
{
    using namespace ads;
    ui->setupUi(this);
    CDockManager::setConfigFlags(CDockManager::DefaultOpaqueConfig);
    CDockManager::setConfigFlag(CDockManager::FocusHighlighting, false);
    CDockManager::setConfigFlag(CDockManager::AllTabsHaveCloseButton, true);

    dockManager = new ads::CDockManager(this);

    QFile qss = QFile(QDir::currentPath() + "/dark.qss");
    qss.open(QFile::ReadOnly);
    dockManager->setStyleSheet("");
    //dockManager->setStyleSheet(qss.readAll());
    qss.close();

    CDockWidget* project = new ads::CDockWidget(WindowProject::windowType());
    project->setWidget(new WindowProject);
    dockManager->addDockWidget(ads::BottomDockWidgetArea, project);

    CDockWidget* stage = new CDockWidget(WindowStage::windowType());
    stage->setWidget(new WindowStage);
    dockManager->addDockWidget(ads::RightDockWidgetArea, stage);

    CDockWidget* outliner = new CDockWidget(WindowOutliner::windowType());
    outliner->setWidget(new WindowOutliner);
    dockManager->addDockWidget(ads::LeftDockWidgetArea, outliner);

    CDockWidget* propertyCtrl = new CDockWidget(WindowPropertyControls::windowType());
    propertyCtrl->setWidget(new WindowPropertyControls);
    dockManager->addDockWidget(ads::RightDockWidgetArea, propertyCtrl);

    ui->action_file_new_file->setEnabled(ProjectManager::isOpened());

    ProjectManager::openProjectEvent().AddListener(this, [this](){
        this->ui->action_file_new_file->setEnabled(true);
    });

    ProjectManager::closedProjectEvent().AddListener(this, [this]() {
        this->ui->action_file_new_file->setEnabled(false);
    });

}

WindowWorker::~WindowWorker()
{
    ProjectManager::openProjectEvent().RemoveByInstance(this);
    ProjectManager::closedProjectEvent().RemoveByInstance(this);
    delete ui;
}


void WindowWorker::on_action_file_new_project_triggered()
{
    WindowNewProject::newProject();
}


void WindowWorker::on_action_file_new_file_triggered()
{
    WindowNewFile::newFile();
}

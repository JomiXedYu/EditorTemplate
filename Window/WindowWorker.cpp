#include "WindowWorker.h"
#include "ui_WindowWorker.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QApplication>

#include <Window/Dialog/WindowNewProject.h>
#include <Window/Dialog/WindowNewFile.h>
#include <Window/WindowProject.h>
#include <Window/WindowStage.h>
#include <Window/WindowOutliner.h>
#include <Window/WindowPropertyControls.h>

#include <DockManager.h>
#include <ProjectManager.h>

WindowWorker::WindowWorker(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::WindowWorker)
{
    ui->setupUi(this);


    using namespace ads;

    CDockManager::setConfigFlags(CDockManager::DefaultOpaqueConfig);
    CDockManager::setConfigFlag(CDockManager::FocusHighlighting, false);
    CDockManager::setConfigFlag(CDockManager::AllTabsHaveCloseButton, true);

    dockManager = new ads::CDockManager(this);

    dockManager->setStyleSheet("");

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

    this->reloadTitle();
    this->reloadActionState();

    ProjectManager::openProjectEvent().AddListener(this, [this]() {
        this->reloadTitle();
        this->reloadActionState();
        });

    ProjectManager::closedProjectEvent().AddListener(this, [this]() {
        this->reloadTitle();
        this->reloadActionState();
        });
}

WindowWorker::~WindowWorker()
{
    ProjectManager::openProjectEvent().RemoveByInstance(this);
    ProjectManager::closedProjectEvent().RemoveByInstance(this);
    delete ui;
}

void WindowWorker::reloadTitle()
{
    if (ProjectManager::isOpened()) {
        this->setWindowTitle(QApplication::applicationDisplayName() + " - " + ProjectManager::projectName());
    }
    else {
        this->setWindowTitle(QApplication::applicationDisplayName());
    }
}

static QAction* _findMenu(QList<QAction*> list, QString name)
{
    for (auto& item : list)
    {
        QMenu* menu = item->menu();
        if (menu != nullptr && menu->objectName() == name)
        {
            return item;
        }
    }
    return nullptr;
}

void WindowWorker::reloadActionState()
{
    bool isopen = ProjectManager::isOpened();
    this->ui->action_file_closeproj->setEnabled(isopen);
    this->ui->action_file_new_file->setEnabled(isopen);

    auto recents = ProjectManager::recentProjects();

    QMenu* menu_file = _findMenu(this->menuBar()->actions(), "menu_file")->menu();
    QMenu* menu_file_recent = _findMenu(menu_file->actions(), "menu_file_recent")->menu();

    for (auto item : menu_file_recent->actions())
    {
        if (item->isSeparator() || item->objectName() == "action_file_recent_clear")
        {
            continue;
        }
        disconnect(item);
        menu_file_recent->removeAction(item);
        delete item;
    }

    for (QString& item : recents)
    {
        auto act = new QAction(item, menu_file_recent);
        
        connect(act, &QAction::triggered, this,
            [item]()
            {
                if (ProjectManager::closeProject())
                    ProjectManager::openProject(item);
            });
        menu_file_recent->addAction(act);
    }

}


void WindowWorker::on_action_file_new_project_triggered()
{
    auto result = WindowNewProject::newProject();
    if (result.isSuccess)
    {
        ProjectManager::newProject(result.projFullPath);
        if (ProjectManager::closeProject())
        {
            ProjectManager::openProject(result.projFullPath);
        }
    }
}


void WindowWorker::on_action_file_new_file_triggered()
{
    WindowNewFile::newFile();
}

void WindowWorker::on_action_file_openproj_triggered()
{
    auto path = QFileDialog::getExistingDirectory(this);
    if (path.isEmpty())
    {
        return;
    }
    if (!QDir().exists(path + "/workspace"))
    {
        QMessageBox::warning(this, "warning", tr("错误的项目文件夹"));
        return;
    }
    ProjectManager::closeProject();
    ProjectManager::openProject(path);

}


void WindowWorker::on_action_file_closeproj_triggered()
{
    ProjectManager::closeProject();
}


void WindowWorker::on_action_file_recent_clear_triggered()
{
    ProjectManager::clearRecentProjects();
    this->reloadActionState();
}


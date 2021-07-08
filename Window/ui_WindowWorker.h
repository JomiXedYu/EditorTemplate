/********************************************************************************
** Form generated from reading UI file 'WindowWorker.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWWORKER_H
#define UI_WINDOWWORKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowWorker
{
public:
    QAction *action_file_new_project;
    QAction *action_file_exit;
    QAction *action_Z;
    QAction *action_Y;
    QAction *action_2;
    QAction *actionsave;
    QAction *action_file_new_file;
    QAction *action_file_openproj;
    QAction *action_file_closeproj;
    QAction *action_file_recent_clear;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu_file_new;
    QMenu *menu_file_recent;
    QMenu *menu_edit;
    QMenu *menu_help;
    QMenu *menu_view;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *WindowWorker)
    {
        if (WindowWorker->objectName().isEmpty())
            WindowWorker->setObjectName(QString::fromUtf8("WindowWorker"));
        WindowWorker->resize(1440, 900);
        action_file_new_project = new QAction(WindowWorker);
        action_file_new_project->setObjectName(QString::fromUtf8("action_file_new_project"));
        action_file_exit = new QAction(WindowWorker);
        action_file_exit->setObjectName(QString::fromUtf8("action_file_exit"));
        action_Z = new QAction(WindowWorker);
        action_Z->setObjectName(QString::fromUtf8("action_Z"));
        action_Y = new QAction(WindowWorker);
        action_Y->setObjectName(QString::fromUtf8("action_Y"));
        action_2 = new QAction(WindowWorker);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        actionsave = new QAction(WindowWorker);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        action_file_new_file = new QAction(WindowWorker);
        action_file_new_file->setObjectName(QString::fromUtf8("action_file_new_file"));
        action_file_openproj = new QAction(WindowWorker);
        action_file_openproj->setObjectName(QString::fromUtf8("action_file_openproj"));
        action_file_closeproj = new QAction(WindowWorker);
        action_file_closeproj->setObjectName(QString::fromUtf8("action_file_closeproj"));
        action_file_recent_clear = new QAction(WindowWorker);
        action_file_recent_clear->setObjectName(QString::fromUtf8("action_file_recent_clear"));
        centralwidget = new QWidget(WindowWorker);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        WindowWorker->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WindowWorker);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1440, 22));
        menu_file = new QMenu(menubar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_file_new = new QMenu(menu_file);
        menu_file_new->setObjectName(QString::fromUtf8("menu_file_new"));
        menu_file_recent = new QMenu(menu_file);
        menu_file_recent->setObjectName(QString::fromUtf8("menu_file_recent"));
        menu_edit = new QMenu(menubar);
        menu_edit->setObjectName(QString::fromUtf8("menu_edit"));
        menu_help = new QMenu(menubar);
        menu_help->setObjectName(QString::fromUtf8("menu_help"));
        menu_view = new QMenu(menubar);
        menu_view->setObjectName(QString::fromUtf8("menu_view"));
        WindowWorker->setMenuBar(menubar);
        statusbar = new QStatusBar(WindowWorker);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WindowWorker->setStatusBar(statusbar);
        toolBar = new QToolBar(WindowWorker);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        WindowWorker->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu_edit->menuAction());
        menubar->addAction(menu_view->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_file->addAction(menu_file_new->menuAction());
        menu_file->addAction(action_file_openproj);
        menu_file->addAction(menu_file_recent->menuAction());
        menu_file->addSeparator();
        menu_file->addAction(action_file_closeproj);
        menu_file->addSeparator();
        menu_file->addAction(action_file_exit);
        menu_file_new->addAction(action_file_new_project);
        menu_file_new->addAction(action_file_new_file);
        menu_file_recent->addSeparator();
        menu_file_recent->addSeparator();
        menu_file_recent->addAction(action_file_recent_clear);
        menu_file_recent->addSeparator();
        menu_edit->addAction(action_Z);
        menu_edit->addAction(action_Y);
        menu_edit->addSeparator();
        menu_edit->addAction(action_2);
        toolBar->addAction(actionsave);

        retranslateUi(WindowWorker);

        QMetaObject::connectSlotsByName(WindowWorker);
    } // setupUi

    void retranslateUi(QMainWindow *WindowWorker)
    {
        WindowWorker->setWindowTitle(QCoreApplication::translate("WindowWorker", "WorkerWindow", nullptr));
        action_file_new_project->setText(QCoreApplication::translate("WindowWorker", "\351\241\271\347\233\256", nullptr));
        action_file_exit->setText(QCoreApplication::translate("WindowWorker", "\351\200\200\345\207\272(&X)", nullptr));
        action_Z->setText(QCoreApplication::translate("WindowWorker", "\346\222\244\351\224\200(&Z)", nullptr));
        action_Y->setText(QCoreApplication::translate("WindowWorker", "\346\201\242\345\244\215(&Y)", nullptr));
        action_2->setText(QCoreApplication::translate("WindowWorker", "\351\246\226\351\200\211\351\241\271", nullptr));
        actionsave->setText(QCoreApplication::translate("WindowWorker", "save", nullptr));
        action_file_new_file->setText(QCoreApplication::translate("WindowWorker", "\346\226\207\344\273\266(&N)", nullptr));
#if QT_CONFIG(shortcut)
        action_file_new_file->setShortcut(QCoreApplication::translate("WindowWorker", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_file_openproj->setText(QCoreApplication::translate("WindowWorker", "\346\211\223\345\274\200\351\241\271\347\233\256(&O)", nullptr));
        action_file_closeproj->setText(QCoreApplication::translate("WindowWorker", "\345\205\263\351\227\255\351\241\271\347\233\256", nullptr));
        action_file_recent_clear->setText(QCoreApplication::translate("WindowWorker", "\346\270\205\351\231\244\350\256\260\345\275\225", nullptr));
        menu_file->setTitle(QCoreApplication::translate("WindowWorker", "\346\226\207\344\273\266(&F)", nullptr));
        menu_file_new->setTitle(QCoreApplication::translate("WindowWorker", "\346\226\260\345\273\272(&N)", nullptr));
        menu_file_recent->setTitle(QCoreApplication::translate("WindowWorker", "\346\234\200\350\277\221\346\211\223\345\274\200\347\232\204\351\241\271\347\233\256", nullptr));
        menu_edit->setTitle(QCoreApplication::translate("WindowWorker", "\347\274\226\350\276\221(&E)", nullptr));
        menu_help->setTitle(QCoreApplication::translate("WindowWorker", "\345\270\256\345\212\251(&H)", nullptr));
        menu_view->setTitle(QCoreApplication::translate("WindowWorker", "\350\247\206\345\233\276(&V)", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("WindowWorker", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowWorker: public Ui_WindowWorker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWWORKER_H

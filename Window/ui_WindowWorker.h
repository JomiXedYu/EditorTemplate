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
    QAction *action_file_new_file;
    QAction *action_file_exit;
    QAction *action_Z;
    QAction *action_Y;
    QAction *action;
    QAction *action_2;
    QAction *actionsave;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_3;
    QMenu *menu_2;
    QMenu *menu_H;
    QMenu *menu_4;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *WindowWorker)
    {
        if (WindowWorker->objectName().isEmpty())
            WindowWorker->setObjectName(QString::fromUtf8("WindowWorker"));
        WindowWorker->resize(1440, 900);
        action_file_new_project = new QAction(WindowWorker);
        action_file_new_project->setObjectName(QString::fromUtf8("action_file_new_project"));
        action_file_new_file = new QAction(WindowWorker);
        action_file_new_file->setObjectName(QString::fromUtf8("action_file_new_file"));
        action_file_exit = new QAction(WindowWorker);
        action_file_exit->setObjectName(QString::fromUtf8("action_file_exit"));
        action_Z = new QAction(WindowWorker);
        action_Z->setObjectName(QString::fromUtf8("action_Z"));
        action_Y = new QAction(WindowWorker);
        action_Y->setObjectName(QString::fromUtf8("action_Y"));
        action = new QAction(WindowWorker);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(WindowWorker);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        actionsave = new QAction(WindowWorker);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        centralwidget = new QWidget(WindowWorker);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        WindowWorker->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WindowWorker);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1440, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_3 = new QMenu(menu);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_H = new QMenu(menubar);
        menu_H->setObjectName(QString::fromUtf8("menu_H"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        WindowWorker->setMenuBar(menubar);
        statusbar = new QStatusBar(WindowWorker);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WindowWorker->setStatusBar(statusbar);
        toolBar = new QToolBar(WindowWorker);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        WindowWorker->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu->addAction(menu_3->menuAction());
        menu->addSeparator();
        menu->addAction(action_file_exit);
        menu_3->addAction(action_file_new_project);
        menu_3->addAction(action_file_new_file);
        menu_2->addAction(action_Z);
        menu_2->addAction(action_Y);
        menu_2->addSeparator();
        menu_2->addAction(action_2);
        toolBar->addAction(actionsave);

        retranslateUi(WindowWorker);

        QMetaObject::connectSlotsByName(WindowWorker);
    } // setupUi

    void retranslateUi(QMainWindow *WindowWorker)
    {
        WindowWorker->setWindowTitle(QCoreApplication::translate("WindowWorker", "WorkerWindow", nullptr));
        action_file_new_project->setText(QCoreApplication::translate("WindowWorker", "\351\241\271\347\233\256", nullptr));
        action_file_new_file->setText(QCoreApplication::translate("WindowWorker", "\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        action_file_new_file->setToolTip(QCoreApplication::translate("WindowWorker", "\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        action_file_new_file->setShortcut(QCoreApplication::translate("WindowWorker", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        action_file_exit->setText(QCoreApplication::translate("WindowWorker", "\351\200\200\345\207\272(&X)", nullptr));
        action_Z->setText(QCoreApplication::translate("WindowWorker", "\346\222\244\351\224\200(&Z)", nullptr));
        action_Y->setText(QCoreApplication::translate("WindowWorker", "\346\201\242\345\244\215(&Y)", nullptr));
        action->setText(QCoreApplication::translate("WindowWorker", "-", nullptr));
        action_2->setText(QCoreApplication::translate("WindowWorker", "\351\246\226\351\200\211\351\241\271", nullptr));
        actionsave->setText(QCoreApplication::translate("WindowWorker", "save", nullptr));
        menu->setTitle(QCoreApplication::translate("WindowWorker", "\346\226\207\344\273\266(&F)", nullptr));
        menu_3->setTitle(QCoreApplication::translate("WindowWorker", "\346\226\260\345\273\272(&N)", nullptr));
        menu_2->setTitle(QCoreApplication::translate("WindowWorker", "\347\274\226\350\276\221(&E)", nullptr));
        menu_H->setTitle(QCoreApplication::translate("WindowWorker", "\345\270\256\345\212\251(&H)", nullptr));
        menu_4->setTitle(QCoreApplication::translate("WindowWorker", "\350\247\206\345\233\276(&V)", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("WindowWorker", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowWorker: public Ui_WindowWorker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWWORKER_H

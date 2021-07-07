/********************************************************************************
** Form generated from reading UI file 'WindowStage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWSTAGE_H
#define UI_WINDOWSTAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowStage
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;

    void setupUi(QMainWindow *WindowStage)
    {
        if (WindowStage->objectName().isEmpty())
            WindowStage->setObjectName(QString::fromUtf8("WindowStage"));
        WindowStage->resize(709, 437);
        centralwidget = new QWidget(WindowStage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        WindowStage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WindowStage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 709, 22));
        WindowStage->setMenuBar(menubar);

        retranslateUi(WindowStage);

        QMetaObject::connectSlotsByName(WindowStage);
    } // setupUi

    void retranslateUi(QMainWindow *WindowStage)
    {
        WindowStage->setWindowTitle(QCoreApplication::translate("WindowStage", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowStage: public Ui_WindowStage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSTAGE_H

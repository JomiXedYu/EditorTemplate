/********************************************************************************
** Form generated from reading UI file 'WindowNewProject.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWNEWPROJECT_H
#define UI_WINDOWNEWPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_WindowNewProject
{
public:
    QLabel *label;
    QListView *listView;

    void setupUi(QDialog *WindowNewProject)
    {
        if (WindowNewProject->objectName().isEmpty())
            WindowNewProject->setObjectName(QString::fromUtf8("WindowNewProject"));
        WindowNewProject->resize(814, 523);
        label = new QLabel(WindowNewProject);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 181, 16));
        listView = new QListView(WindowNewProject);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(20, 80, 221, 351));

        retranslateUi(WindowNewProject);

        QMetaObject::connectSlotsByName(WindowNewProject);
    } // setupUi

    void retranslateUi(QDialog *WindowNewProject)
    {
        WindowNewProject->setWindowTitle(QCoreApplication::translate("WindowNewProject", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("WindowNewProject", "\350\257\267\351\200\211\346\213\251\351\241\271\347\233\256\346\250\241\346\235\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowNewProject: public Ui_WindowNewProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWNEWPROJECT_H

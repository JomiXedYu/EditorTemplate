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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WindowNewProject
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *h1;
    QHBoxLayout *horizontalLayout;
    QListView *listView;
    QLabel *description;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *projName;
    QLabel *label_2;
    QLineEdit *projPath;
    QPushButton *submit;

    void setupUi(QDialog *WindowNewProject)
    {
        if (WindowNewProject->objectName().isEmpty())
            WindowNewProject->setObjectName(QString::fromUtf8("WindowNewProject"));
        WindowNewProject->resize(564, 403);
        verticalLayout = new QVBoxLayout(WindowNewProject);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        h1 = new QLabel(WindowNewProject);
        h1->setObjectName(QString::fromUtf8("h1"));

        verticalLayout->addWidget(h1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listView = new QListView(WindowNewProject);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setMaximumSize(QSize(160, 16777215));

        horizontalLayout->addWidget(listView);

        description = new QLabel(WindowNewProject);
        description->setObjectName(QString::fromUtf8("description"));
        description->setFrameShadow(QFrame::Plain);
        description->setTextFormat(Qt::PlainText);

        horizontalLayout->addWidget(description);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(WindowNewProject);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        projName = new QLineEdit(WindowNewProject);
        projName->setObjectName(QString::fromUtf8("projName"));

        gridLayout->addWidget(projName, 0, 1, 1, 1);

        label_2 = new QLabel(WindowNewProject);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        projPath = new QLineEdit(WindowNewProject);
        projPath->setObjectName(QString::fromUtf8("projPath"));

        gridLayout->addWidget(projPath, 1, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        submit = new QPushButton(WindowNewProject);
        submit->setObjectName(QString::fromUtf8("submit"));

        horizontalLayout_2->addWidget(submit);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(WindowNewProject);

        QMetaObject::connectSlotsByName(WindowNewProject);
    } // setupUi

    void retranslateUi(QDialog *WindowNewProject)
    {
        WindowNewProject->setWindowTitle(QCoreApplication::translate("WindowNewProject", "New Project", nullptr));
        h1->setText(QCoreApplication::translate("WindowNewProject", "\350\257\267\351\200\211\346\213\251\351\241\271\347\233\256\346\250\241\346\235\277", nullptr));
        description->setText(QString());
        label->setText(QCoreApplication::translate("WindowNewProject", "\351\241\271\347\233\256\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("WindowNewProject", "\351\241\271\347\233\256\350\267\257\345\276\204", nullptr));
        submit->setText(QCoreApplication::translate("WindowNewProject", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowNewProject: public Ui_WindowNewProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWNEWPROJECT_H

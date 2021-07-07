/********************************************************************************
** Form generated from reading UI file 'WindowProject.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWPROJECT_H
#define UI_WINDOWPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowProject
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QTreeView *treeView;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QSlider *horizontalSlider;

    void setupUi(QMainWindow *WindowProject)
    {
        if (WindowProject->objectName().isEmpty())
            WindowProject->setObjectName(QString::fromUtf8("WindowProject"));
        WindowProject->resize(326, 722);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WindowProject->sizePolicy().hasHeightForWidth());
        WindowProject->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(WindowProject);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        treeView = new QTreeView(splitter);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        splitter->addWidget(treeView);
        listView = new QListView(splitter);
        listView->setObjectName(QString::fromUtf8("listView"));
        splitter->addWidget(listView);

        gridLayout->addWidget(splitter, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy2);
        horizontalSlider->setMaximumSize(QSize(400, 16777215));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 1, 1, 1);

        WindowProject->setCentralWidget(centralwidget);

        retranslateUi(WindowProject);

        QMetaObject::connectSlotsByName(WindowProject);
    } // setupUi

    void retranslateUi(QMainWindow *WindowProject)
    {
        WindowProject->setWindowTitle(QCoreApplication::translate("WindowProject", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("WindowProject", "\350\277\207\346\273\244\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowProject: public Ui_WindowProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWPROJECT_H

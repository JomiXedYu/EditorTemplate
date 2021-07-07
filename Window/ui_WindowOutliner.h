/********************************************************************************
** Form generated from reading UI file 'WindowOutliner.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWOUTLINER_H
#define UI_WINDOWOUTLINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowOutliner
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTreeView *treeView;

    void setupUi(QMainWindow *WindowOutliner)
    {
        if (WindowOutliner->objectName().isEmpty())
            WindowOutliner->setObjectName(QString::fromUtf8("WindowOutliner"));
        WindowOutliner->resize(297, 650);
        centralwidget = new QWidget(WindowOutliner);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout->addWidget(treeView);

        WindowOutliner->setCentralWidget(centralwidget);

        retranslateUi(WindowOutliner);

        QMetaObject::connectSlotsByName(WindowOutliner);
    } // setupUi

    void retranslateUi(QMainWindow *WindowOutliner)
    {
        WindowOutliner->setWindowTitle(QCoreApplication::translate("WindowOutliner", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("WindowOutliner", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowOutliner: public Ui_WindowOutliner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWOUTLINER_H

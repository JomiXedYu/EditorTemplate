/********************************************************************************
** Form generated from reading UI file 'WindowPropertyControls.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWPROPERTYCONTROLS_H
#define UI_WINDOWPROPERTYCONTROLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowPropertyControls
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QCheckBox *checkBox;
    QTextEdit *textEdit;
    QLabel *label;
    QPushButton *pushButton_2;
    QListView *listView;

    void setupUi(QMainWindow *WindowPropertyControls)
    {
        if (WindowPropertyControls->objectName().isEmpty())
            WindowPropertyControls->setObjectName(QString::fromUtf8("WindowPropertyControls"));
        WindowPropertyControls->resize(324, 737);
        centralwidget = new QWidget(WindowPropertyControls);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout->addWidget(radioButton);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        listView = new QListView(centralwidget);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);

        WindowPropertyControls->setCentralWidget(centralwidget);

        retranslateUi(WindowPropertyControls);

        QMetaObject::connectSlotsByName(WindowPropertyControls);
    } // setupUi

    void retranslateUi(QMainWindow *WindowPropertyControls)
    {
        WindowPropertyControls->setWindowTitle(QCoreApplication::translate("WindowPropertyControls", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("WindowPropertyControls", "PushButton", nullptr));
        radioButton->setText(QCoreApplication::translate("WindowPropertyControls", "RadioButton", nullptr));
        checkBox->setText(QCoreApplication::translate("WindowPropertyControls", "CheckBox", nullptr));
        label->setText(QCoreApplication::translate("WindowPropertyControls", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("WindowPropertyControls", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowPropertyControls: public Ui_WindowPropertyControls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWPROPERTYCONTROLS_H

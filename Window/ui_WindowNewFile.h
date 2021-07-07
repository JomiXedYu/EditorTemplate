/********************************************************************************
** Form generated from reading UI file 'WindowNewFile.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWNEWFILE_H
#define UI_WINDOWNEWFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowNewFile
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QListView *lst_group;
    QListView *lst_types;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_ok;
    QPushButton *btn_cancel;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_type;
    QLabel *lbl_description;
    QGridLayout *gridLayout;
    QComboBox *cmb_path;
    QLineEdit *txt_filename;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *btn_browser;

    void setupUi(QDialog *WindowNewFile)
    {
        if (WindowNewFile->objectName().isEmpty())
            WindowNewFile->setObjectName(QString::fromUtf8("WindowNewFile"));
        WindowNewFile->resize(876, 586);
        WindowNewFile->setLayoutDirection(Qt::LeftToRight);
        layoutWidget = new QWidget(WindowNewFile);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 861, 571));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(16);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(20, 20, 20, 20);
        lst_group = new QListView(layoutWidget);
        lst_group->setObjectName(QString::fromUtf8("lst_group"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lst_group->sizePolicy().hasHeightForWidth());
        lst_group->setSizePolicy(sizePolicy);
        lst_group->setMaximumSize(QSize(200, 16777215));
        lst_group->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_2->addWidget(lst_group, 1, 0, 1, 1);

        lst_types = new QListView(layoutWidget);
        lst_types->setObjectName(QString::fromUtf8("lst_types"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lst_types->sizePolicy().hasHeightForWidth());
        lst_types->setSizePolicy(sizePolicy1);
        lst_types->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lst_types->setSpacing(0);
        lst_types->setGridSize(QSize(50, 50));
        lst_types->setUniformItemSizes(false);

        gridLayout_2->addWidget(lst_types, 1, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setScaledContents(false);
        label->setWordWrap(false);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btn_ok = new QPushButton(layoutWidget);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btn_ok->sizePolicy().hasHeightForWidth());
        btn_ok->setSizePolicy(sizePolicy3);
        btn_ok->setMinimumSize(QSize(120, 0));

        verticalLayout_2->addWidget(btn_ok);

        btn_cancel = new QPushButton(layoutWidget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        sizePolicy3.setHeightForWidth(btn_cancel->sizePolicy().hasHeightForWidth());
        btn_cancel->setSizePolicy(sizePolicy3);
        btn_cancel->setMinimumSize(QSize(120, 0));

        verticalLayout_2->addWidget(btn_cancel);


        gridLayout_2->addLayout(verticalLayout_2, 2, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbl_type = new QLabel(layoutWidget);
        lbl_type->setObjectName(QString::fromUtf8("lbl_type"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lbl_type->sizePolicy().hasHeightForWidth());
        lbl_type->setSizePolicy(sizePolicy4);
        lbl_type->setMaximumSize(QSize(200, 16777215));
        lbl_type->setScaledContents(false);
        lbl_type->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(lbl_type);

        lbl_description = new QLabel(layoutWidget);
        lbl_description->setObjectName(QString::fromUtf8("lbl_description"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lbl_description->sizePolicy().hasHeightForWidth());
        lbl_description->setSizePolicy(sizePolicy5);
        lbl_description->setMinimumSize(QSize(200, 0));
        lbl_description->setSizeIncrement(QSize(50, 0));
        lbl_description->setBaseSize(QSize(50, 0));
        lbl_description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(lbl_description);


        gridLayout_2->addLayout(verticalLayout, 1, 2, 1, 2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(1);
        gridLayout->setVerticalSpacing(5);
        cmb_path = new QComboBox(layoutWidget);
        cmb_path->setObjectName(QString::fromUtf8("cmb_path"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(cmb_path->sizePolicy().hasHeightForWidth());
        cmb_path->setSizePolicy(sizePolicy6);
        cmb_path->setMinimumSize(QSize(0, 20));
        cmb_path->setMaximumSize(QSize(16777215, 20));
        cmb_path->setEditable(true);
        cmb_path->setFrame(true);

        gridLayout->addWidget(cmb_path, 1, 1, 1, 1);

        txt_filename = new QLineEdit(layoutWidget);
        txt_filename->setObjectName(QString::fromUtf8("txt_filename"));
        sizePolicy6.setHeightForWidth(txt_filename->sizePolicy().hasHeightForWidth());
        txt_filename->setSizePolicy(sizePolicy6);
        txt_filename->setMinimumSize(QSize(0, 20));
        txt_filename->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(txt_filename, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        btn_browser = new QPushButton(layoutWidget);
        btn_browser->setObjectName(QString::fromUtf8("btn_browser"));
        sizePolicy3.setHeightForWidth(btn_browser->sizePolicy().hasHeightForWidth());
        btn_browser->setSizePolicy(sizePolicy3);
        btn_browser->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(btn_browser, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 2);


        retranslateUi(WindowNewFile);

        btn_ok->setDefault(true);
        btn_browser->setDefault(false);


        QMetaObject::connectSlotsByName(WindowNewFile);
    } // setupUi

    void retranslateUi(QDialog *WindowNewFile)
    {
        WindowNewFile->setWindowTitle(QCoreApplication::translate("WindowNewFile", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
        label->setText(QCoreApplication::translate("WindowNewFile", "\351\200\211\346\213\251\346\226\207\344\273\266\346\250\241\346\235\277", nullptr));
        btn_ok->setText(QCoreApplication::translate("WindowNewFile", "\347\241\256\345\256\232", nullptr));
        btn_cancel->setText(QCoreApplication::translate("WindowNewFile", "\345\217\226\346\266\210", nullptr));
        lbl_type->setText(QCoreApplication::translate("WindowNewFile", "\347\261\273\345\236\213\357\274\232\351\273\230\350\256\244", nullptr));
        label_3->setText(QCoreApplication::translate("WindowNewFile", "\344\275\215\347\275\256\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("WindowNewFile", "\345\220\215\345\255\227\357\274\232", nullptr));
        btn_browser->setText(QCoreApplication::translate("WindowNewFile", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowNewFile: public Ui_WindowNewFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWNEWFILE_H

/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *loginlab;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_11;
    QLabel *errLab;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *userLe;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *passLe;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *savePassCheckBox;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *autoLoginCheckBox;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *loginPtn;
    QSpacerItem *horizontalSpacer_10;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(860, 500);
        LoginDialog->setMinimumSize(QSize(860, 500));
        LoginDialog->setMaximumSize(QSize(860, 500));
        LoginDialog->setStyleSheet(QLatin1String("QDialog#LoginDialog{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(LoginDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(310, 335));
        label->setMaximumSize(QSize(310, 335));
        label->setPixmap(QPixmap(QString::fromUtf8(":/res/login/left.png")));
        label->setScaledContents(true);

        horizontalLayout_9->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(105, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);

        widget = new QWidget(LoginDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(340, 340));
        widget->setMaximumSize(QSize(340, 340));
        widget->setStyleSheet(QLatin1String("QWidget#widget{\n"
"border-image: url(:/res/login/loginbackgroud.png);\n"
"};"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        loginlab = new QLabel(widget);
        loginlab->setObjectName(QStringLiteral("loginlab"));
        loginlab->setMinimumSize(QSize(100, 23));
        loginlab->setMaximumSize(QSize(105, 23));
        loginlab->setStyleSheet(QLatin1String("QLabel#loginlab\n"
"{	\n"
"	color: rgb(100, 137, 217);\n"
"	font:bold 14pt 75 24pt \"Microsoft YaHei UI\";\n"
"	border-radius: 4px;\n"
"	padding: 2px;\n"
"}"));
        loginlab->setScaledContents(true);

        horizontalLayout->addWidget(loginlab);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_11);

        errLab = new QLabel(widget);
        errLab->setObjectName(QStringLiteral("errLab"));
        errLab->setMinimumSize(QSize(0, 15));
        errLab->setMaximumSize(QSize(16777215, 15));
        errLab->setStyleSheet(QLatin1String("QLabel#errLab\n"
"{	\n"
"	color: rgb(235,0,0);\n"
"	font:bold 8pt 75 12pt \"Microsoft YaHei UI\";\n"
"	border-radius: 4px;\n"
"	padding: 2px;\n"
"}"));

        horizontalLayout_10->addWidget(errLab);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        userLe = new QLineEdit(widget);
        userLe->setObjectName(QStringLiteral("userLe"));
        userLe->setMinimumSize(QSize(280, 40));
        userLe->setMaximumSize(QSize(280, 40));
        userLe->setStyleSheet(QLatin1String("QLineEdit#userLe\n"
"{	\n"
"	font: 25 12pt \"Microsoft YaHei UI\";\n"
"    border: 6px;\n"
"    border-radius: 4px;\n"
"    padding-left:40px;\n"
"	background-image: url(:/res/login/user.png);\n"
"}"));
        userLe->setMaxLength(32767);
        userLe->setCursorPosition(0);
        userLe->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(userLe);

        horizontalSpacer_6 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(10, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        passLe = new QLineEdit(widget);
        passLe->setObjectName(QStringLiteral("passLe"));
        passLe->setMinimumSize(QSize(280, 40));
        passLe->setMaximumSize(QSize(280, 40));
        passLe->setStyleSheet(QLatin1String("QLineEdit#passLe\n"
"{	\n"
"	font: 25 12pt \"Microsoft YaHei UI\";\n"
"    border: 6px;\n"
"    border-radius: 4px;\n"
"    padding-left:40px;\n"
"	background-image: url(:/res/login/pass.png);\n"
"}"));

        horizontalLayout_4->addWidget(passLe);

        horizontalSpacer_8 = new QSpacerItem(14, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(130, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(12);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        savePassCheckBox = new QCheckBox(widget);
        savePassCheckBox->setObjectName(QStringLiteral("savePassCheckBox"));
        savePassCheckBox->setMaximumSize(QSize(16, 16));
        savePassCheckBox->setSizeIncrement(QSize(16, 16));
        savePassCheckBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        savePassCheckBox->setLayoutDirection(Qt::LeftToRight);
        savePassCheckBox->setStyleSheet(QLatin1String("QCheckBox#savePassCheckBox::indicator{\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"QCheckBox#savePassCheckBox::indicator:unchecked{\n"
" \n"
"	image: url(:/res/login/unchecked.png);\n"
"}\n"
"QCheckBox#savePassCheckBox::indicator:checked{\n"
"    \n"
"	image: url(:/res/login/checked.png);\n"
"}"));
        savePassCheckBox->setTristate(false);

        horizontalLayout_6->addWidget(savePassCheckBox);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(56, 20));
        label_2->setStyleSheet(QLatin1String("QLabel#label_2{\n"
"	color: #888888;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 14px;	\n"
"	line-height: 11.9px;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_2);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        autoLoginCheckBox = new QCheckBox(widget);
        autoLoginCheckBox->setObjectName(QStringLiteral("autoLoginCheckBox"));
        autoLoginCheckBox->setMaximumSize(QSize(16, 16));
        autoLoginCheckBox->setStyleSheet(QLatin1String("QCheckBox#autoLoginCheckBox::indicator{\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"QCheckBox#autoLoginCheckBox::indicator:unchecked{\n"
" \n"
"	image: url(:/res/login/unchecked.png);\n"
"}\n"
"QCheckBox#autoLoginCheckBox::indicator:checked{\n"
"    \n"
"	image: url(:/res/login/checked.png);\n"
"}"));
        autoLoginCheckBox->setIconSize(QSize(18, 18));
        autoLoginCheckBox->setAutoExclusive(false);
        autoLoginCheckBox->setTristate(false);

        horizontalLayout_2->addWidget(autoLoginCheckBox);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(56, 20));
        label_3->setStyleSheet(QLatin1String("QLabel#label_3{\n"
"	color: #888888;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 14px;	\n"
"	line-height: 11.9px;\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);


        horizontalLayout_7->addLayout(horizontalLayout_2);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_9 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        loginPtn = new QPushButton(widget);
        loginPtn->setObjectName(QStringLiteral("loginPtn"));
        loginPtn->setMinimumSize(QSize(280, 40));
        loginPtn->setMaximumSize(QSize(280, 40));
        loginPtn->setStyleSheet(QLatin1String("QPushButton#loginPtn\n"
"{\n"
"	border-radius: 2px;\n"
"	color:#ffffff;\n"
"	font: bold 12pt 75 18pt \"Microsoft YaHei UI\";\n"
"	background-color: #6489d9;\n"
"}"));

        horizontalLayout_5->addWidget(loginPtn);

        horizontalSpacer_10 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 3);
        verticalLayout->setStretch(3, 3);
        verticalLayout->setStretch(4, 2);
        verticalLayout->setStretch(5, 3);

        horizontalLayout_9->addWidget(widget);


        verticalLayout_2->addLayout(horizontalLayout_9);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "LoginDialog", nullptr));
        label->setText(QString());
        loginlab->setText(QApplication::translate("LoginDialog", "\350\264\246\345\217\267\347\231\273\345\275\225", nullptr));
        errLab->setText(QString());
        userLe->setInputMask(QString());
        userLe->setText(QString());
        passLe->setText(QString());
        savePassCheckBox->setText(QString());
        label_2->setText(QApplication::translate("LoginDialog", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        autoLoginCheckBox->setText(QString());
        label_3->setText(QApplication::translate("LoginDialog", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        loginPtn->setText(QApplication::translate("LoginDialog", "\347\253\213\345\215\263\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H

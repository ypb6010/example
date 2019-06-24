/********************************************************************************
** Form generated from reading UI file 'TwoButtonDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWOBUTTONDIALOG_H
#define UI_TWOBUTTONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "titlebar.h"

QT_BEGIN_NAMESPACE

class Ui_TwoButtonDialog
{
public:
    QVBoxLayout *verticalLayout;
    TitleBar *titleWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *titlelab;
    QToolButton *closeBtn;
    QLabel *textlab;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelBtn;
    QPushButton *okBtn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *TwoButtonDialog)
    {
        if (TwoButtonDialog->objectName().isEmpty())
            TwoButtonDialog->setObjectName(QStringLiteral("TwoButtonDialog"));
        TwoButtonDialog->resize(728, 220);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TwoButtonDialog->sizePolicy().hasHeightForWidth());
        TwoButtonDialog->setSizePolicy(sizePolicy);
        TwoButtonDialog->setMinimumSize(QSize(600, 220));
        TwoButtonDialog->setStyleSheet(QLatin1String("QDialog#TwoButtonDialog\n"
"{\n"
"	background-color: #ffffff;\n"
"}"));
        verticalLayout = new QVBoxLayout(TwoButtonDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        titleWidget = new TitleBar(TwoButtonDialog);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));
        titleWidget->setMinimumSize(QSize(0, 60));
        titleWidget->setMaximumSize(QSize(16777215, 60));
        titleWidget->setStyleSheet(QLatin1String("QWidget#titleWidget\n"
"{\n"
"background-color: #6489d9;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(titleWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        titlelab = new QLabel(titleWidget);
        titlelab->setObjectName(QStringLiteral("titlelab"));
        titlelab->setMaximumSize(QSize(16777215, 16777215));
        titlelab->setStyleSheet(QLatin1String("QLabel#titlelab\n"
"{\n"
"	background-color: #6489d9;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #ffffff;\n"
"}"));
        titlelab->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(titlelab);

        closeBtn = new QToolButton(titleWidget);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMinimumSize(QSize(40, 40));
        closeBtn->setMaximumSize(QSize(40, 40));
        closeBtn->setStyleSheet(QLatin1String("QToolButton#closeBtn\n"
"{\n"
"border-image: url(:/Resources/close.png);\n"
"}"));

        horizontalLayout_2->addWidget(closeBtn);


        verticalLayout->addWidget(titleWidget);

        textlab = new QLabel(TwoButtonDialog);
        textlab->setObjectName(QStringLiteral("textlab"));
        textlab->setStyleSheet(QLatin1String("QLabel#textlab\n"
"{		\n"
"	background-color: rgb(255, 255, 255);\n"
"	width: 228px;\n"
"	height: 23px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 24px;\n"
"	line-height: 20px;\n"
"	color: #333333;\n"
"}"));
        textlab->setScaledContents(true);
        textlab->setAlignment(Qt::AlignCenter);
        textlab->setWordWrap(true);

        verticalLayout->addWidget(textlab);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(40);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelBtn = new QPushButton(TwoButtonDialog);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cancelBtn->sizePolicy().hasHeightForWidth());
        cancelBtn->setSizePolicy(sizePolicy1);
        cancelBtn->setMinimumSize(QSize(150, 40));
        cancelBtn->setStyleSheet(QLatin1String("QPushButton#cancelBtn\n"
"{\n"
"	background-color: #f4b452;\n"
"	border-radius: 4px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #ffffff;\n"
"}"));

        horizontalLayout->addWidget(cancelBtn);

        okBtn = new QPushButton(TwoButtonDialog);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        sizePolicy1.setHeightForWidth(okBtn->sizePolicy().hasHeightForWidth());
        okBtn->setSizePolicy(sizePolicy1);
        okBtn->setMinimumSize(QSize(150, 40));
        okBtn->setStyleSheet(QLatin1String("QPushButton#okBtn\n"
"{\n"
"	background-color: #6489d9;\n"
"	border-radius: 4px;\n"
"	width: 33px;\n"
"	height: 15px;\n"
"	font-family: MicrosoftYaHei;\n"
"	font-size: 16px;\n"
"	line-height: 23.8px;\n"
"	color: #ffffff;\n"
"}"));

        horizontalLayout->addWidget(okBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 1);

        retranslateUi(TwoButtonDialog);
        QObject::connect(okBtn, SIGNAL(clicked()), TwoButtonDialog, SLOT(accept()));
        QObject::connect(cancelBtn, SIGNAL(clicked()), TwoButtonDialog, SLOT(reject()));
        QObject::connect(closeBtn, SIGNAL(clicked()), cancelBtn, SLOT(click()));

        QMetaObject::connectSlotsByName(TwoButtonDialog);
    } // setupUi

    void retranslateUi(QDialog *TwoButtonDialog)
    {
        TwoButtonDialog->setWindowTitle(QApplication::translate("TwoButtonDialog", "TwoButtonDialog", nullptr));
        titlelab->setText(QApplication::translate("TwoButtonDialog", "\346\240\207\351\242\230", nullptr));
        closeBtn->setText(QString());
        textlab->setText(QApplication::translate("TwoButtonDialog", "\345\206\205\345\256\271", nullptr));
        cancelBtn->setText(QApplication::translate("TwoButtonDialog", "\345\217\226\346\266\210", nullptr));
        okBtn->setText(QApplication::translate("TwoButtonDialog", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TwoButtonDialog: public Ui_TwoButtonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWOBUTTONDIALOG_H

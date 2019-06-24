/********************************************************************************
** Form generated from reading UI file 'EloamToImage.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELOAMTOIMAGE_H
#define UI_ELOAMTOIMAGE_H

#include <ActiveQt/QAxWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EloamToImageClass
{
public:
    QHBoxLayout *horizontalLayout;
    QAxWidget *axWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *EloamToImageClass)
    {
        if (EloamToImageClass->objectName().isEmpty())
            EloamToImageClass->setObjectName(QStringLiteral("EloamToImageClass"));
        EloamToImageClass->resize(917, 708);
        horizontalLayout = new QHBoxLayout(EloamToImageClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        axWidget = new QAxWidget(EloamToImageClass);
        axWidget->setControl(QStringLiteral("{26ba9e7f-78e9-4fb8-a05c-a4185d80d759}"));
        axWidget->setObjectName(QStringLiteral("axWidget"));
        axWidget->setProperty("styleSheet", QVariant(QStringLiteral("")));
        axWidget->setProperty("enabled", QVariant(true));

        horizontalLayout->addWidget(axWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(EloamToImageClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(EloamToImageClass);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(pushButton_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 9);
        horizontalLayout->setStretch(1, 1);

        retranslateUi(EloamToImageClass);

        QMetaObject::connectSlotsByName(EloamToImageClass);
    } // setupUi

    void retranslateUi(QWidget *EloamToImageClass)
    {
        EloamToImageClass->setWindowTitle(QApplication::translate("EloamToImageClass", "EloamToImage", nullptr));
        pushButton->setText(QApplication::translate("EloamToImageClass", "\346\211\223\345\274\200", nullptr));
        pushButton_2->setText(QApplication::translate("EloamToImageClass", "\346\213\215\347\205\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EloamToImageClass: public Ui_EloamToImageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELOAMTOIMAGE_H

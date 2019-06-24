/********************************************************************************
** Form generated from reading UI file 'ExpertsGui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPERTSGUI_H
#define UI_EXPERTSGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include "LeftInfo/LeftExpandWidget.h"
#include "LeftInfo/LeftShutupWidget.h"
#include "MainWindow.h"

QT_BEGIN_NAMESPACE

class Ui_ExpertsGuiClass
{
public:
    QHBoxLayout *horizontalLayout;
    LeftShutupWidget *shutupWidget;
    LeftExpandWidget *expandWidget;
    MainWindow *mainWindow;

    void setupUi(QWidget *ExpertsGuiClass)
    {
        if (ExpertsGuiClass->objectName().isEmpty())
            ExpertsGuiClass->setObjectName(QStringLiteral("ExpertsGuiClass"));
        ExpertsGuiClass->resize(1920, 1040);
        ExpertsGuiClass->setMinimumSize(QSize(1920, 1040));
        horizontalLayout = new QHBoxLayout(ExpertsGuiClass);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        shutupWidget = new LeftShutupWidget(ExpertsGuiClass);
        shutupWidget->setObjectName(QStringLiteral("shutupWidget"));
        shutupWidget->setMinimumSize(QSize(80, 0));

        horizontalLayout->addWidget(shutupWidget);

        expandWidget = new LeftExpandWidget(ExpertsGuiClass);
        expandWidget->setObjectName(QStringLiteral("expandWidget"));
        expandWidget->setMinimumSize(QSize(570, 0));

        horizontalLayout->addWidget(expandWidget);

        mainWindow = new MainWindow(ExpertsGuiClass);
        mainWindow->setObjectName(QStringLiteral("mainWindow"));
        mainWindow->setMinimumSize(QSize(1350, 0));

        horizontalLayout->addWidget(mainWindow);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 5);

        retranslateUi(ExpertsGuiClass);

        QMetaObject::connectSlotsByName(ExpertsGuiClass);
    } // setupUi

    void retranslateUi(QWidget *ExpertsGuiClass)
    {
        ExpertsGuiClass->setWindowTitle(QApplication::translate("ExpertsGuiClass", "ExpertsGui", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpertsGuiClass: public Ui_ExpertsGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPERTSGUI_H

/********************************************************************************
** Form generated from reading UI file 'AssistGui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSISTGUI_H
#define UI_ASSISTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include "LeftInfo/LeftExpandWidget.h"
#include "LeftInfo/LeftShutupWidget.h"
#include "MainWindow.h"

QT_BEGIN_NAMESPACE

class Ui_AssistGui
{
public:
    QHBoxLayout *horizontalLayout;
    LeftShutupWidget *shutupWidget;
    LeftExpandWidget *expandWidget;
    MainWindow *mainWindow;

    void setupUi(QWidget *AssistGui)
    {
        if (AssistGui->objectName().isEmpty())
            AssistGui->setObjectName(QStringLiteral("AssistGui"));
        AssistGui->resize(1920, 1040);
        AssistGui->setMinimumSize(QSize(1920, 1040));
        AssistGui->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(AssistGui);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        shutupWidget = new LeftShutupWidget(AssistGui);
        shutupWidget->setObjectName(QStringLiteral("shutupWidget"));
        shutupWidget->setMinimumSize(QSize(80, 0));

        horizontalLayout->addWidget(shutupWidget);

        expandWidget = new LeftExpandWidget(AssistGui);
        expandWidget->setObjectName(QStringLiteral("expandWidget"));
        expandWidget->setMinimumSize(QSize(570, 0));

        horizontalLayout->addWidget(expandWidget);

        mainWindow = new MainWindow(AssistGui);
        mainWindow->setObjectName(QStringLiteral("mainWindow"));
        mainWindow->setMinimumSize(QSize(1350, 0));

        horizontalLayout->addWidget(mainWindow);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 5);

        retranslateUi(AssistGui);

        QMetaObject::connectSlotsByName(AssistGui);
    } // setupUi

    void retranslateUi(QWidget *AssistGui)
    {
        AssistGui->setWindowTitle(QApplication::translate("AssistGui", "MedicalGui", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AssistGui: public Ui_AssistGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSISTGUI_H

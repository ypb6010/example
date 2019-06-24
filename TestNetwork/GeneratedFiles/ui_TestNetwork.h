/********************************************************************************
** Form generated from reading UI file 'TestNetwork.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTNETWORK_H
#define UI_TESTNETWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestNetworkClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *editData;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *dataSize;
    QPushButton *btnbuild;
    QPushButton *btnSend;

    void setupUi(QMainWindow *TestNetworkClass)
    {
        if (TestNetworkClass->objectName().isEmpty())
            TestNetworkClass->setObjectName(QStringLiteral("TestNetworkClass"));
        TestNetworkClass->resize(230, 139);
        centralWidget = new QWidget(TestNetworkClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        editData = new QLineEdit(centralWidget);
        editData->setObjectName(QStringLiteral("editData"));

        horizontalLayout->addWidget(editData);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        dataSize = new QSpinBox(centralWidget);
        dataSize->setObjectName(QStringLiteral("dataSize"));
        dataSize->setMaximum(1024);

        horizontalLayout_2->addWidget(dataSize);


        verticalLayout->addLayout(horizontalLayout_2);

        btnbuild = new QPushButton(centralWidget);
        btnbuild->setObjectName(QStringLiteral("btnbuild"));

        verticalLayout->addWidget(btnbuild);

        btnSend = new QPushButton(centralWidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));

        verticalLayout->addWidget(btnSend);

        TestNetworkClass->setCentralWidget(centralWidget);

        retranslateUi(TestNetworkClass);

        QMetaObject::connectSlotsByName(TestNetworkClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestNetworkClass)
    {
        TestNetworkClass->setWindowTitle(QApplication::translate("TestNetworkClass", "TestNetwork", nullptr));
        label->setText(QApplication::translate("TestNetworkClass", "\345\206\205\345\256\271\357\274\232", nullptr));
        label_2->setText(QApplication::translate("TestNetworkClass", "\345\244\247\345\260\217\357\274\232", nullptr));
        btnbuild->setText(QApplication::translate("TestNetworkClass", "\347\224\237\346\210\220\346\225\260\346\215\256", nullptr));
        btnSend->setText(QApplication::translate("TestNetworkClass", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestNetworkClass: public Ui_TestNetworkClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTNETWORK_H

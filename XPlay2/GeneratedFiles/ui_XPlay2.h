/********************************************************************************
** Form generated from reading UI file 'XPlay2.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XPLAY2_H
#define UI_XPLAY2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "XVideoWidget.h"

QT_BEGIN_NAMESPACE

class Ui_XPlay2Class
{
public:
    QVBoxLayout *verticalLayout;
    XVideoWidget *openGLWidget;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *XPlay2Class)
    {
        if (XPlay2Class->objectName().isEmpty())
            XPlay2Class->setObjectName(QStringLiteral("XPlay2Class"));
        XPlay2Class->resize(800, 600);
        XPlay2Class->setMinimumSize(QSize(800, 600));
        XPlay2Class->setMaximumSize(QSize(800, 600));
        verticalLayout = new QVBoxLayout(XPlay2Class);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        openGLWidget = new XVideoWidget(XPlay2Class);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));

        verticalLayout->addWidget(openGLWidget);

        horizontalSlider = new QSlider(XPlay2Class);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(999);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(XPlay2Class);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(XPlay2Class);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 50);
        verticalLayout->setStretch(2, 1);

        retranslateUi(XPlay2Class);

        QMetaObject::connectSlotsByName(XPlay2Class);
    } // setupUi

    void retranslateUi(QWidget *XPlay2Class)
    {
        XPlay2Class->setWindowTitle(QApplication::translate("XPlay2Class", "XPlay2", nullptr));
        pushButton->setText(QApplication::translate("XPlay2Class", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        pushButton_2->setText(QApplication::translate("XPlay2Class", "\346\232\202\345\201\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XPlay2Class: public Ui_XPlay2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XPLAY2_H

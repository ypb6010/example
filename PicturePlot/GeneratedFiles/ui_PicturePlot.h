/********************************************************************************
** Form generated from reading UI file 'PicturePlot.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTUREPLOT_H
#define UI_PICTUREPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_PicturePlotClass
{
public:

    void setupUi(QDialog *PicturePlotClass)
    {
        if (PicturePlotClass->objectName().isEmpty())
            PicturePlotClass->setObjectName(QStringLiteral("PicturePlotClass"));
        PicturePlotClass->resize(600, 400);

        retranslateUi(PicturePlotClass);

        QMetaObject::connectSlotsByName(PicturePlotClass);
    } // setupUi

    void retranslateUi(QDialog *PicturePlotClass)
    {
        PicturePlotClass->setWindowTitle(QApplication::translate("PicturePlotClass", "PicturePlot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PicturePlotClass: public Ui_PicturePlotClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTUREPLOT_H

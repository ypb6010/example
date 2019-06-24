#pragma once
#define String2QString(str) \
		QString::fromLocal8Bit(str.data())
#include "medicalwidget_global.h"


#include <QApplication>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QIcon>
#include <QPushButton>
#include <QRect>
#include <iostream>
#include <boost/format.hpp>
#include <QList>
#include <QToolTip>
#include "../MedicalWidget/TableModel.h"


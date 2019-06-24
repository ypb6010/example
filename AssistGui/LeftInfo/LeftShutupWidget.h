#pragma once

#include <QWidget>
#include "ui_LeftShutupWidget.h"

class LeftShutupWidget : public QWidget
{
	Q_OBJECT

public:
	LeftShutupWidget(QWidget *parent = Q_NULLPTR);
	~LeftShutupWidget();
///作为提升类，所有组件应当放开
public:
	Ui::LeftShutupWidget ui;
};

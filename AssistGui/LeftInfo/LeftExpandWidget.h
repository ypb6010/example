#pragma once

#include <QWidget>
#include "ui_LeftExpandWidget.h"

class LeftExpandWidget : public QWidget
{
	Q_OBJECT

public:
	LeftExpandWidget(QWidget *parent = Q_NULLPTR);
	~LeftExpandWidget();

///作为提升类，将UI所有组件放开
public:
	Ui::LeftExpandWidget ui;
private:
	void chanageTabWidget(QLabel* lab);
};

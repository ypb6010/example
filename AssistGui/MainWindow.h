#pragma once

#include <QWidget>
#include "ui_MainWindow.h"

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();
///作为提升类，所有的ui组件应当放开给父窗口
public:
	Ui::MainWindow ui;
};

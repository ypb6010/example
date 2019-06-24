#pragma once

#include <QWidget>

class LeftExpandLine : public QWidget
{
	Q_OBJECT

public:
	LeftExpandLine(QWidget *parent);
	~LeftExpandLine();
private:
	virtual void paintEvent(QPaintEvent *event);
};

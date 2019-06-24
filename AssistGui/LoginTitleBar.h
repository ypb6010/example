#pragma once

#include <QFrame>
#include "ui_TitleBar.h"

class LoginTitleBar : public QFrame
{
	Q_OBJECT

public:
	LoginTitleBar(QWidget *parent = Q_NULLPTR);
	~LoginTitleBar();

protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);

	virtual void onMinButton();
	virtual void onColseButton();
private:
	Ui::TitleBar ui;
	QPoint m_starPt;
	bool m_bPress;
};

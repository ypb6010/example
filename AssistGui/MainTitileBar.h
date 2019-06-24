#pragma once

#include <QFrame>

class MainTitileBar : public QFrame
{
	Q_OBJECT

public:
	MainTitileBar(QWidget *parent);
	~MainTitileBar();
protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);

	QPoint m_starPt;
	bool m_bPress;
};

#pragma once

#include <QFrame>

class MEDICALWIDGET_EXPORT TitleBar : public QFrame
{
	Q_OBJECT

public:
	TitleBar(QWidget *parent);
	~TitleBar();
protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);

	QPoint m_starPt;
	bool m_bPress;
};

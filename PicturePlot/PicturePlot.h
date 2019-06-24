#pragma once

#include <QtWidgets/QDialog>
#include "ui_PicturePlot.h"

class PicturePlot : public QDialog
{
	Q_OBJECT

public:
	PicturePlot(QWidget *parent = Q_NULLPTR);
protected:
	virtual void paintEvent(QPaintEvent *event);

	virtual void mousePressEvent(QMouseEvent *event) override;

	virtual void mouseMoveEvent(QMouseEvent* event) override;

	virtual void mouseReleaseEvent(QMouseEvent *event) override;
private:
	Ui::PicturePlotClass ui;
	bool	m_isButtonPressed;
	QPoint m_beginPt;
	QPixmap m_source;
	QPixmap m_plot;
	QPixmap m_cach;
};

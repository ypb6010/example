#include "stable.h"
#include "PicturePlot.h"

PicturePlot::PicturePlot(QWidget *parent)
	: QDialog(parent)
	, m_source("882.jpg")
	, m_isButtonPressed(false)
{
	m_plot = m_source;
	ui.setupUi(this);

}

void PicturePlot::paintEvent(QPaintEvent *event)
{
	QStyleOption opt;
	opt.initFrom(this);
	QStylePainter painter(this);
	painter.drawPrimitive(QStyle::PE_Widget, opt);
	QRect blound = rect();
	if (!m_isButtonPressed)
		painter.drawPixmap(blound, m_plot);
	else
		painter.drawPixmap(blound, m_cach);

}

void PicturePlot::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_isButtonPressed = true;
		m_beginPt = event->pos();
		//求出图片大小，到窗口大小的缩放变换矩阵
		QTransform mt = QTransform::fromScale((qreal)width() / (qreal)m_plot.width(), (qreal)height() / (qreal)m_plot.height());
		//缩放到视口的大小
		m_plot = m_plot.transformed(mt);
		m_cach = m_plot;
		event->accept();
	}
	else
	{
		event->ignore();
	}
}

void PicturePlot::mouseMoveEvent(QMouseEvent* event)
{
	if (m_isButtonPressed)
	{
#if 1		//自由标绘
		QPainter painter(&m_cach);
		QPoint pt = event->pos();
		painter.drawLine(m_beginPt, pt);
		m_beginPt = pt;
#endif

#if 0		//矩形标绘
		QRect blound(m_beginPt, event->pos());
		QPixmap pixmap = m_plot;
		QPainter painter(&pixmap);
		painter.drawRect(blound);

		m_cach = pixmap;
#endif
#if 0		//圆形标绘
		QPixmap pixmap = m_plot;
		QPainter painter(&pixmap);
		QRect blound(m_beginPt, event->pos());
		painter.drawEllipse(blound);
		m_cach = pixmap;
#endif
#if 0		//箭头标绘
		QPoint pt = event->pos();
		float lenght = 10.0;
		float angle = 0.5;
		QPoint first(pt.x() - lenght * cos(atan2((pt.y() - m_beginPt.y()), (pt.x() - m_beginPt.x())) - angle), \
			pt.y() - lenght * sin(atan2((pt.y() - m_beginPt.y()), (pt.x() - m_beginPt.x())) - angle));

		QPoint secend(pt.x() - lenght * sin(atan2((pt.x() - m_beginPt.x()), (pt.y()- m_beginPt.y())) - angle), \
			pt.y() - lenght * cos(atan2((pt.x() - m_beginPt.x()), (pt.y() - m_beginPt.y())) - angle));
		QPixmap pixmap = m_plot;
		QPainter painter(&pixmap);
		QRect blound(m_beginPt, event->pos());
		painter.drawLine(pt, first);
		painter.drawLine(pt, secend);
		painter.drawLine(m_beginPt, pt);
		m_cach = pixmap;
#endif
		update();
	}
}

void PicturePlot::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_isButtonPressed = false;
		m_plot = m_cach;
		event->accept();
	}
	else
	{
		event->ignore();
	}
}

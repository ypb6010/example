#include "stable.h"
#include "LeftExpandLine.h"

LeftExpandLine::LeftExpandLine(QWidget *parent)
	: QWidget(parent)
{
}

LeftExpandLine::~LeftExpandLine()
{
}

void LeftExpandLine::paintEvent(QPaintEvent *event)
{
	QStylePainter painter(this);
	int nWidth = width();
	int nheight = height();
	QStyleOption opt;
	opt.rect = rect();
	opt.init(this);
	painter.drawPrimitive(QStyle::PE_Widget, opt);
	QPen pen(QBrush(0xe1e2e6), 1);
	painter.setPen(pen);	
	painter.drawLine(20, 480, nWidth - 20, 480);
}

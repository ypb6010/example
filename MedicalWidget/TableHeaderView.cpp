#include "stable.h"
#include "TableHeaderView.h"


void TableHeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
	painter->save();
	QHeaderView::paintSection(painter, rect, logicalIndex);
	painter->restore();
	painter->fillRect(rect, qRgb(214, 219, 231));
	auto value = model()->headerData(logicalIndex, Qt::Horizontal, Qt::DisplayRole);
	QFont font;
	font.setFamily("MicrosoftYaHei");
	font.setPixelSize(16);
	QPen pen;
	pen.setColor(qRgb(51, 51, 51));
	painter->setFont(font);
	painter->setPen(pen);
	painter->drawText(rect, Qt::AlignCenter, value.toString());
	painter->setPen(qRgb(233, 234, 239));
	painter->drawRect(rect);
}

TableHeaderView::TableHeaderView(Qt::Orientation orientation, QWidget *parent)
	: QHeaderView(orientation, parent)
{
}

TableHeaderView* TableHeaderView::clone()
{
	auto view = new TableHeaderView(orientation());
	view->setMinimumHeight(this->minimumHeight());
	view->setSectionResizeMode(QHeaderView::Stretch);
	return view;
}

TableHeaderView::~TableHeaderView()
{
}

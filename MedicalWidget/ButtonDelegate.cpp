#include "stable.h"
#include "ButtonDelegate.h"


ButtonDelegate::ButtonDelegate(QObject *parent)
	: QStyledItemDelegate(parent)
{
}

ButtonDelegate::~ButtonDelegate()
{
	qDeleteAll(m_btns);
}
// user	  是否使用按钮
// user+1 按钮是否可用
// user+2 按钮图片
void ButtonDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	if (!index.data(Qt::UserRole).toBool())
	{
		return __super::paint(painter, option, index);
	}
	QStyleOptionButton* button = m_btns.value(index);
	if (!button) 
	{
		button =  new QStyleOptionButton();
	}
	button->text = index.data(Qt::DisplayRole).toString();
	button->state |= QStyle::State_Enabled;
	(const_cast<ButtonDelegate *>(this))->m_btns[index] = button;
	button->rect = option.rect.adjusted(4, 4, -4, -4);

	painter->save();
	if (option.state & QStyle::State_Selected)
	{
		painter->fillRect(option.rect, qRgb(230,240,255));
	}
	painter->restore();
	QPixmap btnPic = stringToPixmap(index.data(Qt::UserRole + 2).toString());
	QRect picRect = btnPic.rect();
	QPoint pt = button->rect.center();

	if (picRect.width() > button->rect.width()|| picRect.height() > button->rect.height())
	{
		painter->drawPixmap(button->rect, btnPic);
	}
	else
	{
		button->rect.setLeft(pt.x() - picRect.width() / 2);
		button->rect.setRight(pt.x() + picRect.width() / 2);
		button->rect.setTop(pt.y() - picRect.height() / 2);
		button->rect.setBottom(pt.y() + picRect.height() / 2);
		painter->drawPixmap(button->rect, btnPic);
	}

	painter->setPen(QPen(qRgb(255, 255, 255)));

	QFont font;
	font.setFamily("font-family: MicrosoftYaHei");
	font.setPixelSize(16);
	painter->setFont(font);
	painter->drawText(button->rect, Qt::AlignCenter, button->text);
}

bool ButtonDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
	if (!index.data(Qt::UserRole).toBool() || !index.data(Qt::UserRole+1).toBool())
	{
		return __super::editorEvent(event, model, option, index);		
	}
	auto btn = m_btns.value(index);
	auto rect = btn ? btn->rect : option.rect;
	if (event->type() == QEvent::MouseButtonPress) 	
	{
		QMouseEvent* me = dynamic_cast<QMouseEvent*>(event);
		if (!me) return __super::editorEvent(event, model, option, index);
		if (rect.contains(me->x(), me->y()) && m_btns.contains(index))
		{
			m_btns.value(index)->state |= QStyle::State_Sunken;
		}
	}
	if (event->type() == QEvent::MouseButtonRelease) 
	{
		QMouseEvent* me = dynamic_cast<QMouseEvent*>(event);
		if (!me) return __super::editorEvent(event, model, option, index);
		if (rect.contains(me->x(), me->y()) && m_btns.contains(index))
		{
			m_btns.value(index)->state &= (~QStyle::State_Sunken);
			emit clicked(index);
		}
	}
	return __super::editorEvent(event, model, option, index);
}

QPixmap ButtonDelegate::stringToPixmap(QString const& picStr) const
{
	if (picStr == "lookup")
	{
		return QPixmap(":/Resources/lookup.png");
	}
	else if (picStr == "del")
	{
		return QPixmap(":/Resources/del.png");
	}
	else if (picStr == "normal")
	{
		return QPixmap(":/Resources/button.png");
	}
	else if (picStr == "disable")
	{
		return QPixmap(":/Resources/button_disabled.png");
	}
	return QPixmap();
}


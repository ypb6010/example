#include "stable.h"
#include "ButtonBoxDelegate.h"

ButtonBoxDelegate::ButtonBoxDelegate(QObject *parent)
	: QStyledItemDelegate(parent)
{
}

ButtonBoxDelegate::~ButtonBoxDelegate()
{
}


void ButtonBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	auto btns = m_btsMap.find(index);
	if (btns == m_btsMap.end())
	{
		Btns_type buttons({ new QStyleOptionButton, new QStyleOptionButton });
		const_cast<ButtonBoxDelegate*>(this)->m_btsMap[index] = buttons;
	}

	QStyleOptionButton* patOption = m_btsMap[index][0];
	QStyleOptionButton* diagnoseOption = m_btsMap[index][1];

	QRect boundRect = option.rect.adjusted(21, 4, -21, -4);
	patOption->rect.setRect(boundRect.x(), boundRect.y(), boundRect.width() / 2, boundRect.height());
	diagnoseOption->rect.setRect(boundRect.center().x() + 4, boundRect.y(), boundRect.width() / 2, boundRect.height());
	patOption->state |= QStyle::State_Enabled;
	diagnoseOption->state |= QStyle::State_Enabled;
	QStringList strText = index.data(Qt::DisplayRole).toString().split(";");
	patOption->text = strText[0];
	diagnoseOption->text = strText[1];
	if (patOption->rect.contains(m_mousePoint))
	{
		if (m_nType == 0)
		{
			patOption->state |= QStyle::State_MouseOver;
		}
		else if (m_nType == 1)
		{
			patOption->state |= QStyle::State_Sunken;
		}
	}
	if (diagnoseOption->rect.contains(m_mousePoint))
	{
		if (m_nType == 0)
		{
			diagnoseOption->state |= QStyle::State_MouseOver;
		}
		else if (m_nType == 1)
		{
			diagnoseOption->state |= QStyle::State_MouseOver;
		}
	}
	QPixmap pics[2];
	QStringList strPics = index.data(Qt::UserRole).toString().split(";");
	pics[0] = const_cast<ButtonBoxDelegate*>(this)->stringToPixmap(strPics[0]);
	pics[1] = const_cast<ButtonBoxDelegate*>(this)->stringToPixmap(strPics[1]);

	painter->save();
	if (option.state & QStyle::State_Selected)
	{
		painter->fillRect(option.rect, qRgb(230, 240, 255));
	}
	painter->restore();
	QFont font("MicrosoftYaHei", 12);
	painter->setFont(font);
	painter->setPen(0xfefefe);
	painter->drawPixmap(patOption->rect, pics[0]);
	painter->drawPixmap(diagnoseOption->rect, pics[1]);
	painter->drawText(patOption->rect, Qt::AlignCenter, patOption->text);
	painter->drawText(diagnoseOption->rect, Qt::AlignCenter, diagnoseOption->text);
}

bool ButtonBoxDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
	m_nType = -1;
	QMouseEvent *pEvent = static_cast<QMouseEvent *> (event);
	m_mousePoint = pEvent->pos();

	// 还原鼠标样式
	QApplication::restoreOverrideCursor();

	for (int i = 0;i < m_btsMap.value(index).size();i++)
	{
		auto btn = m_btsMap.value(index)[i];
		if (!btn->rect.contains(m_mousePoint))
			continue;
		switch (event->type())
		{
			// 鼠标滑过
		case QEvent::MouseMove:
		{
			// 设置鼠标样式为手型
			QApplication::setOverrideCursor(Qt::PointingHandCursor);
			m_nType = 0;
	
			break;
		}
		// 鼠标按下
		case QEvent::MouseButtonPress:
		{
			m_nType = 1;
			break;
		}
		// 鼠标释放
		case QEvent::MouseButtonRelease:
		{
			///在此发出按下的信号
			std::cout << boost::format("第%d行%d列的第%d按钮被点击\n") % index.row() % index.column() % i ;
			emit clicked(index, i);
			break;
		}
		default:
			break;
		}
	}
	return __super::editorEvent(event, model, option, index);
}

QPixmap ButtonBoxDelegate::stringToPixmap(QString const& str)
{
	if (str == "blue")
	{
		return QPixmap(":/Resources/button.png");
	}
	else if (str == "yellow")
	{
		return QPixmap(":/Resources/yellow_normal.png");
	}
	return QPixmap();
}

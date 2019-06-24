#include "stable.h"
#include "TitleBar.h"
#include <QMouseEvent>


TitleBar::TitleBar(QWidget *parent)
	: QFrame(parent)
{
}

TitleBar::~TitleBar()
{
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		if (QApplication::activeWindow()->isMaximized())
		{
			event->ignore();
			return;
		}
		m_bPress = true;
		m_starPt = event->pos();
		event->accept();
	}
	else
	{
		event->ignore();
	}

}

void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bPress = false;
		event->accept();
	}
	else
	{
		event->ignore();
	}
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
	if (m_bPress)
	{
		QPoint movePt = event->globalPos() - m_starPt;
		window()->move(movePt);
		event->accept();
	}
	else
	{
		event->ignore();
	}
}

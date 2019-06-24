#include "stable.h"
#include "MainTitileBar.h"
#include <QMouseEvent>


MainTitileBar::MainTitileBar(QWidget *parent)
	: QFrame(parent)
{
}

MainTitileBar::~MainTitileBar()
{
}

void MainTitileBar::mousePressEvent(QMouseEvent *event)
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

void MainTitileBar::mouseReleaseEvent(QMouseEvent *event)
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

void MainTitileBar::mouseMoveEvent(QMouseEvent *event)
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

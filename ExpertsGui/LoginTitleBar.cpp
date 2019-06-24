#include "stable.h"
#include "LoginTitleBar.h"
#include <qt_windows.h>
#include <QMoveEvent>
LoginTitleBar::LoginTitleBar(QWidget *parent)
	: QFrame(parent)
	, m_bPress(false)
{
	ui.setupUi(this);
	ui.minButton->setToolTip(QStringLiteral("最小化"));
	ui.closeButton->setToolTip(QStringLiteral("关闭"));

	connect(ui.minButton, &QAbstractButton::clicked, [this](){
		onMinButton();
	});
	connect(ui.closeButton, &QAbstractButton::clicked, [this](){
		onColseButton();
	});

}

LoginTitleBar::~LoginTitleBar()
{
}

void LoginTitleBar::mousePressEvent(QMouseEvent *event)
{
#if 0
	if (ReleaseCapture())
	{
		QWidget* pWinodw = window();
		if (pWinodw->isTopLevel())
		{
			SendMessage((HWND)pWinodw->winId(), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
		}
	}
	event->ignore();
#endif
	if (event->button() == Qt::LeftButton)
	{
		m_bPress = true;
		m_starPt = event->pos(); 
		event->accept();
	}
	else
	{
		event->ignore();
	}
}

void LoginTitleBar::mouseReleaseEvent(QMouseEvent *event)
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

void LoginTitleBar::mouseMoveEvent(QMouseEvent *event)
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


void LoginTitleBar::onMinButton()
{
	QWidget* pWindow = this->window();
	pWindow->showMinimized();
}


void LoginTitleBar::onColseButton()
{
	QDialog* pWindow = dynamic_cast<QDialog*>(this->window());
	pWindow->reject();
}

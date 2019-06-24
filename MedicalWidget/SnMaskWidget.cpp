#include "stable.h"
#include "SnMaskWidget.h"

#include <QApplication>
#include <QPainter>

SnMaskWidget * SnMaskWidget::__instance = nullptr;

SnMaskWidget::SnMaskWidget(QWidget *parent /* = nullptr */)
	: QWidget(parent)
	, mpMainWidget(NULL)
{
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	//this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

	/// 绑定全局事件，过滤弹窗进行处理
	qApp->installEventFilter(this);

	__instance = this;
}

SnMaskWidget::~SnMaskWidget()
{

}

SnMaskWidget * SnMaskWidget::getInstance()
{
	return __instance;
}

void SnMaskWidget::setMainWidget(QWidget *pWidget)
{
	mpMainWidget = pWidget;
}

void SnMaskWidget::setDialogNames(const QStringList &dialogNames)
{
	mDialogNames = dialogNames;
}

void SnMaskWidget::addDialogName(const QString &sName)
{
	mDialogNames.append(sName);
}

void SnMaskWidget::removeDialogName(const QString &sName)
{
	mDialogNames.removeOne(sName);
}

void SnMaskWidget::setBgColor(const QColor &bgColor)
{
// 	QPalette palette = this->palette();
// 	palette.setBrush(QPalette::Background, bgColor);
// 	this->setPalette(palette);
}

void SnMaskWidget::setOpacity(double opacticy)
{
//	this->setWindowOpacity(opacticy);
}

void SnMaskWidget::showEvent(QShowEvent *event)
{
	if (mpMainWidget != 0) 
	{
		this->setGeometry(mpMainWidget->geometry());
	}
}

bool SnMaskWidget::eventFilter(QObject *object, QEvent *event)
{
	if (event->type() == QEvent::Show) 
	{
		if (mDialogNames.contains(object->objectName())) 
		{
			this->show();
			QWidget *pWidget = qobject_cast<QWidget *>(object);
			if (nullptr != pWidget)
			{
				pWidget->raise();
			}
		}
	}
	else if (event->type() == QEvent::Hide) 
	{
		if (mDialogNames.contains(object->objectName())) 
		{
			this->hide();
		}
	}
	return QWidget::eventFilter(object, event);
}

void SnMaskWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.fillRect(rect(), QColor(100, 100, 100, 127));
}


#pragma once

/************************************************************************
* 窗体遮罩                                                                     
************************************************************************/

#include <QWidget>

class MEDICALWIDGET_EXPORT SnMaskWidget : public QWidget
{
	//SINGLETON(SnMaskWidget)
public:
	SnMaskWidget(QWidget *parent = nullptr);
	~SnMaskWidget();

	static SnMaskWidget *getInstance();

public Q_SLOTS:
	void setMainWidget(QWidget *pWidget);
	void setDialogNames(const QStringList &dialogNames);
	void addDialogName(const QString &sName);
	void removeDialogName(const QString &sName);
	void setBgColor(const QColor &bgColor);
	void setOpacity(double opticy);

protected:
	virtual void showEvent(QShowEvent *event) override;
	virtual bool eventFilter(QObject *object, QEvent *event) override;
	virtual void paintEvent(QPaintEvent *event) override;

private:
	QWidget *mpMainWidget;		///< 需要遮罩的主窗体
	QStringList mDialogNames;	///< 可能弹窗的对象名称集合链表（窗体）
	
	static SnMaskWidget *__instance;
};


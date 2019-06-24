#pragma once

#include <QtWidgets/QWidget>
#include "ui_XPlay2.h"

class XDemuxThread;
extern XDemuxThread* pWorkManager;

class XPlay2 : public QWidget
{
	Q_OBJECT

public:
	XPlay2(QWidget *parent = Q_NULLPTR);
	~XPlay2();
	IVideoCall* getIVedioCall() const;
protected:
	

	virtual void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
	void openFile();
	void on_timer();
private:
	QTimer*			m_ptimer;
	Ui::XPlay2Class ui;
};

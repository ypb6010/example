#pragma once

#include <QtWidgets/QWidget>
#include "ui_EloamToImage.h"


namespace eloamComLib
{
	class IEloamGlobal;
	class IEloamDevice;
	class IEloamVideo;
	class IEloamView;
};

class EloamToImage : public QWidget
{
	Q_OBJECT

public:
	EloamToImage(QWidget *parent = Q_NULLPTR);
	~EloamToImage();
private:
	void on_open();
	void on_capture();
private:
	Ui::EloamToImageClass ui;
	eloamComLib::IEloamDevice*		m_pDevice;
	eloamComLib::IEloamGlobal*		m_pEloamGlobal;
	eloamComLib::IEloamVideo*		m_pVedio;
	eloamComLib::IEloamView*		m_pView;
};

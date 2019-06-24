#include <iostream>
#include "EloamToImage.h"
#include "eloamcomlib.h"
#include <QUuid>
#include <QMetaMethod>
#include <oaidl.h>

using namespace eloamComLib;

EloamToImage::EloamToImage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_pEloamGlobal = new IEloamGlobal;
	m_pEloamGlobal->setControl("EloamGlobal.Instance");
	if (!m_pEloamGlobal->InitDevs())
	{
		std::cout << "初始化高拍仪失败" << std::endl;
	}
	connect(ui.pushButton, &QPushButton::clicked, this, &EloamToImage::on_open);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &EloamToImage::on_capture);
}

EloamToImage::~EloamToImage()
{
	delete m_pVedio;	
	m_pEloamGlobal->DeinitDevs();
	delete m_pDevice;
	delete m_pEloamGlobal;
}

void EloamToImage::on_open()
{
	m_pDevice = reinterpret_cast<decltype(m_pDevice)>(m_pEloamGlobal->querySubObject("CreateDevice(int,int)", 1, 0));
	if (m_pDevice->isNull())
	{
		return;
	}
	m_pVedio = reinterpret_cast<decltype(m_pVedio)>(m_pDevice->querySubObject("CreateVideo(int,int)", 0, 2));
	if (!m_pVedio)
	{
		std::cout << "m_pVedio is nullptr! 创建视频设备" << std::endl;
		return;
	}
	m_pView = reinterpret_cast<decltype(m_pView)>(ui.axWidget->querySubObject("GetView()"));
	if (!m_pView)
	{
		std::cout << "m_pView is nullptr! 获取视图接口失败" << std::endl;
		return;
	}
	QColor color = qRgb(255, 255, 255);
	if (!m_pView->dynamicCall("SelectVideo(IDispatch*)", m_pVedio->asVariant()).toBool())
	{
		std::cout << "绑定设备失败" << std::endl;
		return;
	}
	if (!m_pView->dynamicCall("SetText(const QString&,const QColor&)", QStringLiteral("打开视频中，请等待..."), color).toBool())
	{
		std::cout << "设备显示文字失败" << std::endl;
		return;
	}
	ui.pushButton->setEnabled(false);
	ui.pushButton_2->setEnabled(true);
}

void EloamToImage::on_capture()
{
	IEloamImage* pImage = reinterpret_cast<decltype(pImage)>(m_pVedio->querySubObject("CreateImage(int,IDispatch*)", 0, m_pView->asVariant()));
	if (!pImage)
	{
		std::cout << "pImage is nullptr! 图像对象创建失败" << std::endl;	
		return;
	}
	IEloamMemory* pMemory = reinterpret_cast<decltype(pMemory)>(pImage->querySubObject("CreateMemory(int,int)", 13, 0));
	if (!pMemory)
	{
		return;
	}
	pMemory->Save(QStringLiteral("458.png"));

	QByteArray cache = QByteArray::fromBase64(pMemory->GetBase64().toLatin1());
	QPixmap pixmap(cache);
	pixmap.save("159.png"); 

	pMemory->Destroy();
	pImage->Destroy();
	delete pMemory;
	delete pImage;
}

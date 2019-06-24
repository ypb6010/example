#pragma once

#include "assistcore_global.h"
#include "Core.h"

class AssistWindowInterface;

class AssistCore;
/**
 * 类名称：AssistCore
 * 类简介：AssistCore为助诊端的核心模块，主要实现了创建助诊的系统
 * ******  在本模块中添加了GUI的接口，解析完成数据后，直接调用GUI。
 * ******  解析每个数据包的二进制格式，全部在此类中进行实现，所有
 * ******  已经实现好的解析函数，一定要在initOthers中进行绑定，因为
 * ******  解析函数要注册到消息管理器中，initOthers在确保都已经创建
 * ******  完成后，才会调用。
 */
class ASSISTCORE_EXPORT AssistCore :public Core
{
	typedef AssistCore this_type;
public:
	AssistCore();
	virtual ~AssistCore();
	//*********************************************************
	// 函数：   creator
	// 全称：  	AssistCore::creator
	// 说明：	助诊端模块，工厂函数，创建助诊模块
	// 权限：   public static 
	// 返回值： core_ptr					解释：返回一个助诊模块的智能指针
	// 限定词：
	//*********************************************************
	static core_ptr creator();

public:
	virtual void setMainWindow(WindowInterface* pWindow);
	virtual WindowInterface* mainWindow() const override;
public:
	void receipt_heartbeat(std::string const& strMsg, msg_header_t const& head);
protected:
	//*********************************************************
	// 函数：   initOthers
	// 全称：  	AssistCore::initOthers
	// 说明：	所有的绑定操作，在重写此函数后在此进行，可以确保所有已经创建完成
	// 权限：   virtual protected 
	// 返回值： void
	// 限定词：
	//*********************************************************
	virtual void initOthers() override;


	virtual void netAreaConnect(std::string const& strMsg);
	
private:
	AssistWindowInterface* m_pMainWindow;
};





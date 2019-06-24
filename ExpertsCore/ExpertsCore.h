#pragma once

#include "expertscore_global.h"
class ExpertsWindowInterface;

/**
 * 类名称：	ExpertsCore
 * 类简介：	本类是专家客户端配套的核心部件。
 * ******	客户端==>>区域服务器 使用编码器会自动放入编码消息队列，自动有线程负责发送
 * ******	区域服务器==>>客户端 使用子类中的宏REG_EVENT_ARG进行注册为通用或者使用
 * ******	REG_EVENT来满足一些特殊的需求，需要在Core里面执行操作的。这两个宏只负责
 * ******	截取本地序列化队列中（网络序列化后转换为本地序列化）的消息，如果在网络
 * ******	转本地序列化中出现时失败，则注册也不会收到消息，或者收到的消息仍然是错误消息
 */
class EXPERTSCORE_EXPORT ExpertsCore : public Core
{
	typedef ExpertsCore this_type;
public:
	ExpertsCore();
	static core_ptr creator();
public:
	//*********************************************************
	// 函数：   setMainWindow
	// 全称：  	ExpertsCore::setMainWindow
	// 说明：	重写使其设置指向本类中的接口
	// 权限：   virtual public 
	// 返回值： void
	// 限定词：
	// 参数： 	WindowInterface * pWindow				解释：专家的主窗口指针
	//*********************************************************
	virtual void setMainWindow(WindowInterface* pWindow);

	//*********************************************************
	// 函数：   mainWindow
	// 全称：  	ExpertsCore::mainWindow
	// 说明：	使用重写，使其指向专家端的主窗口
	// 权限：   virtual public 
	// 返回值： WindowInterface*
	// 限定词： const 
	//*********************************************************
	virtual WindowInterface* mainWindow() const override;
	//*********************************************************
	// 函数：   initOthers
	// 全称：  	AssistCore::initOthers
	// 说明：	所有的绑定操作，在重写此函数后在此进行，可以确保所有已经创建完成
	// 权限：   virtual protected 
	// 返回值： void
	// 限定词：
	//*********************************************************
	virtual void initOthers() override;

	//*********************************************************
	// 函数：   netAreaConnect
	// 全称：  	ExpertsCore::netAreaConnect
	// 说明：	重写本函数的意义在于，意味着区域服的TCP发来信号已经连接
	// 权限：   virtual public 
	// 返回值： void
	// 限定词：
	// 参数： 	std::string const & strMsg				解释：TCP的文字消息
	//*********************************************************
	virtual void netAreaConnect(std::string const& strMsg);
public:
	void receipt_heartbeat(std::string const& strMsg, msg_header_t const& head);
private:
	ExpertsWindowInterface* m_pMainWindow;
};

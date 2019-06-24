#pragma once

#include <QStandardItemModel>
#include "medicalwidget_global.h"

typedef std::tuple<int32_t, std::string, std::string, std::string, std::string, std::string, std::string, std::string,int32_t> assis_regist_row;

class MEDICALWIDGET_EXPORT TableModel : public QStandardItemModel
{
	Q_OBJECT

public:
	TableModel(QObject *parent);


	//*********************************************************
	// 函数：   make_assist_registrarow
	// 全称：  	TableModel::make_assist_registrarow
	// 说明：
	// 权限：   public static 
	// 返回值： QList<QStandardItem*>
	// 限定词：
	// 参数： 	assis_regist_row const & value	   解释：挂号的信息
	// 参数： 	bool isHanderUseButton			   解释：操作栏是否使用了按钮
	// 参数： 	bool isButtonEnable				   解释：按钮是否是可以红装填
	// 参数： 	QString const & strPix			   解释：按钮图片，图片是可选择（限制）
	//*********************************************************
	static QList<QStandardItem*> make_assist_registrarow(assis_regist_row const& value, bool isHanderUseButton = false, bool isButtonEnable = true, QString const& strPix = "normal");

	//*********************************************************
	// 函数：   make_experts_registrarow
	// 全称：  	TableModel::make_experts_registrarow
	// 说明：
	// 权限：   public static 
	// 返回值： QList<QStandardItem*>
	// 限定词：
	// 参数： 	QString const & num					解释：专家就诊号
	// 参数： 	QString const & patName				解释：患者姓名
	// 参数： 	QString const & patSex				解释：患者性别
	// 参数： 	QString const & handlerText			解释：操作栏的文字
	// 参数： 	bool isHandlerUseButton				解释：是否使用了按钮委托
	// 参数： 	bool isButtonEnable					解释：按钮是否是开启的状态
	// 参数： 	QString const & strPix				解释：按钮的图片使用样式，详见委托中string2pixmap
	//*********************************************************
	static QList<QStandardItem*> make_experts_registrarow(QString const& num, QString const& patName, QString const& patSex, QString const& handlerText = "--",
		bool isHandlerUseButton = false, bool isButtonEnable = false, QString const& strPix = "normal");
	//*********************************************************
	// 函数：   make_offlinero
	// 全称：  	TableModel::make_offlinero
	// 说明：
	// 权限：   public static 
	// 返回值： QT_NAMESPACE::QList<QStandardItem*>
	// 限定词：
	// 参数： 	QString const & typeName				解释：报告类型（比如：心电检查、血压等）
	// 参数： 	QString const & className				解释：项目（比如：血压检测，心电图）
	// 参数： 	QString const & datetime				解释：时间
	// 参数： 	QString const & lookupText				解释：查看栏文字
	// 参数： 	QString const & delText					解释：删除栏文字
	// 参数： 	bool isLookupUseButton					解释：查看是否使用了按钮
	// 参数： 	bool isLookupEnable						解释：查看的按钮是否可用状态
	// 参数： 	QString const & strLookPic				解释：查看按钮的图片类型，说明
	// 参数： 	bool isDelUseButton						解释：删除栏是否使用了按钮
	// 参数： 	bool isDelEnable						解释：删除按钮是否可用状态
	// 参数： 	QString const & strDelPic				解释：删除按钮的图片类型，说明
	//*********************************************************
	static QList<QStandardItem*> make_offlinero(QString const& typeName, QString const& className, QString const& datetime, QString const& lookupText = "", QString const& delText = "",
		bool isLookupUseButton = true, bool isLookupEnable = true, QString const& strLookPic = "lookup", bool isDelUseButton = true, bool isDelEnable = true, QString const& strDelPic = "del");

	static QList<QStandardItem*> make_historyStatis(QString const& strDate, QString const& patNameInfo, QString const& experts, QString const& handles = QStringLiteral("患者详情;诊断详情"), QString const& pics="blue;yellow");
	~TableModel();
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

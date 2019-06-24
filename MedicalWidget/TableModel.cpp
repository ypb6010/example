#include "stable.h"
#include "TableModel.h"

TableModel::TableModel(QObject *parent)
	: QStandardItemModel(parent)
{
}

QList<QStandardItem*> TableModel::make_assist_registrarow(assis_regist_row const& value, bool isHanderUseButton, bool isButtonEnable, QString const& strPix)
{
	auto&&[rank, patient_id, register_id, doctor_id, doctor_name, patient_name, code, state, wait_num] = value;
	QList<QStandardItem*> row;
	QStandardItem* expertsNum = new QStandardItem(QString::number(rank));
	QStandardItem* patName = new QStandardItem(String2QString(patient_name));
	QStandardItem* expertname = new QStandardItem(String2QString(doctor_name));
	QStandardItem* patState = new QStandardItem(String2QString(state));
	QStandardItem* queueNum = new QStandardItem(QString::number(wait_num));
	QStandardItem* handler = new QStandardItem(isHanderUseButton ? QStringLiteral("恢复队列"): QStringLiteral("--"));

	QVariantList dataList;
	dataList << rank << String2QString(patient_id) << String2QString(register_id) << String2QString(doctor_id) 
		<< String2QString(doctor_name) << String2QString(patient_name) << String2QString(code) << String2QString(state) 
		<< wait_num;
	handler->setData(dataList, Qt::UserRole + 3);
	handler->setData(isHanderUseButton, Qt::UserRole);
	handler->setData(isButtonEnable, Qt::UserRole + 1);
	handler->setData(strPix, Qt::UserRole + 2);
	row << expertsNum << patName << expertname << patState << queueNum << handler;
	foreach(auto item, row)
	{
		item->setEditable(false);
	}
	return row;
}

QList<QStandardItem*> TableModel::make_experts_registrarow(QString const& num, QString const& patName, QString const& patSex, QString const& handlerText /*= "--"*/, bool isHandlerUseButton /*= false*/, bool isButtonEnable /*= false*/, QString const& strPix /*= "normal"*/)
{
	QList<QStandardItem*> row;
	QStandardItem* numItem = new QStandardItem(num);
	QStandardItem* patNameItem = new QStandardItem(patName);
	QStandardItem* patSexItem = new QStandardItem(patSex);
	QStandardItem* handlerItem = new QStandardItem(handlerText);
	handlerItem->setData(isHandlerUseButton, Qt::UserRole);
	handlerItem->setData(isButtonEnable, Qt::UserRole + 1);
	handlerItem->setData(strPix, Qt::UserRole + 2);
	row << numItem << patNameItem << patSexItem << handlerItem;
	for each (auto& item in row)
	{
		item->setEditable(false);
	}
	return row;
}

QList<QStandardItem*> TableModel::make_offlinero(QString const& typeName, QString const& className, QString const& datetime, QString const& lookupText, QString const& delText,
	bool isLookupUseButton, bool isLookupEnable, QString const& strLookPic, bool isDelUseButton, bool isDelEnable, QString const& strDelPic)
{
	QList<QStandardItem*> row;
	QStandardItem* typeItem = new QStandardItem(typeName);
	QStandardItem* classitem = new QStandardItem(className);
	QStandardItem* dateItem = new QStandardItem(datetime);
	QStandardItem* lookItem = new QStandardItem(lookupText);
	QStandardItem* delItem = new QStandardItem(delText);
	lookItem->setData(isLookupUseButton, Qt::UserRole);
	lookItem->setData(isLookupEnable, Qt::UserRole + 1);
	lookItem->setData(strLookPic, Qt::UserRole + 2);
	delItem->setData(isDelUseButton, Qt::UserRole);
	delItem->setData(isDelEnable, Qt::UserRole + 1);
	delItem->setData(strDelPic, Qt::UserRole + 2);
	row << typeItem << classitem << dateItem << lookItem << delItem;
	foreach(auto item, row)
	{
		item->setEditable(false);
	}
	return row;
}

QList<QStandardItem*> TableModel::make_historyStatis(QString const& strDate, QString const& patNameInfo, QString const& experts, QString const& handles, QString const& pics)
{
	QList<QStandardItem*> row;
	QStandardItem* dateItem = new QStandardItem(strDate);
	QStandardItem* nameInfoItem = new QStandardItem(patNameInfo);
	QStandardItem* expertsItem = new QStandardItem(experts);
	QStandardItem* handlersItem = new QStandardItem(handles);
	handlersItem->setData(pics, Qt::UserRole);
	row << dateItem << nameInfoItem << expertsItem << handlersItem;
	foreach(auto item, row)
	{
		item->setEditable(false);
	}
	return row;
}

TableModel::~TableModel()
{
}

QVariant TableModel::data(const QModelIndex &index, int role /*= Qt::DisplayRole*/) const
{
	if (Qt::TextAlignmentRole == role)
		return Qt::AlignCenter;
	else if (role == Qt::FontRole)
	{
		return QFont("MicrosoftYaHei", 12, qRgb(102, 102, 102));
	}
	else if (role == Qt::TextColorRole)
	{
		return qRgb(102, 102, 102);
	}
	return QStandardItemModel::data(index, role);
}

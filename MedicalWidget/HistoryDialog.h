#pragma once

#include <QDialog>

#ifndef GLOBAL_DEFINE //检测没有包含全局头文件，做一下声明
struct ListContent
{
	std::string                content;             //内容
	std::string                patient_id;          //病人id
	std::string                doctor_id;           //专家id
	std::string                datetime;            //创建时间格式:YY-mm-dd HH:MM:SS
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & content;
		ar & patient_id;
		ar & doctor_id;
		ar & datetime;
	}
};
namespace boost
{
	namespace serialization
	{
		template<class Archive>
		void serialize(Archive & ar, ListContent & g, const unsigned int version)//必须包含在boost::serialization名字空间下
		{
			ar & g.content;
			ar & g.patient_id;
			ar & g.doctor_id;
			ar & g.datetime;
		}
	}
}
//病史信息响应
struct IllHistoryResponse
{
	std::list <ListContent>		drug;				 //药物过敏史
	std::list <ListContent>		past;                //既往史
	std::list <ListContent>		family;              //家族史
	std::list <ListContent>		genetic;             //遗传病史
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & drug;
		ar & past;
		ar & family;
		ar & genetic;
	}
};
namespace boost
{
	namespace serialization
	{
		template<class Archive>
		void serialize(Archive & ar, IllHistoryResponse & g, const unsigned int version)//必须包含在boost::serialization名字空间下
		{
			ar & g.drug;
			ar & g.past;
			ar & g.family;
			ar & g.genetic;
		}
	}
}
#endif
namespace Ui
{
	class HistoryDialog;
};

class MEDICALWIDGET_EXPORT HistoryDialog : public QDialog
{
	Q_OBJECT

public:
	enum WindowIndex
	{
		Drug = 0,
		Past = 1,
		Family = 2,
		Genetic = 3
	};
	enum HistoryDialog::WindowIndex :int;
public:
	HistoryDialog(QWidget *parent = Q_NULLPTR);
	~HistoryDialog();
	void setData(IllHistoryResponse const& hisData);
	void setIndex(WindowIndex index);
	void setVisiableAppend(bool bVisiable);
signals:
	void addDrugClicked();
	void addPastClecked();
	void addFamilyClicked();
	void addGeneticClicked();
private:
	Ui::HistoryDialog* ui;
	QStandardItemModel* drupModel;
	QStandardItemModel* pastModel;
	QStandardItemModel* familyModel;
	QStandardItemModel* geneticModel;

};

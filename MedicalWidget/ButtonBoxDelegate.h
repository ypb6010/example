#pragma once

#include <QStyledItemDelegate>
#include "medicalwidget_global.h"

typedef std::vector<QStyleOptionButton*> Btns_type;

class MEDICALWIDGET_EXPORT ButtonBoxDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	ButtonBoxDelegate(QObject *parent);
	~ButtonBoxDelegate();
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
private:
	inline QPixmap stringToPixmap(QString const& string);
signals:
	void clicked(QModelIndex,int);
protected:
	int m_nType;  // 按钮状态-1：划过 2：按下
	QPoint m_mousePoint;	
	QMap<QModelIndex, Btns_type> m_btsMap;
};

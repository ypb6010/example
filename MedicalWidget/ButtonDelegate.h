#pragma once

#include <QStyledItemDelegate>
#include "medicalwidget_global.h"
template <class Key, class T>
class QMap;

class MEDICALWIDGET_EXPORT ButtonDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	ButtonDelegate(QObject *parent);
	~ButtonDelegate();
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
signals:
	void clicked(QModelIndex);
protected:
	inline QPixmap stringToPixmap(QString const& picStr) const;
private:
	QMap<QModelIndex, QStyleOptionButton*> m_btns;
};

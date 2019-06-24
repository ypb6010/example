#pragma once

#include <QHeaderView>
#include "medicalwidget_global.h"

class MEDICALWIDGET_EXPORT TableHeaderView : public QHeaderView
{
	Q_OBJECT
protected:
	virtual void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const override;
public:
	TableHeaderView(Qt::Orientation orientation, QWidget *parent = nullptr);
	TableHeaderView* clone();
	~TableHeaderView();
};

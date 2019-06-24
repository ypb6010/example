#pragma once

#include <QDialog>
#include "ui_HistoryStatisWidget.h"

class HistoryStatisDialog : public QDialog
{
	Q_OBJECT

public:
	HistoryStatisDialog(QWidget *parent = Q_NULLPTR);
	~HistoryStatisDialog();

private:
	Ui::HistoryStatisDialog ui;
	TableModel* m_pModel;
};

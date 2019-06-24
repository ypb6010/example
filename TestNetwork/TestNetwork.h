#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestNetwork.h"


class QTcpServer;
class QTcpSocket;

class TestNetwork : public QMainWindow
{
	Q_OBJECT

public:
	TestNetwork(QWidget *parent = Q_NULLPTR);
private slots:
	void on_send();
	void on_build();
private:
	int32_t randsize(int32_t max_size)
	{
		return std::rand() % max_size;
	}
private:
	Ui::TestNetworkClass ui;
	QTcpServer* m_pServer;
	QList<QTcpSocket*> m_pSockList;
	QVector<char> m_vecdata;
	int m_nsize;
};

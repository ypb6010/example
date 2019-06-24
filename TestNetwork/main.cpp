#include "TestNetwork.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestNetwork w;
	w.show();
	return a.exec();
}

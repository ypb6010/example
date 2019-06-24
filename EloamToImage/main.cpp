#include "EloamToImage.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	EloamToImage w;
	w.show();
	return a.exec();
}

#include "cube.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Cube w;
	w.show();
	return a.exec();
}

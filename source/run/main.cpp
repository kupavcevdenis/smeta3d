#include <QApplication>
#include "gui_basis/mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	CMainWindow w;

	w.show();
	return a.exec();
}
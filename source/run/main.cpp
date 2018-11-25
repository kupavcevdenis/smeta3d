#include <QApplication>
#include "gui_basis/mainwindow.h"
#include "kernel/ifc/ICore.h"


using namespace smeta3d;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	CMainWindow w;

	SP_ICore ptrCore = GetSingltonCore();

	ptrCore->Init();

	w.show();
	int nRet = a.exec();
	ptrCore->DeInit();

	return nRet;
}

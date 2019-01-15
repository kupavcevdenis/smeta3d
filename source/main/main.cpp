#include <QApplication>
#include "gui_basis/mainwindow.h"
#include "kernel/ifc/ICore.h"

#include "Context.h"

using namespace smeta3d;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);	

	SP_ICore ptrCore = GetSingltonCore();



	CMainWindow w;

	CContext* context = new CContext(&w);
	w.setCentralWidget(context);

	ptrCore->Init((HWND)context->winId());

	w.show();
	int nRet = a.exec();
	ptrCore->DeInit();

	return nRet;
}

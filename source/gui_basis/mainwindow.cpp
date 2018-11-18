#include "gui_basis/mainwindow.h"


CMainWindow::CMainWindow(QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
	setupUi(this);
}

CMainWindow::~CMainWindow()
{

}
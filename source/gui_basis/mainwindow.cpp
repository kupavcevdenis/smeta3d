#include "gui_basis/mainwindow.h"

#include "ui_mainwindow.h"

CMainWindow::CMainWindow(QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
	m_pUI = new Ui::MainWindow;
	m_pUI->setupUi(this);
}

CMainWindow::~CMainWindow()
{
	delete m_pUI;
}
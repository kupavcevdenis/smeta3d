#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

class CMainWindow : public QMainWindow, Ui::MainWindow
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~CMainWindow();
};

#endif // MAIN_WINDOW_H*/

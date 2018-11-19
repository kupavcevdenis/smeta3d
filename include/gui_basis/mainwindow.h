#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

namespace Ui
{
	class MainWindow;
}


class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~CMainWindow();

private:
	Ui::MainWindow* m_pUI;
};

#endif // MAIN_WINDOW_H*/

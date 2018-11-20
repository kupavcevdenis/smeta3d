#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#ifndef GUI_BASIS_EXPORT
#if defined(gui_basis_EXPORTS)
#define GUI_BASIS_EXPORT __declspec(dllexport)
#else
#define GUI_BASIS_EXPORT __declspec(dllimport)
#endif
#endif

namespace Ui
{
	class MainWindow;
}


class GUI_BASIS_EXPORT CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~CMainWindow();

private:
	Ui::MainWindow* m_pUI;
};

#endif // MAIN_WINDOW_H*/

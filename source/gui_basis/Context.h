#ifndef CContext_H
#define CContext_H
#include <QWidget>
#include "Core.h"
#include <qdatetime.h>
class CContext : public QWidget
{
public:
	CContext(QWidget* pParent);
	~CContext();
	void timerEvent(QTimerEvent *pEvent);
	virtual void resizeEvent(QResizeEvent *);
	QPaintEngine *paintEngine() const {return NULL;}
	void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
	bool event(QEvent *);
private:
	
	int m_TimerID_25;
	QTime m_Time;
	int countframe;
	float sec;
};
#endif


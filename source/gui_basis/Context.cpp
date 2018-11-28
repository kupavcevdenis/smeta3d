#include "Context.h"
#include <QResizeEvent>
#include <QPainter>
#include <QMainWindow>
#include <QStatusBar>

CContext::CContext(QWidget* pParent):
QWidget(pParent)
{
	setAttribute(Qt::WA_PaintOnScreen);
	m_TimerID_25  = startTimer( 0 );
	m_Time.start();
	countframe = 0;
	sec = 0;

}
CContext::~CContext()
{
	killTimer(m_TimerID_25);
}
//таймер для вызова отрисовки
void CContext::timerEvent(QTimerEvent *pEvent)
{ 
	float fTimePerFrame = m_Time.restart();
	Core* pCore = GetSingltonCore();
	if(pCore && pCore->IsInit())
		pCore->Simulate(fTimePerFrame);
	
	countframe++;
	sec += fTimePerFrame;
	if(sec > 1000.f)
	{
		//QPainter p(this);
		//p.setBrush(QBrush(QColor(255,255,255)));
		//p.drawText(100,100,QString("%1").arg(countframe));
		qobject_cast<QMainWindow*>(parentWidget())->statusBar()->showMessage(QString("%1").arg(countframe));
		countframe = 0;
		sec = 0;
	}	

}
void CContext::resizeEvent(QResizeEvent *evnt)
{
	Core* pCore = GetSingltonCore();
	if(pCore && pCore->IsInit())
		pCore->Resize(this->width(), this->height());
}
void CContext::keyPressEvent(QKeyEvent *evn)
{
	Core* pCore = GetSingltonCore();
	if(!pCore || !pCore->IsInit())
		return;

	switch(evn->key())
	{
	case Qt::Key_Left:
		{
			if(evn->modifiers()==Qt::ShiftModifier)
				pCore->SetEvent(Core::eTE_FastLeft);
			else
				pCore->SetEvent(Core::eTE_Left);
			break;
		}
	case Qt::Key_Right:
		{
			if(evn->modifiers()==Qt::ShiftModifier)
				pCore->SetEvent(Core::eTE_FastRight);
			else
				pCore->SetEvent(Core::eTE_Right);
			break;
		}
	default: break;
	}
	QWidget::keyPressEvent(evn);
}
void CContext::keyReleaseEvent(QKeyEvent *evn)
{
	
	Core* pCore = GetSingltonCore();
	if(!pCore || !pCore->IsInit())
		return;

	pCore->SetEvent(Core::eTE_Unknow);
	QWidget::keyReleaseEvent(evn);
}
bool CContext::event(QEvent *evn)
{
	Core* pCore = GetSingltonCore();
	if(!pCore || !pCore->IsInit())
		return QWidget::event(evn);

	QEvent::Type type = evn->type();
	if(type != QEvent::KeyPress)
		return QWidget::event(evn);
	QKeyEvent* pEvent = dynamic_cast<QKeyEvent*>(evn);

	switch(pEvent->key())
	{
	case Qt::Key_Left:
		{
			pCore->SetEvent(Core::eTE_Left);
			break;
		}
	case Qt::Key_Right:
		{
			pCore->SetEvent(Core::eTE_Right);
			break;
		}
	default: break;
	}

	return QWidget::event(evn);
}



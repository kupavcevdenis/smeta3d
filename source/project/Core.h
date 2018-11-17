/*#ifndef CORE_H
#define CORE_H

#include "GLContext.h"
#include "WinMenu.h"
#include "Game.h"

class Core
{
public:
	Core();
	~Core();
	bool Init(const HWND& HWnd);
	void Simulate(float fTimePerSec);
	void Resize(int w, int h);
	bool IsInit();
	Shader* GetShader();
	

	enum ETypeEvent
	{
		eTE_Unknow		= 0,
		eTE_Esc			= 1,
		eTE_Left		= 2,
		eTE_Right		= 3,
		eTE_FastLeft    = 4,
		eTE_FastRight   = 5
	};
	
	void  SetEvent(const ETypeEvent& eType_);
	inline ETypeEvent GetEvent() const {return m_eTypeEvent;}

private:
	GLContext* m_pContext;
	WinMenu*   m_pMenu;
	Game*      m_pGame;
	Shader*    m_pShader;
	bool	   m_bInit;
	ETypeEvent m_eTypeEvent;
};
Core* GetSingltonCore();
#endif*/
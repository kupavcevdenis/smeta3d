/*#include "Core.h"

Core* GetSingltonCore()
{
	static Core* pCore = NULL;
	if(!pCore)
		pCore = new Core();
	return pCore;
}

Core::Core() :
m_pContext(NULL),
m_pMenu(NULL),
m_pShader(NULL),
m_pGame(NULL),
m_bInit(false),
m_eTypeEvent(eTE_Unknow)
{	
}
Core::~Core()
{
}
bool Core::Init(const HWND& HWnd)
{
	m_pContext = new GLContext(HWnd);
	m_pMenu = new WinMenu();
	m_pGame = new Game();
	m_pShader = new Shader();
	m_pShader->Bind();
	Matrix4f mat;
	mat.InitOrthoProjTransform(0,1,1,0,-1,1);
	m_pShader->projection(mat);
	m_bInit = true;
	return IsInit();
}
Shader* Core::GetShader()
{
	return m_pShader;
}
void Core::Simulate(float fTimePerSec)
{
	m_pContext ->Clear();

	m_pMenu->Render();

	m_pGame->Update(fTimePerSec);
	m_pGame->Render();

	m_pContext ->Swap();
}
void Core::Resize(int w, int h)
{
	m_pContext->Resize(w,h);
}
bool Core::IsInit()
{
	return m_bInit;
}

void  Core::SetEvent(const ETypeEvent& eType_)
{
	m_eTypeEvent = eType_;
}*/
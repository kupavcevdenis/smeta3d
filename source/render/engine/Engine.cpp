#include "Engine.h"

#include "gl_render_system/GLContext.h"

namespace smeta3d
{
	/////////////////////////////////////////////////////////////////////
	///
	SP_IEngine GetSingltonEngine()
	{
		static SP_IEngine ptrEngine = nullptr;
		if (!ptrEngine)
			ptrEngine.reset(new CEngine());
		return ptrEngine;
	}
	/////////////////////////////////////////////////////////////////////
	///

	CEngine::CEngine()
	{
	}
	/////////////////////////////////////////////////////////////////////
	///

	CEngine::~CEngine()
	{
	}
	/////////////////////////////////////////////////////////////////////
	///

	bool CEngine::Init(const HWND& HWnd)
	{
		m_ptrContext = std::make_shared<GLContext>(HWnd);
		return true;
	}
	/////////////////////////////////////////////////////////////////////
	///

	bool CEngine::IsInit() const
	{
		return true;
	}
	/////////////////////////////////////////////////////////////////////
	///

	void CEngine::DeInit()
	{
		m_ptrContext = nullptr;
	}

	/////////////////////////////////////////////////////////////////////
	///
	void CEngine::Update(float fTimePerSec)
	{
		m_ptrContext->Clear();
	}
	/////////////////////////////////////////////////////////////////////
	///
	void CEngine::BeginRender()
	{

	}

	/////////////////////////////////////////////////////////////////////
	///
	void CEngine::Render()
	{
		
	}

	/////////////////////////////////////////////////////////////////////
	///
	void CEngine::EndRender()
	{
		m_ptrContext->Swap();
	}

	/////////////////////////////////////////////////////////////////////
	///
	void CEngine::Resize(int w, int h)
	{
		m_ptrContext->Resize(w, h);
	}
}
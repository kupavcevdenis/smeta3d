#include "Core.h"

namespace smeta3d
{
	/////////////////////////////////////////////////////////////////////
	///
	SP_ICore GetSingltonCore()
	{
		static SP_ICore ptrCore = nullptr;
		if (!ptrCore)
			ptrCore.reset(new CCore());
		return ptrCore;
	}

	/////////////////////////////////////////////////////////////////////
	///
	CCore::CCore()
	{
	}

	/////////////////////////////////////////////////////////////////////
	///
	CCore::~CCore()
	{
	}

	/////////////////////////////////////////////////////////////////////
	///
	bool CCore::Init()
	{
		if (IsInit())
			return false;

		m_ptrEngine = smeta3d::GetSingltonEngine();
		if (m_ptrEngine)
			m_ptrEngine->Init();

		m_bInit = m_ptrEngine->IsInit();
		return IsInit();
	}
	/////////////////////////////////////////////////////////////////////
	///
	bool CCore::IsInit() const
	{
		return m_bInit && m_ptrEngine;
	}
	/////////////////////////////////////////////////////////////////////
	///
	void CCore::DeInit()
	{
		if (!IsInit())
			return;

		if (m_ptrEngine)
		{
			m_ptrEngine->DeInit();
			m_ptrEngine = nullptr;
		}
		m_bInit = false;
	}
	/////////////////////////////////////////////////////////////////////
	///
	const smeta3d::SP_IEngine& CCore::GetEngine() const
	{
		return m_ptrEngine;
	}
	/////////////////////////////////////////////////////////////////////
	///
	void CCore::Simulate(float fTimePerSec)
	{
		/*m_pContext->Clear();

		m_pMenu->Render();

		m_pGame->Update(fTimePerSec);
		m_pGame->Render();

		m_pContext->Swap();*/

		m_ptrEngine->Update(fTimePerSec);

		m_ptrEngine->BeginRender();		
		m_ptrEngine->Render();
		m_ptrEngine->EndRender();
	}
	void CCore::Resize(int w, int h)
	{
		m_ptrEngine->Resize(w, h);
	}
}

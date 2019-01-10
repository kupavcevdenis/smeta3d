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

		smeta3d::SP_IEngine ptrEngine = GetEngine();
		if (ptrEngine)
			ptrEngine->Init();

		m_bInit = ptrEngine->IsInit();
		return IsInit();
	}
	/////////////////////////////////////////////////////////////////////
	///
	bool CCore::IsInit() const
	{
		return m_bInit;
	}
	/////////////////////////////////////////////////////////////////////
	///
	void CCore::DeInit()
	{
		if (!IsInit())
			return;

		smeta3d::SP_IEngine ptrEngine = GetEngine();
		if (ptrEngine)
			ptrEngine->DeInit();

		m_bInit = false;
	}
	/////////////////////////////////////////////////////////////////////
	///
	const smeta3d::SP_IEngine& CCore::GetEngine() const
	{
		return smeta3d::GetSingltonEngine();
	}
}

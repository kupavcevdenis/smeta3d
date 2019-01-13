#ifndef CORE_H
#define CORE_H

#include "kernel/ifc/ICore.h"

namespace smeta3d
{
	class CCore : public ICore
	{
	public:
		CCore();
		~CCore();

		DECL_PUBLIC_ICORE;

	public:

		smeta3d::SP_IEngine m_ptrEngine;
		bool m_bInit;

	};


}
#endif
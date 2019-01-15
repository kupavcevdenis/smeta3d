#ifndef GLContex_H_
#define GLContex_H_

#include <windows.h>
#include "render\engine\ifc\IContext.h"

namespace smeta3d
{
	class GLContext : public IContext
	{
	public:
		GLContext(const HWND& HWnd);
		~GLContext();

		DECL_PUBLIC_ICONTEXT

	private:
		bool CreateContext(const HWND& HWnd);
	private:
		struct SAppContext* m_pAppContext;


	};
}

#endif /* GLContex_H_ */

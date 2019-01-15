#ifndef ENGINE_H_
#define ENGINE_H_

#include "render/engine/ifc/IEngine.h"
#include "render/engine/ifc/IContext.h"

namespace smeta3d
{
	class CEngine : public IEngine
	{
	public:
		CEngine();
		~CEngine();

		DECL_PUBLIC_IENGINE

	private:

		std::shared_ptr<IContext> m_ptrContext;

	};
}
#endif /* GLContex_H_ */

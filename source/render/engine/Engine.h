#ifndef ENGINE_H_
#define ENGINE_H_

#include "render/engine/ifc/IEngine.h"

namespace smeta3d
{
	class CEngine : public IEngine
	{
	public:
		CEngine();
		~CEngine();

		DECL_PUBLIC_IENGINE


	};
}
#endif /* GLContex_H_ */

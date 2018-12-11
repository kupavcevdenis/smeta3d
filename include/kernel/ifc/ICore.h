#ifndef ICORE_H
#define ICORE_H

#include <memory>
#include "render/engine/ifc/IEngine.h"

namespace smeta3d
{
	class ICore
	{
		public:
			~ICore() {};

			virtual bool Init() = 0;
			virtual bool IsInit() const  = 0;
			virtual void DeInit() = 0;

			virtual engine_smeta3d::SP_IEngine GetEngine()  = 0;
	};




	using SP_ICore = std::shared_ptr<ICore>;

	SP_ICore __declspec(dllexport) GetSingltonCore();
}

#define DECL_PUBLIC_ICORE \
		bool Init(); \
        bool IsInit() const; \
        void DeInit(); \
	    engine_smeta3d::SP_IEngine GetEngine();

#endif
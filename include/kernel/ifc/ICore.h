#ifndef ICORE_H
#define ICORE_H

#include <memory>

namespace smeta3d
{
	class ICore
	{
		public:
			~ICore() {};

			virtual bool Init() = 0;
			virtual bool IsInit() const  = 0;
			virtual void DeInit() = 0;
	};


#define DECL_PUBLIC_ICORE \
		bool Init(); \
        bool IsInit() const; \
        void DeInit();


	using SP_ICore = std::shared_ptr<ICore>;

	SP_ICore __declspec(dllexport) GetSingltonCore();
}
#endif
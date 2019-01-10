#ifndef IENGINE_H_
#define IENGINE_H_


#include <memory>

namespace smeta3d
{

	class IEngine
	{
	public:
		~IEngine() {};

		virtual bool Init() = 0;
		virtual bool IsInit() const = 0;
		virtual void DeInit() = 0;



	};

	using SP_IEngine = std::shared_ptr<IEngine>;

	SP_IEngine __declspec(dllexport) GetSingltonEngine();
}
#define DECL_PUBLIC_IENGINE \
		bool Init(); \
        bool IsInit() const; \
        void DeInit();



#endif /* IENGINE_H_ */

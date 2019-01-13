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

		virtual void Update(float fTimePerSec) = 0;

		virtual void BeginRender() = 0;
		virtual void Render() = 0;
		virtual void EndRender() = 0;

		virtual void Resize(int w, int h) = 0;



	};

	using SP_IEngine = std::shared_ptr<IEngine>;

	SP_IEngine __declspec(dllexport) GetSingltonEngine();
}
#define DECL_PUBLIC_IENGINE \
		bool Init(); \
        bool IsInit() const; \
        void DeInit(); \
	    void Update(float fTimePerSec); \
        void BeginRender(); \
        void Render(); \
        void EndRender(); \
        void Resize(int w, int h);




#endif /* IENGINE_H_ */

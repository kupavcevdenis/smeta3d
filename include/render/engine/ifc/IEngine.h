#ifndef IENGINE_H_
#define IENGINE_H_


#include <memory>

class IEngine
{
public:
	~IEngine() {};

	virtual bool Init() = 0;
	virtual bool IsInit() const = 0;
	virtual void DeInit() = 0;

	

};

#define DECL_PUBLIC_IENGINE \
		bool Init(); \
        bool IsInit() const; \
        void DeInit();

using SP_IEngine = std::shared_ptr<IEngine>;

SP_IEngine __declspec(dllexport) GetSingltonEngine();

#endif /* IENGINE_H_ */

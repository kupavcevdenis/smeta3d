#ifndef IContex_H_
#define IContex_H_

#include <windows.h>

namespace smeta3d
{
	class IContext
	{
	public:
		virtual ~IContext() {};
		virtual void Clear() = 0;
		virtual void Swap() = 0;
		virtual void Resize(int w, int h) = 0;

	};
}

#define DECL_PUBLIC_ICONTEXT \
		void Clear(); \
		void Swap(); \
		void Resize(int w, int h);


#endif /* IContext */

#ifndef _IEVENT_
#define _IEVENT_

#include <system/uuid.h>

namespace smeta3d
{

	using event_id = CUUID;

	class IEvent
	{
	public:
		~IEvent() {};
		virtual const event_id& GetID() const = 0;
	};

   
} // end namespace smeta3d

#define DECL_EVENT(CLASS_EVENT) \
   public: \
     static const smeta3d::event_id& GetCurrentID() \
     { \
	   static smeta3d::event_id s_id = smeta3d::CUUID(CLASS_EVENT##_STR); \
       return s_id; \
     } \
     virtual const smeta3d::event_id& GetID() const \
     { \
       return CLASS_EVENT::GetCurrentID(); \
     } \

#endif // _IEVENT_

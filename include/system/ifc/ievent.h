#ifndef _IEVENT_
#define _IEVENT_

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace smeta3d
{

	using event_id = boost::uuids::uuid;

	class IEvent
	{
	public:
		~IEvent() {};
		virtual const event_id& GetID() const = 0;
	};

#define DECL_EVENT(CLASS_EVENT) \
   public: \
     static const event_id& GetCurrentID() \
     { \
	   static event_id s_id = boost::uuids::string_generator(CLASS_EVENT##_STR); \
       return s_id; \
     } \
     virtual const event_id& GetID() \
     { \
       return CLASS_EVENT::GetCurrentID(); \
     } \
   
} // end namespace smeta3d



#endif // _IEVENT_

#include <system/event_manager.h>
#include <string>
#include <iostream>

#define CEventTest_STR "59032DEA-497F-4480-A2BB-2D240DB052DD"
class CEventTest : public smeta3d::IEvent
{
	DECL_EVENT(CEventTest)
	CEventTest() {}
};

smeta3d::CEventManager eventMng;

class CReceiver
{
public:

	CReceiver()
	{
		eventMng.connectEvent<CEventTest, EVENT_CALLBACK(CReceiver, testEvent, CEventTest)>(this, NULL, this, true, true);
	}
	~CReceiver()
	{
		eventMng.disconnectEvent<CEventTest, CReceiver>(this);
	}

	void testEvent(CEventTest* event_)
	{
		std::cout << "event!!!" << std::endl;
	}
};

int main()
{

	CReceiver receiver;
	CEventTest test;
	eventMng.sendEvent(NULL, NULL, &test);

}
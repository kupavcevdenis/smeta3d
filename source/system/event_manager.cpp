#include "system/event_manager.h"

namespace smeta3d
{

	//-----------------------------------------------------------------------------
	///
	CEventManager::CEventManager()
	{
	}


	//-----------------------------------------------------------------------------
	///
	void CEventManager::connectEvent(const event_id& id, bool ignoreSender, void *pSender,
		bool ignoreReceiver, void *pReceiver,
		const TEventCallBack& handler_func)
	{
		void *pListener = handler_func.Listener();
		assert(pListener);
		if (!pListener)
			return;
		SListenerData data;
		data.handler_func = handler_func;
		data.m_bIgnoreSender = ignoreSender;
		data.m_bIgnoreReceiver = ignoreReceiver;
		data.m_pSender = pSender;
		data.m_pReceiver = pReceiver;
		data.m_bConnected = true; /// Получатель действительно подключен

		TEventHandlerMap::iterator it = m_EventHandlers.find(id);
		if (it == m_EventHandlers.end())
		{
			TListenerMap listmap;
			listmap.insert(TListenerMap::value_type(pListener, data));
			m_EventHandlers.insert(TEventHandlerMap::value_type(id, listmap));
		}
		else
		{
			if (it->second.find(pListener) == it->second.end())
				it->second.insert(TListenerMap::value_type(pListener, data)); /// Добавление нового получателя заданного события
			else
				it->second[pListener] = data; /// Обновление условий получения событий
		}
	}


	//-----------------------------------------------------------------------------
	///
	void CEventManager::disconnectEvent(const event_id& id, void *pListener)
	{
		TEventHandlerMap::iterator it = m_EventHandlers.find(id);

		if (it != m_EventHandlers.end())
		{
			TListenerMap::iterator lit = it->second.find(pListener);
			if (lit != it->second.end())
			{
				lit->second.m_bConnected = false; // Удаление будет произведено в момент ближайшей рассылки события текущего типа
				return;
			}
		}
	}


	//-----------------------------------------------------------------------------
	///
	void CEventManager::sendEvent(const void *pSender, const void *pReceiver, IEvent* pEvent)
	{
		assert(pEvent && "Null event interface");
		TEventHandlerMap::iterator itHandler = pEvent ? m_EventHandlers.find(pEvent->GetID()) : m_EventHandlers.end();
		if (itHandler == m_EventHandlers.end())
			return;

		TListenerMap::iterator itListener = itHandler->second.begin(), itEndListener = itHandler->second.end();
		while (itListener != itEndListener)
		{
			SListenerData &ldata = itListener->second;   // информация об обработчике события
			if (!ldata.m_bConnected)   // Отложенное удаление
			{
				itHandler->second.erase(itListener++);
				continue;
			}

			if ((ldata.m_bIgnoreSender || ldata.m_pSender == pSender) && (ldata.m_bIgnoreReceiver || ldata.m_pReceiver == pReceiver))
				ldata.handler_func(pEvent);

			++itListener;
		}
	}


	//-----------------------------------------------------------------------------
	/// Менеджер по умолчанию (глобальный)
	/*DECL_IN_DLL CEventMgr& bm::EventMgr()
	{
	   static CEventMgr Mgr;
	   return Mgr;
	}*/
}
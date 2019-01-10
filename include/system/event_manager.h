#ifndef _EVENT_MANAGE_
#define _EVENT_MANAGE_

#include <map>
#include <memory.h>
#include "system/ifc/ievent.h"

#define EVENT_CALLBACK(Class, Metod, Arg)      Arg, Class, &Class::Metod

namespace smeta3d
{
   /**
   \brief ����� ��������������� ����� ��� ����������� ������������ �������
   */
   class CEventCallback
   {
   public:
      CEventCallback() : object_ptr(0), stub_ptr(0){}

      template <class C, class E, void (C::*Method)(E*)>
      static CEventCallback from_method(C* object_ptr)
      {
         CEventCallback d;
         d.object_ptr = object_ptr;
         d.stub_ptr = &method_stub<C, E, Method>; // #1
         return d;
      }

      void* Listener() const {return object_ptr;}

      void operator()(IEvent* value) const
      {
         (*stub_ptr)(object_ptr, value);
      }

   private:
      typedef void (*stub_type)(void*, IEvent*);

      void*     object_ptr;
      stub_type stub_ptr;

      template <class C, class E, void (C::*Method)(E*)>
      static void method_stub(void* object_ptr, IEvent* value)
      {
         C* p = static_cast<C*>(object_ptr);
         E* e = static_cast<E*>(value);
         (p->*Method)(e); // #2
      }
   };


   ////////////////////////////////////////////////////////////////////////////////
   /**
   \brief ����� "�������� �������".
   �������� �� �������� ������������������ ���������� � �������� ���������
   */
   class CEventManager
   {
   public:
	   CEventManager();

      typedef CEventCallback TEventCallBack;

      struct SListenerData
      {
         SListenerData(){memset(this, 0, sizeof(SListenerData));}
         TEventCallBack  handler_func;
         void*           m_pSender;
         void*           m_pReceiver;
         bool            m_bIgnoreSender;
         bool            m_bIgnoreReceiver;
         /// ���� ������ ��� ����������� ������ ���������� ��������� �� ����� �������� ���������
         bool            m_bConnected; /// ���������� ��������� � ����� �������� �������
      };

      /// ��������� �������.
      /// �� ���������� ������� @see pEvent_ ����������� ����� ������������ � ���������� ��
      /// ������� (�����) ��������� �������.
      /// @param pSender_ �������� ��������
      /// @param pReceiver_ ���������� �������
      /// @param pEvent_ ��������� �������
      void sendEvent(const void *pSender_, const void *pReceiver_, IEvent* pEvent_);

      template<class ES, class ER>
      void Conversion(ER*){}

      ///
      template <class ES, class ER, class C, void (C::*Method)(ER*) >
      void connectEvent(C *pListener, void *pSender, void *pReceiver, bool anySender=true, bool anyReceiver=true)
      {
         Conversion<ES,ER>((ES*)0); // �������� ����������� E � P
         TEventCallBack handler_func = TEventCallBack::from_method<C, ER, Method>(pListener);
         connectEvent(ES::GetCurrentEID(), anySender, pSender, anyReceiver, pReceiver, handler_func);
      }

      ///
      template <class ES, class C >
      void disconnectEvent(C *pListener)
      {
         disconnectEvent(ES::GetCurrentEID(), pListener);
      }

   protected:
      void connectEvent(const event_id& id, bool ignoreSender, void *pSender, bool ignoreReceiver, void *pReceiver, const TEventCallBack& handler_func);
      void disconnectEvent(const event_id& id, void *pListener);

   private:
      typedef std::map<void*, SListenerData>     TListenerMap;
      typedef std::map<event_id, TListenerMap>   TEventHandlerMap;

      TEventHandlerMap  m_EventHandlers;
   };

   //////////////////////////////////////
   // �������� �� ��������� (����������)
  // DECL_IN_DLL CEventMgr& EventMgr();

} // end namespace smeta3d


/* ������ ������������� ��. � "system/ifc/ievent.h" */


#endif // _EVENT_MANAGE_

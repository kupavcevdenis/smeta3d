/*
#include <iostream>
#include <boost/signals2/signal.hpp>
#include <boost/signals2/shared_connection_block.hpp>

struct HelloWorld
{
	void operator()() const
	{
		std::cout << "Hello, World!" << std::endl;
	}
};

void disconnect_example()
{
	boost::signals2::signal<void()> sig;

	//[ disconnect_code_snippet
	boost::signals2::connection c = sig.connect(HelloWorld());
	std::cout << "c is connected\n";
	sig(); // Prints "Hello, World!"

	c.disconnect(); // Disconnect the HelloWorld object
	std::cout << "c is disconnected\n";
	sig(); // Does nothing: there are no connected slots
		   //]
}

void block_example()
{
	boost::signals2::signal<void()> sig;

	//[ block_code_snippet
	boost::signals2::connection c = sig.connect(HelloWorld());
	std::cout << "c is not blocked.\n";
	sig(); // Prints "Hello, World!"

	{
		boost::signals2::shared_connection_block block(c); // block the slot
		std::cout << "c is blocked.\n";
		sig(); // No output: the slot is blocked
	} // shared_connection_block going out of scope unblocks the slot
	std::cout << "c is not blocked.\n";
	sig(); // Prints "Hello, World!"}
		   //]
}

struct ShortLived
{
	void operator()() const
	{
		std::cout << "Life is short!" << std::endl;
	}
};

void scoped_connection_example()
{
	boost::signals2::signal<void()> sig;

	//[ scoped_connection_code_snippet
	{
		boost::signals2::scoped_connection c(sig.connect(ShortLived()));
		sig(); // will call ShortLived function object
	} // scoped_connection goes out of scope and disconnects

	sig(); // ShortLived function object no longer connected to sig
		   //]
}

//[ disconnect_by_slot_def_code_snippet
void foo() { std::cout << "foo"; }
void bar() { std::cout << "bar\n"; }
//]

void disconnect_by_slot_example()
{
	boost::signals2::signal<void()> sig;

	//[ disconnect_by_slot_usage_code_snippet
	sig.connect(&foo);
	sig.connect(&bar);
	sig();

	// disconnects foo, but not bar
	sig.disconnect(&foo);
	sig();
	//]
}

int main()
{
	std::cout << "Disconnect example:\n";
	disconnect_example();

	std::cout << "\nBlock example:\n";
	block_example();

	std::cout << "\nScoped connection example:\n";
	scoped_connection_example();

	std::cout << "\nDisconnect by slot example:\n";
	disconnect_by_slot_example();

	return 0;
}*/
#include <iostream>
#include <boost/signals2.hpp>

using namespace std;
using namespace boost::signals2;

struct HelloWorld
{
	void operator()(int n) const
	{
		std::cout << "HelloWorld invocation with param " << n << endl;
	}
};

struct TrackedHelloWorld
{
	void operator()(int n) const
	{
		std::cout << "TrackedHelloWorld invocation with param " << n << endl;
	}
};


struct SPaintData
{
	SPaintData() {};
};


enum class ETypeSignal
{
	eTS_Unknown,
	eTS_Paint
    
};

bool Test()
{
	bool b = 0;
	return false;
}





/*class CSignalPaint : public CSignal 
{
public:
	CSignalPaint() {};
	virtual ETypeSignal Type() const { return ETypeSignal::eTS_Paint; }

public:

	using internal_signal = boost::signals2::signal<void(const SPaintData&)>;
	internal_signal m_signal;

	static bool m_bReg;
};

bool CSignalPaint::m_bReg = Test();
*/
class IEvent
{
};


template <class C, class E, void (C::*Method)(E*)>
static void method_stub(void* object_ptr, IEvent* value)
{
	C* p = static_cast<C*>(object_ptr);
	E* e = static_cast<E*>(value);
	(p->*Method)(e); // #2
}


class E: public IEvent
{

};

class C
{
public:
	void f(E*)
	{
		int e = 0;
	}
};


class D
{
public:

	void f0(E*)
	{
		int e = 0;
	}

	void f1(E*)
	{
		int e = 0;
	}
};

typedef void(*stub_type)(void*, IEvent*);

stub_type stub_ptr1 = &method_stub<C, E, &C::f>; // #1
stub_type stub_ptr2 = &method_stub<D, E, &D::f1>; // #2
stub_type stub_ptr3 = &method_stub<C, E, &C::f>; // #1

int main()
{

	C c;
	E e;
	(*stub_ptr1)(&c, &e);
	(*stub_ptr2)(&c, &e);


	// Сигнал, принимающий 1 целочисленный аргумент и возвращающий void
	boost::signals2::signal<void(int)> sig;

   

	// Создать вызываемый объект HelloWorld и подключить его
	HelloWorld hello;
	sig.connect(hello);

	// Создать вызываемый объект TrackedHelloWorld и подключить  // его посредством сильной ссылки; сделать его отслеживаемым.  // После выхода из блока объект будет удалён, и соответствующее  // подключение будет разорвано.
	{
		boost::shared_ptr<TrackedHelloWorld> p(new TrackedHelloWorld());
		boost::signals2::signal<void(int)>::slot_type s(*p);
		s.track(p);
		sig.connect(s);

		// Вызвать оба объекта
		sig(2);
	}

	// Вызвать первый объект (слот второго стал «неактивным»)
	sig(3);

	return 0;
}
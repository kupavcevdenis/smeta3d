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



class CSignalManager final
{
public:
	CSignalManager() {};


private:



};


int main()
{
	// ������, ����������� 1 ������������� �������� � ������������ void
	boost::signals2::signal<void(int)> sig;

   

	// ������� ���������� ������ HelloWorld � ���������� ���
	HelloWorld hello;
	sig.connect(hello);

	// ������� ���������� ������ TrackedHelloWorld � ����������  // ��� ����������� ������� ������; ������� ��� �������������.  // ����� ������ �� ����� ������ ����� �����, � ���������������  // ����������� ����� ���������.
	{
		boost::shared_ptr<TrackedHelloWorld> p(new TrackedHelloWorld());
		boost::signals2::signal<void(int)>::slot_type s(*p);
		s.track(p);
		sig.connect(s);

		// ������� ��� �������
		sig(2);
	}

	// ������� ������ ������ (���� ������� ���� �����������)
	sig(3);

	return 0;
}
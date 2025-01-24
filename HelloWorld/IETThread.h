#include<iostream>
#include<thread>

class IEThread {
public:
	IEThread();
	virtual ~IEThread();

	void start();
	static void sleep(int ms);

protected:
	virtual void run() = 0;
};
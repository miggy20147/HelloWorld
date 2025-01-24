#include "IETThread.h"

IEThread::IEThread() {

}

IEThread::~IEThread() {

}

void IEThread::start() {
	std::thread(&IEThread::run, this).detach();
}

void IEThread::sleep(int ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}
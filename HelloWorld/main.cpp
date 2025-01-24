//#include<iostream>
//#include<thread>
//
//void testFunc(int x)
//{
//	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
//	std::cout << "Hello World from Thread #" << x << ".\n";
//}
//
//
//int main() 
//{
//	std::cout << "Hello World from Main Thread.\n";
//
//	std::thread myThread(testFunc, 200);
//
//	//To report the results back to the main thread. "success"
//	//Guaranteed data from this thread
// 
// 
//	//join is not ideal for asynchronous mechanisms and persistent threads
//	//detach(): from thread main -> thread 1, thread 1 and thread main can run parallely
//	//used for persistent background threads and more control over synchronizing data
//	//join(): serializable 
//	myThread.detach();
//	std::cout << "Bye World!";
//}


//Create N independent threads that periodically print different print statements all threads one persistent until the main thread has stopped
#include<iostream>
#include<thread>
#include<array>

class MyThread
{
	int id;
	bool running = false;

public:
	MyThread(int id) {
		this->id = id;
	}

	void start(int id) {
		std::thread(&MyThread::run, this, id).detach();
	}

	void run(int id)
	{
		running = true;
		while (running) {
			std::cout << "Hello from thread: " << id << ".\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(3000));
			dismiss();
		}
	}

	void dismiss() {
		running = false;
	}
};

int main() 
{
	const int n = 20; //number of threads
	MyThread myThread = NULL;

	for (int i = 0; i < n; i++) {
		myThread.start(i);
	}
	//sleep
	std::this_thread::sleep_for(std::chrono::seconds(1));

}


#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

std::mutex g_mutex;

void Test1()
{
	unique_lock<std::mutex> lk(g_mutex);

	this_thread::sleep_for(10s);
	
	cout << "test1" << endl;
}

void Test2()
{
	unique_lock<std::mutex> lk(g_mutex);

	this_thread::sleep_for(10s);
	cout << "test2" << endl;
}

int main()
{
	thread th1(Test1);
	thread th2(Test2);

	th1.join();
	th2.join();
	return 0;
}

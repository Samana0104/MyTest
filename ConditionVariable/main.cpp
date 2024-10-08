#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <condition_variable>
using namespace std;

std::mutex g_mtx;
std::condition_variable g_cv;
bool g_bBus = 0;

void wait()
{
	std::unique_lock<std::mutex> lk(g_mtx);

	std::cout << "start waiting!" << std::endl;
	g_cv.wait(lk);
	std::cout << "finished waiting" << std::endl;
}

void signal()
{
	cout << "notify" << endl;
	g_cv.notify_all();
}

int main()
{
	std::thread t1(wait);

	this_thread::sleep_for(5s);
	std::thread t2(signal);

	t1.join();
	t2.join();
	return 0;

}

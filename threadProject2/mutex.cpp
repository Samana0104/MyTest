#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
using namespace std;

int sum = 0;

void Process()
{
	mutex mt;
	mt.lock();
	sum++;
	mt.unlock();
}

void Counter()
{
	mutex mt;
	mt.lock();
	Process();
	mt.unlock();
}
	

int main()
{
	thread th(Counter);
	thread th2(Counter);
	th.join();
	th2.join();
	cout << "Á¾·á" << endl;
	std::shared_mutex mtx;

	return 0;
}
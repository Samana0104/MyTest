#include <windows.h>
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

class tthread
{
private:
	int sum = 0;
	double a = 3.0;
public:
	void run(int repeat)
	{
		for (int i = 0; i < repeat; i++)
			sum++;
	}

	void print()
	{
		cout << "sum : " << sum << endl;
	}
};

void Counter(int start, int end)
{
	mutex mt;
	while (start < end)
	{
		mt.lock();
		cout << "thread ID : " << std::this_thread::get_id() << " , Counter : " << start << endl;
		start++;
		mt.unlock();
	}
}

int main()
{
	std::cout.sync_with_stdio(true);
	tthread th[2];
	thread th1(&tthread::run, &th[0], 1000);
	thread th2(&tthread::run, &th[1], 1000);
	cout << sizeof(tthread) << endl;
	return 0;
}
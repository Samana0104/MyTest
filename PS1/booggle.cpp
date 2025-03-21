#include <iostream>
#include <thread>
#include <atomic>

class Spinlock
{
private:
	std::atomic_flag flag = ATOMIC_FLAG_INIT;

public:
	void lock()
	{
		while (flag.test_and_set(std::memory_order_acquire)) {}
	}

	void unlock()
	{
		flag.clear(std::memory_order_release);
	}
};

Spinlock spinlock;
int sharedCounter = 0;

void increment()
{
	for (int i = 0; i < 1000000; ++i)
	{
		spinlock.lock();
		sharedCounter++;
		std::cout << "locked" << std::endl;
		spinlock.unlock();
		std::cout << "unlock" << std::endl;
	}
}

int main()
{
	std::thread t1(increment);
	std::thread t2(increment);

	t1.join();
	t2.join();

	std::cout << "Final Counter: " << sharedCounter << std::endl;
	return 0;
}
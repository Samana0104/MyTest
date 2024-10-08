#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <queue>
#include <fstream>
#include <sstream>

class MyLog
{
private:
	std::condition_variable m_condVar;
	std::mutex m_mutex;
	std::queue<std::string> m_queue;
	std::thread m_thread;
public:
	MyLog();
	~MyLog();

	void Log(const std::string& msg);
	void Process();
};


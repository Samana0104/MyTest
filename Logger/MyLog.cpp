#include "MyLog.h"

MyLog::MyLog()
{
	m_thread = std::thread(&MyLog::Process, this);
}

MyLog::~MyLog()
{
	std::unique_lock<std::mutex> lock(m_mutex);

}

void MyLog::Log(const std::string& msg)
{
	std::unique_lock<std::mutex> lk(m_mutex);
	m_queue.push(msg);
	m_condVar.notify_all();
}

void MyLog::Process()
{
	std::ofstream ofs("log.txt");

	if (ofs.fail())
	{
		std::cerr << "Failed" << std::endl;
		return;
	}
	
	std::unique_lock<std::mutex> lock(m_mutex);
	while (true)
	{
		if (!m_queue.empty())
		{
			break;
		}
		else
		{
			ofs << m_queue.front() << std::endl;
			m_queue.pop();
		}
	}
}

void SendMsg(int id, MyLog& log)
{

	for (int i = 0; i < 10; i++)
	{
		std::stringstream ss;
		ss << "start " << i << "thread " << id;
		log.Log(ss.str());
	}
}
int main()
{
	MyLog log;

	std::thread th(SendMsg, 0, std::ref(log));

}

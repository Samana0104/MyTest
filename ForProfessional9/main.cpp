#include <iostream>
#include <string>
#include <queue>
#include <format>
using namespace std;

class Error final
{
private:
	int m_priority;
	string m_errorString;

public:
	Error(int priority, string errorString)
		: m_priority(priority), m_errorString(move(errorString))
	{ }

	int getPriority() const
	{
		return m_priority;
	}

	const string& getErrorString() const
	{
		return m_errorString;
	}

	auto operator<=>(const Error& rhs) const
	{
		return getPriority() <=> rhs.getPriority();
	}
};

ostream& operator<<(ostream& os, const Error& err)
{
	os << std::format("{} (priority {})", err.getErrorString(), err.getPriority());
	return os;
}

class ErrorCorrelator final
{
private:
	priority_queue<Error> m_errors;
public:
	void addError(const Error& error)
	{
		m_errors.push(error);
	}

	[[nodiscard]] Error getError()
	{
		if (m_errors.empty())
		{
			throw std::out_of_range("No more errors.");
		}

		Error top(m_errors.top());
		m_errors.pop();
		return top;
	}
};

int main()
{
	ErrorCorrelator ec;
	ec.addError(Error(3, "Unable to read file"));
	ec.addError(Error(1, "Incorrect entry from user"));
	ec.addError(Error(10, "Unable to allocate memory!"));

	while (true)
	{
		try
		{
			Error e(ec.getError());
			cout << e << endl;
		}
		catch(const out_of_range&)
		{
			cout << "Finished processing errors" << endl;
			break;
		}
	}
}

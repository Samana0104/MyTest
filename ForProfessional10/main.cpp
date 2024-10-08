#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <string_view>
#include <initializer_list>
using namespace std;

class AccessList
{
private:
	std::set<std::string> m_allowed;

public:
	AccessList() = default;
	AccessList(std::initializer_list<std::string_view> users)
	{
		m_allowed.insert(begin(users), end(users));
	}

	void AddUser(std::string user)
	{
		m_allowed.emplace(std::move(user));
	}

	void RemoveUser(const std::string& user)
	{
		m_allowed.erase(user);
	}

	bool isAllowed(const std::string& user) const
	{
		return (m_allowed.contains(user) != 0);
	}

	std::vector<std::string> GetAllUsers() const
	{
		return { begin(m_allowed), end(m_allowed) };
	}
};


int main()
{
	AccessList fileX{ "mgregoire", "baduser" };
	fileX.AddUser("pvw");
	fileX.RemoveUser("baduser");

	if (fileX.isAllowed("mgregoire"))
		cout << "mgregoire has permissions" << endl;
}

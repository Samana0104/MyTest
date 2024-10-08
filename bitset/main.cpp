#include <iostream>
#include <bitset>
#include <string>
#include <string_view>
#include <map>
using namespace std;

class CableCompany final
{
private:
	static const size_t NumChannels{ 10 };
	using MapType = map<string, bitset<NumChannels>>;

	MapType m_packages, m_customers;
	bitset<NumChannels>& getCustomerChannelsHelper(string_view name);
public:
	
	void addPackage(string_view packageName, const bitset<NumChannels>& channels);
	void removePackage(string_view packageName);
	const bitset<NumChannels>& getPackage(string_view packageName) const;

	void newCustomer(string_view name, string_view package);
	void newCustomer(string_view name, const bitset<NumChannels>& channels);

	void addChannel(string_view name, int channel);
	void removeChannel(string_view name, int channel);

	void addPackageToCustomer(string_view name, string_view package);
	void deleteCustomer(string_view name);

	const bitset<NumChannels>& getCustomerChannels(string_view name) const;
	
};

int main()
{
	bitset<10> myBitset;
	
	myBitset.set(3);
	myBitset.set(6);
	myBitset[8] = true;
	myBitset[9] = myBitset[3];

	if (myBitset.test(3))
		cout << "Bit 3 is set!" << endl;

	cout << myBitset << endl;
	
	auto str1("0011001100");
	auto str2("0000111100");

	bitset<10> bitsOne(str1);
	bitset<10> bitsTwo(str2);
	
	auto bitsThree(bitsOne & bitsTwo);
	cout << bitsThree << endl;
	bitsThree <<= 4;
	cout << bitsThree << endl;
	return 0;
}


void CableCompany::addPackage(string_view packageName, const bitset<NumChannels>& channels)
{
	m_packages.emplace(packageName, channels);
}

void CableCompany::removePackage(string_view packageName)
{
}

const bitset<CableCompany::NumChannels>& CableCompany::getPackage(string_view packageName) const
{
	// TODO: insert return statement here
}

void CableCompany::newCustomer(string_view name, string_view package)
{
}

void CableCompany::newCustomer(string_view name, const bitset<NumChannels>& channels)
{
}

void CableCompany::addChannel(string_view name, int channel)
{
}

void CableCompany::removeChannel(string_view name, int channel)
{
}

void CableCompany::addPackageToCustomer(string_view name, string_view package)
{
}

void CableCompany::deleteCustomer(string_view name)
{
}

const bitset<CableCompany::NumChannels>& CableCompany::getCustomerChannels(string_view name) const
{
	// TODO: insert return statement here
}

bitset<CableCompany::NumChannels>& CableCompany::getCustomerChannelsHelper(string_view name)
{
}

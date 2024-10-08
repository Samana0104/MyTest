#include <iostream>
#include <filesystem>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
using namespace std::filesystem;

int main()
{
	space_info s(space("C:\\"));
	cout << s.capacity << endl;
	cout << s.free << endl;
	return 0;
}

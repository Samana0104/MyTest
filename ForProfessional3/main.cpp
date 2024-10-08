#include <iostream>
#include <string_view>
#include <string>
#include <source_location>
#include <format>
using namespace std;

void logMessage(string_view msg, const source_location& location = source_location::current())
{
	cout << format("{}({}): {}: {}", location.file_name(),
		location.line(), location.function_name(), msg) << endl;

}
int main()
{
	logMessage("Å×½ºÆ®");

	return 0;
}

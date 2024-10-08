#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
namespace fs = std::filesystem;

void test(const std::string path)
{
	fs::directory_iterator itr(path);

	while (itr != fs::end(itr))
	{
		const fs::directory_entry& entry = *(itr++);
		std::cout << entry.path() << entry.is_directory() << std::endl;
		if (entry.is_directory())
		{
			test(entry.path().string());
		}
	}
}

class C
{
private:

public:
	C()
	{
		std::cout << "클래스 생성" << std::endl;
	}

	~C()
	{
		std::cout << "클래스 해제" << std::endl;
	}
};

void F()
{
	std::vector<C*> a;

	a.push_back(new C);
	a.push_back(new C);
	a.push_back(new C);
	delete a[0];
	delete a[1];
	delete a[2];
}

int main()
{
	F();
	return 0;
}
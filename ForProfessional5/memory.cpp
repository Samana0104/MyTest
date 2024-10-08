#include <iostream>
using namespace std;

class MemoryDemo
{
public:
	virtual ~MemoryDemo() = default;

	void* operator new(size_t size);
	void operator delete(void* ptr) noexcept;
	
	void* operator new[](size_t size);
	void operator delete[](void* ptr) noexcept;

	void* operator new(size_t size, const std::nothrow_t&) noexcept;
	void operator delete(void* ptr, const std::nothrow_t&) noexcept;

	void* operator new[](size_t size, const std::nothrow_t&) noexcept;
	void operator delete[](void* ptr, const std::nothrow_t&) noexcept;
};

void* MemoryDemo::operator new(size_t size)
{
	cout << "operator new" << endl;
	return ::operator new(size);
}

void MemoryDemo::operator delete(void* ptr) noexcept
{
	cout << "operator delete" << endl;
	::operator delete(ptr);
}

void* MemoryDemo::operator new[](size_t size)
{
	cout << "operator new[]" << endl;
	return ::operator new[](size);
}

void MemoryDemo::operator delete[](void* ptr) noexcept
{
	cout << "operator delete[]" << endl;
	::operator delete[](ptr);
}

void* MemoryDemo::operator new(size_t size, const std::nothrow_t&) noexcept
{
	cout << "operator new nothrow" << endl;
	return ::operator new(size, nothrow);
}

void MemoryDemo::operator delete(void* ptr, const std::nothrow_t&) noexcept
{
	cout << "operator delete nothrow" << endl;
	::operator delete(ptr, nothrow);
}

void* MemoryDemo::operator new[](size_t size, const std::nothrow_t&) noexcept
{
	cout << "operator new[] nothrow" << endl;
	return ::operator new[](size, nothrow);
}

void MemoryDemo::operator delete[](void* ptr, const std::nothrow_t&) noexcept
{
	cout << "operator delete[] nothrow" << endl;
	::operator delete[](ptr, nothrow);
}

int main()
{
	MemoryDemo* mem = new MemoryDemo();
	delete mem;

	mem = new MemoryDemo[10];
	delete[] mem;

	mem = new(nothrow)MemoryDemo();
	delete mem;

	mem = new(nothrow)MemoryDemo[10];
	delete[] mem;

	return 0;
}

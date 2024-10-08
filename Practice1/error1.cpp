#include <iostream>
#include <array>
using namespace std;

int main()
{
	std::array<int, 3> values = { 11, 22, 33 };

	auto [x, y, z] = values;

	cout << x << y << z << endl;
	struct Point { double mX, mY, mZ; };
	Point point;
	point.mX = 1.0; point.mY = 2.0; point.mZ = 3.0;
	auto [x, y, z] = point;
	cout << x << y << z << endl;
// 초기화만 구조적 바인딩 가능함
// 해당 예제처럼 구조적 바인딩이 두 번 나오면 이미 변수가 선언되었기에 에러가 나옴
	return 0;
}
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
// �ʱ�ȭ�� ������ ���ε� ������
// �ش� ����ó�� ������ ���ε��� �� �� ������ �̹� ������ ����Ǿ��⿡ ������ ����
	return 0;
}
#include <iostream>
#include <DirectXMath.h>
#include <directxtk\SimpleMath.h>
using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

int main()
{
	float ptCursorX = ((2.f * -122) / 1008) - 1;
	float ptCursorY = -(((2.f * 224) / 539) - 1);
	float z = 1.f;

	Matrix mat(1.29f, 0.f, 0.f, 0.f, 0.f, 2.41f, 0.f, 0.f, 0.f, 0.f, 1.0001f, 1.f, 0.f, 0.f, -1.0001f, 0.f);
	Vector4 vec = { ptCursorX, ptCursorY, z, 1.f };
	mat = mat.Invert();
	Vector4 test = Vector4::Transform(vec, mat);


	return 0;
}
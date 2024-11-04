#include <iostream>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
using namespace std;

int main()
{
	glm::mat3x3 mat3 = { 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f };
	/*
	1 4 7 column major
	2 5 8
	3 6 9
	*/
	glm::mat4x4 mat4 = { 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f,
		10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f };
	/*
	1 5 9 13
	2 6 10 14
	3 7 11 15
	4 8 12 16
	*/
	glm::mat4 identity(1.f);
	/*
	1 0 0 0
	0 1 0 0
	0 0 1 0
	0 0 0 1

	물론 glm::identity 함수 방법도 있음
	*/
	glm::vec4 vec4 = { 1.f, 2.f, 3.f, 1.f };
	glm::vec3 vec3 = { 1.f, 2.f, 3.f };
	auto vec = mat4 * vec4;
	glm::translate(mat4, vec3); // 이런식으로 mat4x4 * vec3 곱하기 가능

	cout << "mat4 * vec4 : " << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << endl;
	auto matTranspose = glm::transpose(mat4);

	cout << "Not Transposed : " << endl;
	cout << mat4[0][0] << ", " << mat4[1][0] << ", " << mat4[2][0] << ", " << mat4[3][0] << endl;
	cout << mat4[0][1] << ", " << mat4[1][1] << ", " << mat4[2][1] << ", " << mat4[3][1] << endl;
	cout << mat4[0][2] << ", " << mat4[1][2] << ", " << mat4[2][2] << ", " << mat4[3][2] << endl;
	cout << mat4[0][2] << ", " << mat4[1][3] << ", " << mat4[2][3] << ", " << mat4[3][3] << endl;

	cout << "Transposed : " << endl;
	cout << matTranspose[0][0] << ", " << matTranspose[1][0] << ", " << matTranspose[2][0] << ", " << matTranspose[3][0] << endl;
	cout << matTranspose[0][1] << ", " << matTranspose[1][1] << ", " << matTranspose[2][1] << ", " << matTranspose[3][1] << endl;
	cout << matTranspose[0][2] << ", " << matTranspose[1][2] << ", " << matTranspose[2][2] << ", " << matTranspose[3][2] << endl;
	cout << matTranspose[0][2] << ", " << matTranspose[1][3] << ", " << matTranspose[2][3] << ", " << matTranspose[3][3] << endl;

	return 0;
}
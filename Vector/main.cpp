#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace std;

int main()
{
	glm::vec3 v1(1.f, 1.f, 1.f);
	glm::vec3 v2(2.f, 0.f, 1.f);
	glm::vec3 v3 = v1 + v2; // glm은 이런식으로 연산자 오버로딩이 지원된다.
	glm::vec3 v4 = v1 * v2;
	glm::vec3 v5 = (glm::ivec3)v1 ^ (glm::ivec3)v2; // ivec을 붙힌 이유는 실수형에서는 에러가 남
	glm::vec3 v6 = v1++;
	glm::vec3 v7 = v1 / v2; // [1 / 0]의 처리 결과는 ?
	glm::vec3 v8 = glm::cross(v1, v2);
	glm::vec3 v9 = glm::normalize(v1);

	cout << "V1 + V2 dimension : " << (v1 + v2).length() << endl; // 길이 아님 벡터의 차원임
	cout << "V3(v1+v2) : " << v3.x << ", " << v3.y << ", " << v3.z << endl;
	cout << "V4(v1*v2) : " << v4.x << ", " << v4.y << ", " << v4.z << endl;
	cout << "V4(v1*v2) length: " << glm::length(v4) << endl; // glm::length 함수는 벡터의 길이를 구한다.
	cout << "V5(v1^v2) : " << v5.x << ", " << v5.y << ", " << v5.z << endl;
	cout << "V6(v1++) : " << v6.x << ", " << v6.y << ", " << v6.z << endl;
	cout << "V7(v1/v2) : " << v7.x << ", " << v7.y << ", " << v7.z << endl;
	cout << "V8(V1 cross dot V2) : " << v8.x << ", " << v8.y << ", " << v8.z << endl; // 외적 
	cout << "V1 dot V2 : " << glm::dot(v1, v2) << endl; // 내적
	cout << "V9(v1 normalized) : " << v9.x << ", " << v9.y << ", " << v9.z << endl;

	return 0;
}
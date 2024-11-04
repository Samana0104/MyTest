#include <iostream>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/ext/quaternion_float.hpp>
#include <glm/ext/quaternion_common.hpp>
#include <glm/ext/quaternion_transform.hpp>
#include <glm/ext/quaternion_geometric.hpp>
#include <glm/ext/quaternion_trigonometric.hpp>
#include <glm/ext/quaternion_exponential.hpp>
using namespace std;

int main()
{
	glm::quat qt(1.f, 1.f, 2.f, 3.f);
	// 실수부 : 1.f, 허수부 : { 1.f, 2.f, 3.f }
	glm::quat qt2(0.f, 2.f, 3.f, 4.f);

	auto qt3 = qt * qt2;

	// qua<T, Q> rotate(qua<T, Q> const& q, T const& angle, vec<3, T, Q> const& v)
	// 위에 헤더파일 잘 선언하면 이런식으로 쿼터니언을 통해 회전 가능

	cout << "qt * qt2 : " << qt3.x << ", " << qt3.y << ", " << qt3.z << ", " << "w : " << qt3.w;
	return 0;
}
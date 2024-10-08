#include <DirectXMath.h>
#include <glm/glm.hpp>
#include <iostream>
#include <chrono>
#pragma comment(lib, "glm/glm.lib")

using namespace DirectX;

// 반복 횟수 설정
const int ITERATIONS = 100000000;

void testDirectXMath() {
	XMVECTOR v1 = XMVectorSet(1.0f, 2.0f, 3.0f, 4.0f);
	XMVECTOR v2 = XMVectorSet(5.0f, 6.0f, 7.0f, 8.0f);
	XMVECTOR result;

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < ITERATIONS; ++i) {
		result = XMVectorAdd(v1, v2);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;
	std::cout << "DirectXMath: " << duration.count() << " seconds" << std::endl;
}

void testGLM() {
	glm::vec4 v1(1.0f, 2.0f, 3.0f, 4.0f);
	glm::vec4 v2(5.0f, 6.0f, 7.0f, 8.0f);
	glm::vec4 result;

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < ITERATIONS; ++i) {
		result = v1 + v2;
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;
	std::cout << "GLM: " << duration.count() << " seconds" << std::endl;
}

int main() {
	testDirectXMath();
	testGLM();
	return 0;
}
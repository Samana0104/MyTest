#include <iostream>
#include <glm/glm.hpp>
#include <glm/ext.hpp> // perspective translate rotate
#include <glm/gtc/matrix_transform.hpp>
using namespace std;

int main()
{
	// 기본적인 TRS(translate, rotation, scale)
	//glm::mat4 Proj = glm::perspective(glm::radians(45.f), 1.33f, 0.1f, 10.f);
	//glm::mat4 Ortho = glm::ortho(float left, float right, float bottom, float top);
	//glm::mat4 ViewTranslate = glm::translate(glm::mat4(1.f), Translate);
	//glm::mat4 ViewRotateX = glm::rotate(ViewTranslate, Orientation.y, Up);
	//glm::mat4 View = glm::rotate(ViewRotateX, Orientation.x, Up);
	//glm::mat4 Model = glm::mat4(1.0f);
	//return Proj * View * Model;

	//glm::mat4 glm::lookAt(glm::vec3 const& eye, glm::vec3 const& center, glm::vec3 const& up);
	//glm::dmat4 glm::lookAt(glm::dvec3 const& eye, glm::dvec3 const& center, glm::dvec3 const& up);


}
#include "Screen.h"

 namespace GEngine
{
	int Screen::getResX()
	{
		return resX;
	}

	int Screen::getResY()
	{
		return resY;
	}
	glm::mat4 Screen::getProjectionMatrix()
	{
		projectionMatrix = glm::perspective(
			glm::radians(90.0f), // fov
			(float)resX / (float)resY, // ratio
			0.1f, 100.0f);//display range, <0.1 & >100 will not be visible; 

		return projectionMatrix;
	}
	//x and y are required to create the projection matrix. even though using glm::perspective.
}

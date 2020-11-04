#include "Transform.h"
#

namespace GEngine
{
	void Transform::onInitialize()
	{
		modelMatrix = glm::mat4(1.0f); // identiy matrix.
		pos = glm::vec3(0.f);
		rotAngle = 1.f;
		rotAxis = glm::vec3(0.f, 1.f, 0.f);
		scale = glm::vec3(1.f);
	}
	glm::mat4 Transform::getModelMatrix()
	{
		modelMatrix = glm::translate(modelMatrix, pos); // 
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotAngle), rotAxis); // must be in radians
		modelMatrix = glm::scale(modelMatrix, scale);

	// DO NOT CHANGE THE ORDER, IT VIL FUCK UP.

		return modelMatrix;
	}
}
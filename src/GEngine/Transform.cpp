#include "Transform.h"

namespace GEngine
{
	void Transform::onInitialize()
	{
		modelMatrix = glm::mat4(1.0f); // identiy matrix.
		pos = glm::vec3(0.001f, 0.f, -1.1f);
		rotAngle = 0.f;
		rotAxis = glm::vec3(0.f, 1.f, 0.f);
		scale = glm::vec3(1.f);
	}
	void Transform::setRotAngle(float _rotAngle)
	{
		rotAngle = _rotAngle;
	}
	void Transform::setRotAxis(glm::vec3 _rotAxis)
	{
		rotAxis = _rotAxis;
	}
	void Transform::setScale(glm::vec3 _scale)
	{
		scale = _scale;
	}
	void Transform::setPos(glm::vec3 _Pos)
	{
		pos = _Pos;
		modelMatrix = glm::translate(modelMatrix, pos);

	}
	void Transform::setModelMatrix(glm::mat4 _modelMatrix)
	{
		modelMatrix = _modelMatrix;
	}
	float Transform::getrotAngle()
	{
		return rotAngle;
	}
	glm::vec3 Transform::getRotAxis()
	{
		return rotAxis;
	}
	glm::vec3 Transform::getScale()
	{
		return scale;
	}
	glm::vec3 Transform::getPos()
	{
		return pos;
	}
	glm::mat4 Transform::getModelMatrix()
	{
		modelMatrix = glm::translate(modelMatrix, glm::vec3(0,0,0));
		modelMatrix = glm::rotate(modelMatrix, glm::radians(rotAngle), rotAxis); // must be in radians
		modelMatrix = glm::scale(modelMatrix, scale);

	// DO NOT CHANGE THE ORDER

		return modelMatrix;
	}
}
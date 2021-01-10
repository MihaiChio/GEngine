#include "Renderer.h"
#include "Core.h"
#include "Entity.h"
#include "Exception.h"
#include "Model.h"
#include "Shader.h"

#include <iostream>
#include <fstream>

namespace GEngine
{

	void Renderer::onInitialize()
	{
		std::cout << "Initializing" << std::endl;

		shader = getCore()->context->createShader();
		std::shared_ptr<Shader> shaderFile = getCore()->getAM()->load<Shader>("../shaders/shader.frag");
		shader = shaderFile->getShader();

		shape = getCore()->context->createMesh();
		std::shared_ptr<Model> object = getCore()->getAM()->load<Model>("../curuthers/curuthers");
		shape = object->getMesh();
		//Creates Object.
		//TODO  - move shader and model into their own loader.
	}

	void Renderer::onRender()
	{
		shader->setMesh(shape);
		shader->setUniform("in_Model", getModelMatrix()); //getModelMatrix is a shortcut function defined in component.
		shader->setUniform("in_Projection", getProjectionMatrix()); //shortcuts needed.
		shader->render();
	}


}
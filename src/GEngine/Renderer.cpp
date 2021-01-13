#include "Renderer.h"
#include "Core.h"
#include "Entity.h"
#include "Exception.h"
#include "Model.h"
#include "Shader.h"
#include "TextureMe.h"

#include <iostream>
#include <fstream>

namespace GEngine
{
	void Renderer::onInitialize(const std::string _pathToModel, const std::string _pathToTexture) // path to texture has to contain .type.
	{

		shader = getCore()->context->createShader();
		std::shared_ptr<Shader> shaderFile = getCore()->getAM()->load<Shader>("../shaders/shader.frag");
		shader = shaderFile->getShader();

		shape = getCore()->context->createMesh();
		std::shared_ptr<Model> object = getCore()->getAM()->load<Model>(_pathToModel);
		shape = object->getMesh();


		//wip
		std::shared_ptr<TextureMe> myTex = getCore()->getAM()->load<TextureMe>(_pathToTexture);
		std::shared_ptr<rend::Texture> rendTex = std::make_shared<rend::Texture>(); 
		//HAS TO BE INSTANTIATED (CLASS).
		rendTex->setId(myTex->getTextureId());
		shape->setTexture("in_Texture", rendTex);
		//Creates Object.
		//TODO  - Create a texture loader.
	}

	void Renderer::onRender()
	{
		shader->setMesh(shape);
		shader->setUniform("in_Model", getModelMatrix()); //getModelMatrix is a shortcut function defined in component.
		shader->setUniform("in_Projection", getProjectionMatrix()); //shortcuts needed.
		shader->render();
	}


}
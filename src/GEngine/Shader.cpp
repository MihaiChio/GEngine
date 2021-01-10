#include "Shader.h"
#include "Exception.h"
#include "AssetManager.h"
#include "Core.h"

#include <iostream>
#include <fstream>

namespace GEngine
{
	void Shader::onLoad(const std::string _path)
	{
		shader = getAM().lock()->getCore()->context->createShader();
		//creating the shader from the core context.

		std::ifstream file(_path);
		if (!file.is_open())
		{
			throw Exception::Exception("Shader not found");
		}

		while (!file.eof())
		{
			std::getline(file, line);
			content += line + "\n";
		}

		shader->parse(content);
	}

	std::shared_ptr<rend::Shader> Shader::getShader()
	{
		return shader;
	}
}
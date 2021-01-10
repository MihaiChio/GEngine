#include "Model.h"
#include "Exception.h"
#include "AssetManager.h"
#include "Core.h"

#include <iostream>
#include <fstream>

namespace GEngine
{
	void Model::onLoad(const std::string _path)
	{
		mesh = getAM().lock()->getCore()->context->createMesh();

		std::ifstream file(_path + ".obj");
		if (!file.is_open())
		{
			throw Exception::Exception("Model not found");
		}

		while (!file.eof())
		{
			std::getline(file, line);

			content += line + "\n"; // without the New line the loader won't know how to properly render the model.
		}
		//reads file

		mesh->parse(content);
		//creating the model.
	}
	std::shared_ptr<rend::Mesh> Model::getMesh()
	{
		return mesh;
	}
}

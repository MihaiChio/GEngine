#include "Renderer.h"
#include "Core.h"
#include "Entity.h"

#include <iostream>
#include <fstream>

namespace GEngine
{

	void Renderer::onInitialize()
	{
		std::cout << "Initializing" << std::endl;

		const char* src =
			"\n#ifdef VERTEX\n                       " \
			"uniform mat4 in_Projection;			 " \
			"uniform mat4 in_Model;					 " \
			"										 " \
			"attribute vec2 a_TexCoord;				 " \
			"attribute vec3 a_Position;              " \
			"attribute vec3 a_Normal;				 " \
			"varying vec2 v_TexCoord;				 " \
			"                                        " \
			"void main()                             " \
			"{                                       " \
			"  gl_Position = in_Projection * in_Model * vec4(a_Position, 1); " \
			"  v_TexCoord = a_TexCoord;				 " \
			"  if(a_Normal.x == 9) gl_Position.x = 7;" \
			"}                                       " \
			"                                        " \
			"\n#endif\n                              " \
			"\n#ifdef FRAGMENT\n                     " \
			"                                        " \
			"varying vec2 v_TexCoord;				 " \
			"void main()                             " \
			"{                                       " \
			"  gl_FragColor = vec4(v_TexCoord, 0, 1);    " \
			"}                                       " \
			"                                        " \
			"\n#endif\n                              ";

		shader = getCore()->context->createShader();  // shaders the context variable from core and uses the createShader()
		
		shader->parse(src);

		shape = getCore()->context->createMesh();

		std::ifstream file("../curuthers/curuthers.obj");
		if (!file.is_open())
		{
			throw rend::Exception("Failed to find file");
		}

		std::string content;
		std::string line; // expensive if left in a while loop.
		while (!file.eof())
		{
			std::getline(file, line);

			content += line + "\n"; // without the New line the loader won't know how to properly render the model.
		}

		shape->parse(content); //takes the data from the file not the path.

	}

	void Renderer::onRender()
	{
		shader->setMesh(shape);
		shader->setUniform("in_Model", getModelMatrix()); //getModelMatrix is a shortcut function defined in component.
		shader->setUniform("in_Projection", getProjectionMatrix()); //shortcuts needed.
		shader->render();
	}


}
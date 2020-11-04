#include "Renderer.h"
#include "Core.h"
#include "Entity.h"

#include <iostream>

namespace GEngine
{

	void Renderer::onInitialize()
	{
		std::cout << "Initializing" << std::endl;

		const char* src =
			"\n#ifdef VERTEX\n                       " \
			"uniform mat4 in_Projection;			 " \
			"uniform mat4 in_Model;					 " \
			"attribute vec3 a_Position;              " \
			"                                        " \
			"void main()                             " \
			"{                                       " \
			"  gl_Position = in_Projection * in_Model * vec4(a_Position, 1); " \
			"}                                       " \
			"                                        " \
			"\n#endif\n                              " \
			"\n#ifdef FRAGMENT\n                     " \
			"                                        " \
			"void main()                             " \
			"{                                       " \
			"  gl_FragColor = vec4(1, 0, 0, 1);      " \
			"}                                       " \
			"                                        " \
			"\n#endif\n                              ";

		shader = getCore()->context->createShader();  // shaders the context variable from core and uses the createShader()
		shader->parse(src);

		shape = getCore()->context->createBuffer();
		shape->add(rend::vec3(0.f, 0.5f,-2.f));
		shape->add(rend::vec3(-0.5f, -0.5f, -2.f));
		shape->add(rend::vec3(0.5f, -0.5f, -2.f));
	}

	void Renderer::onRender()
	{
		shader->setAttribute("a_Position", shape);
		shader->setUniform("in_Model", getEntity()->getComponent<Transform>()->getModelMatrix());
		shader->setUniform("in_Projection", getEntity()->getCore()->getScreen()->getProjectionMatrix());
		shader->render();
	}

}
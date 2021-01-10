#include <string>
#include <iostream>
#include "Resource.h"
#include "rend/rend.h"

namespace GEngine
{
	struct Renderer;

	struct Shader : public Resource
	{
		void onLoad(const std::string _path);
		std::shared_ptr<rend::Shader> getShader();

	private:
		std::string content;
		std::string line;
		std::shared_ptr<rend::Shader> shader;
	};
}
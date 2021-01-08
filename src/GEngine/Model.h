#include <string>
#include <iostream>
#include "Resource.h"
#include "rend/rend.h"

namespace GEngine
{
	struct Renderer;

	struct Model : public Resource
	{
		void onLoad(const std::string _path );
		std::shared_ptr<rend::Mesh> getMesh();
	private:
		std::string content;
		std::string line;
		std::shared_ptr<rend::Mesh> mesh;
	};
}
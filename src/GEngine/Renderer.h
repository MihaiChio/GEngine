#include "Component.h"
#include <rend/rend.h>
#include <memory>


namespace GEngine
{

	struct Renderer : public Component
	{
		Renderer() {};

		void onInitialize(const std::string _pathToModel, const std::string _pathToTexture);
		void onRender();

	private:
		std::shared_ptr<rend::Shader> shader;
		std::shared_ptr<rend::Mesh> shape;

	};

}
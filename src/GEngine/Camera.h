#include "Component.h"

#include <rend/rend.h>

namespace GEngine
{
	struct Camera : public Component
	{
		void onInitialize();

		rend::mat4 getView();
		//getRenderTex
		//AddRenderTex


	private:
		std::shared_ptr<rend::RenderTexture> rendTexture;
	};

}

#include "Component.h"
#include <rend/rend.h>

namespace GEngine
{
	struct Camera : public Component
	{
		void onInitialize();
		rend::mat4 getView();


	private:
		std::shared_ptr<rend::RenderTexture> rendTexture;
		std::shared_ptr<Component> object; // might add this maybe mayvbe x2

	};

}


#include <string>
#include "Resource.h"

namespace GEngine
{
	struct TextureMe : public Resource
	{
		void onLoad(const std::string _path);
		void loadTex(const std::string _path);
		unsigned int getTextureId();
		
	private:
		int w = 0;
		int h = 0;
		int channels = 0;
		unsigned char* data;
		unsigned int textureId = 0;
	};
}
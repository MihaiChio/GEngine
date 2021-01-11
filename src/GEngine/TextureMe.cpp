#
#include "TextureMe.h"
#include "Core.h"
#include "Exception.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb-master/stb_image.h>

namespace GEngine
{
	void TextureMe::onLoad(const std::string _path)
	{
		loadTex(_path);
	}
	void TextureMe::loadTex(const std::string _path)
	{
		glGenTextures(1, &textureId);
		glBindTexture(GL_TEXTURE_2D, textureId);

		//setting filtering options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//loading texture
		data = stbi_load(_path.c_str(), &w, &h, &channels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			throw Exception::Exception("Texture not loaded");
		}
		stbi_image_free(data);
	}
	GLuint TextureMe::getTextureId()
	{
		return textureId;
	}
}
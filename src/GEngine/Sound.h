#include <string>
#include <openal-soft/include/al.h>
#include <vector>
#include "Resource.h"

namespace GEngine
{
	struct Sound : public Resource
	{
		ALuint getID();
		void onLoad(const std::string _path);
		void loadOgg(const std::string& _fileName, std::vector<char> &buffer, ALenum &format, ALsizei &freq);
	private:
		ALuint s_id = 0;
	};
}
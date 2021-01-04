#include "Component.h"
#include <openal-soft/include/al.h>
#include <string>
#include "Sound.h"

namespace GEngine
{
	struct soundSource : public Component
	{
		void onInitialize(const std::string _path);
		void onTick();

	private:
		ALuint soundID;		
	};
}
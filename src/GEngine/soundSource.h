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
		void playSound();
		void deleteSound();
		bool isPlaying();

	private:
		float x, y, z = 0;
		ALuint soundID;		
		ALfloat listenerPos[3] = { x,y,z };
	};
	//TODO -> Try to add positional sound
	//TODO -> Try to add Textures
}
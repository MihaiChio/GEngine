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
		ALuint soundID;		
	};
}
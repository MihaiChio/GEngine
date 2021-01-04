
#include "Entity.h"
#include "Core.h"
#include "soundSource.h"



namespace GEngine
{
	void soundSource::onInitialize(const std::string _path)
	{
		std::shared_ptr<Sound> sound = getEntity()->getCore()->getAM()->load<Sound>(_path); //
	
		alGenSources(1, &soundID);
		alSourcei(soundID, AL_BUFFER, sound->getID());
		alSourcePlay(soundID);
	}

	void soundSource::onTick()
	{
		ALint state = 0;

		//Delete stuff if not used anymore .
		//TODO IMPLEMENT DELETE
	}
}



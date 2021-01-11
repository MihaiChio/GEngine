
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
		//alSourcePlay(soundID);
	}

	void soundSource::onTick()
	{
		ALint state = 0;

		//Delete stuff if not used anymore.
	}
	void soundSource::playSound()
	{
		alListenerfv(AL_POSITION, listenerPos);
		if(!isPlaying())
		{
			alSourcePlay(soundID);
			
		}
	}
	//todo Delete, Play, 
	bool soundSource::isPlaying()
	{
		ALenum state = 0;
		alGetSourcei(soundID, AL_SOURCE_STATE, &state);
		return(state == AL_PLAYING);
	}

	void soundSource::setX(float _xPosAudio)
	{
		z += _xPosAudio;
	}

	void soundSource::deleteSound()
	{
		alDeleteSources(1, &soundID);
	}



}



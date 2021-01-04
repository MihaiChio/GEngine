#include "Sound.h"
#include <openal-soft/stb_vorbis.h>

namespace GEngine
{
	ALuint Sound::getID()
	{
		return s_id;
	}
	void Sound::onLoad(const std::string _path)
	{
		alGenBuffers(1, &s_id);

		ALenum format = 0; 
		ALsizei freq = 0;
		std::vector<char> bufferData;

		
		loadOgg(_path + ".ogg", bufferData, format, freq); // loading and decoding the file.

		alBufferData(s_id, format, &bufferData[0], static_cast<ALsizei>(bufferData.size()), freq); // add it to the buffer.


	}
	void Sound::loadOgg(const std::string& _fileName, std::vector<char>& buffer, ALenum& format, ALsizei& freq)
	{
		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;

		size_t samples = stb_vorbis_decode_filename(_fileName.c_str(), &channels, &sampleRate, &output);
		if (samples == -1)
		{
			//implemenet exception - failed to open file + _filename + for decoding
		}
		//channels format.

		if (channels == 1)
		{
			format = AL_FORMAT_MONO16;
		}
		else
		{
			format = AL_FORMAT_MONO16;
		}

		//sample rate.

		freq = sampleRate;

		buffer.resize(samples * 2);
		memcpy(&buffer.at(0), output, buffer.size());

		//cleaning up.
		free(output);
	}
}

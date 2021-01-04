#include <memory>
#include <vector>

#include <rend/rend.h>
#include <SDL.h>
#include <openal-soft/include/al.h>
#include <openal-soft/include/alc.h>

#include "AssetManager.h"
#include "Screen.h"
#include "Keyboard.h"

namespace GEngine
{
	struct Transform;
	struct Renderer;
	struct Entity;

	/**
	* Engine base class, essential classes, libraries and resources are linked and executed here.
	*/

	struct Core
	{
		friend struct GEngine::Renderer;
		static std::shared_ptr<Core> initialize();


		std::shared_ptr<Entity> addEntity();
		void initialiseSDL(std::shared_ptr<Core> _rtnu);
		void initializeOpenAL(std::shared_ptr<Core> _rtn); // this will be called in initialize with
		void start();
		void exit();
		std::shared_ptr<Screen> getScreen();
		std::shared_ptr<AssetManager> getAM();
		std::shared_ptr<Keyboard> getKeyboard();
		static void loop();

	private:
		std::shared_ptr<Keyboard> keyB;
		std::shared_ptr<AssetManager> AM;
		std::vector<std::shared_ptr<Entity>> entities; // only needs to know that the "entity" struct exists. HAS TO BE DEFINED BEFORE ACCESSED.
		std::weak_ptr<Core> self;
		SDL_Window* window;
		SDL_GLContext glContext;
		std::shared_ptr<rend::Context> context;
		//private constructors do not allow the user to use new and only allows the class to initialise it.
		std::shared_ptr<Screen> screen;
		//creating the audio variables 
		ALCdevice* device;
		ALCcontext* contextAud;
	};
}
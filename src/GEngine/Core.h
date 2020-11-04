#include <memory>
#include <vector>
#include <rend/rend.h>
#include <SDL.h>
#include "Screen.h"

namespace GEngine
{
	struct Transform;
	struct Renderer;
	struct Entity;

	struct Core
	{
		friend struct GEngine::Renderer;
		static std::shared_ptr<Core> initialize();


		std::shared_ptr<Entity> addEntity();
		void initialiseSDL(std::shared_ptr<Core> _rtnu);
		void start();
		void exit();
		std::shared_ptr<Screen> getScreen();
		static void loop();

	private:
		std::vector<std::shared_ptr<Entity>> entities; // only needs to know that the "entity" struct exists. HAS TO BE DEFINED BEFORE ACCESSED.
		std::weak_ptr<Core> self;
		SDL_Window* window;
		SDL_GLContext glContext;
		std::shared_ptr<rend::Context> context;
		//private constructors do not allow the user to use new and only allows the class to initialise it.
		std::shared_ptr<Screen> screen;
	};
}
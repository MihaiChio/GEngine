#include "Core.h"
#include "Entity.h"

#ifdef EMSCRIPTEN
	#include <emscripten.h>
#endif
namespace GEngine
{
		Core* c;
		std::shared_ptr<Core> Core::initialize()
		{
			
			std::shared_ptr<Core> rtn = std::make_shared<Core>();
			rtn->self = rtn;	// rtn REPRESENTS AN INSTANCE OF CORE.
			rtn->screen = std::make_shared<Screen>();

			rtn->initialiseSDL(rtn);
			return rtn;
		}

		std::shared_ptr<Entity> Core::addEntity()
		{
			std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

			std::shared_ptr<Transform> transComp = rtn->addComponent<Transform>();
			// adding "transComp" to Entity.

			rtn->core = self;
			//This is making sure that THIS core is being used without raw pointers.

			rtn->self = rtn;
			//similar to THIS but with weak pointers.

			entities.push_back(rtn);

			return rtn;
		}

		void Core::initialiseSDL(std::shared_ptr<Core> _rtnu)
		{
			_rtnu -> window = SDL_CreateWindow("G Engine", 
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
				_rtnu->screen->getResX(), _rtnu->screen->getResY(), // Core gets its screen class and the desired propertIES. 
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
			if (!window)
			{
				//Error message
				//Implement exceptions class.
			}


			_rtnu -> glContext = SDL_GL_CreateContext(window);


			_rtnu->context = rend::Context::initialize();
			if (!glContext)
			{
				//Error message
			}

			
		}

		 void Core::loop()
		{
			bool isRunning = true;
			SDL_Event e = { 0 };

			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					isRunning = false;
				}
			}
			for (size_t ei = 0; ei < c->entities.size(); ei++)
			{
				c->entities.at(ei)->tick();
			}
			glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (size_t ei = 0; ei < c->entities.size(); ei++)
			{
				c->entities.at(ei)->render();
			}

			SDL_GL_SwapWindow(c->window);
		}

		void Core::start() // main loop.
		{
			c = this;
			#ifdef EMSCRIPTEN
			
						emscripten_set_main_loop(Core::loop, 0, 1);	
			#else
						while (true)
						{
							loop();
						}
			#endif // EMSCRIPTEN


		}


		 void Core::exit()
		{
			 SDL_GL_DeleteContext(glContext);
			 SDL_DestroyWindow(window);
			 SDL_Quit();
			// TO DO
		}

		 std::shared_ptr<Screen> Core::getScreen()
		 {
			 return screen;
		 }


}
#include "Core.h"
#include "Entity.h"

#ifdef EMSCRIPTEN
	#include <emscripten.h>
#endif
namespace GEngine
{
		std::weak_ptr<Core> _core; // to avoid a loop problem with emscripten.
		std::shared_ptr<Core> Core::initialize()
		{

			std::shared_ptr<Core> rtn = std::make_shared<Core>();
			rtn->self = rtn;	// rtn REPRESENTS AN INSTANCE OF CORE.
			rtn->screen = std::make_shared<Screen>();

			rtn->initialiseSDL(rtn);
			rtn->initializeOpenAL(rtn);
			rtn->AM = std::make_shared<AssetManager>(); //
			rtn->AM->setCore(rtn);
			rtn->AM->setSelf(rtn->AM); // sets asset manager self to the one refered in here.
			rtn->keyB = std::make_shared<Keyboard>();

			_core = rtn;
			return rtn;
		}

			std::shared_ptr<Entity> Core::addEntity()
		{
			std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
			rtn->core = self;
			//This is making sure that THIS core is being used without raw pointers.
			std::shared_ptr<Transform> transComp = rtn->addComponent<Transform>();
			// adding "transComp" to Entity.
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

		void Core::initializeOpenAL(std::shared_ptr<Core> _rtn)
		{
			_rtn->device = alcOpenDevice(NULL);

			if (!_rtn->device)
			{
				throw rend::Exception("No device found");
			}
			_rtn->contextAud = alcCreateContext(_rtn->device, NULL); // select the the preffered device.

			if (!_rtn->contextAud)
			{
				alcCloseDevice(_rtn->device);
			//exception
			}

			if (!alcMakeContextCurrent(_rtn->contextAud))
			{
				alcDestroyContext(_rtn->contextAud);
				alcCloseDevice(_rtn->device);
				//exception
			}

			//has to be closed after use.

			// alcMakeContextCurrent(NULL);
			// alcDestroyContext(context);
			// alcCloseDevice(device);
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
				else if (e.type == SDL_KEYDOWN)
				{
					_core.lock()->keyB->keys.push_back(e.key.keysym.sym);
				}
				else if (e.type == SDL_KEYUP)
				{
					_core.lock()->keyB->removeKey(e.key.keysym.sym);
				}
			}
			for (size_t ei = 0; ei < _core.lock()->entities.size(); ei++)
			{
				_core.lock()->entities.at(ei)->tick();
			}
			glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glViewport(0, 0, _core.lock()->screen->getResX(), _core.lock()->screen->getResY());
			//TODO CAMERA IMPLEMENT
			for (size_t ci = 0; ci < _core.lock()->cameraVec.size(); ci++)
			{
				_core.lock()->curCam = _core.lock()->cameraVec.at(ci);
				glClear(GL_DEPTH_BUFFER_BIT);
				for (size_t ei = 0; ei < _core.lock()->entities.size(); ei++)
				{
					_core.lock()->entities.at(ei)->render();
				}
				glViewport(0, 0, 300, 300);
			}

			SDL_GL_SwapWindow(_core.lock()->window);
		}

		void Core::start() // main loop.
		{
			//c = this;
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
			 return self.lock()->screen;
		 }

		 std::shared_ptr<AssetManager> Core::getAM()
		 {
			 return self.lock()->AM;
		 }

		 std::shared_ptr<Camera> Core::getCam()
		 {
			 return curCam.lock();
		 }

		 std::shared_ptr<Keyboard> Core::getKeyboard()
		 {
			 return self.lock()->keyB;
		 }


}
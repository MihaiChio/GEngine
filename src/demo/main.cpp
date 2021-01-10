#include <GEngine/GEngine.h>
#include <iostream>

using namespace GEngine;

struct player : public Component
{
	void onInitialize(std::string name)
	{
		std::shared_ptr<Renderer> r = getEntity()->addComponent<Renderer>();
	}
	void onTick()
	{
		if (getCore()->getKeyboard()->getKey(SDLK_d))
		{
			std::cout << "Moving Right" << std::endl;
			getEntity()->getComponent<Transform>()->setPos(glm::vec3(-0.1f, 0.f, 0.f));
			
			if (getEntity()->getComponent<soundSource>() != NULL) // checking if the component exists.
			{
				getEntity()->getComponent<soundSource>()->playSound();
			}
		}

		if (getCore()->getKeyboard()->getKey(SDLK_e))
		{
			std::cout << "Rotating right" << std::endl;
			getEntity()->getComponent<Transform>()->setRotAngle(1.f);
			getEntity()->getComponent<Transform>()->setRotAxis(glm::vec3(0.f, 0.1f, 0.f));
			if (getEntity()->getComponent<soundSource>() != NULL) // checking if the component exists.
			{
				getEntity()->getComponent<soundSource>()->deleteSound();

			}
		}
		else if (getCore()->getKeyboard()->getKey(SDLK_q))
		{
			std::cout << "Rotating left" << std::endl;
			getEntity()->getComponent<Transform>()->setRotAngle(1.f);
			getEntity()->getComponent<Transform>()->setRotAxis(glm::vec3(0.f, -0.1f, 0.f));

			//DEBUG TEST
	

		}
		else
		{
			getEntity()->getComponent<Transform>()->setRotAngle(0.f);
		}

	}
};

int main()
{
	try
	{
		std::shared_ptr<Core> core = Core::initialize();

		std::shared_ptr<Entity> pe = core->addEntity();
		std::shared_ptr<player> plo = pe->addComponent<player>("ceausescu");
		std::shared_ptr<soundSource> sc = pe->addComponent<soundSource>("Jump3"); //playing sound

		plo->getEntity()->getComponent<Transform>()->setPos(glm::vec3(1, 0, -5));
		pe->addComponent<Camera>();

		std::shared_ptr<Entity> cam2 = core->addEntity();
		cam2->addComponent<Camera>();



		std::shared_ptr<Entity> r2 = core->addEntity();
		//std::shared_ptr<player> p2 = r2->addComponent<player>("ceau");
		core->start();

		return 0;
	}

		catch(std::exception& ex)
	{
		std::cout << ex.what()<< std::endl;
		return 1;
	}
}
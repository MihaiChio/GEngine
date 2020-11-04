#include <GEngine/GEngine.h>
#include <iostream>

using namespace GEngine;


int main()
{
	try
	{
		std::shared_ptr<Core> core = Core::initialize();
		std::shared_ptr<Entity> pe = core->addEntity();
		std::shared_ptr<Renderer> pc = pe->addComponent<Renderer>();

		core->start();

		return 0;
	}
		catch(std::exception& ex)
	{
		std::cout << ex.what()<< std::endl;
		return 1;
	}
}
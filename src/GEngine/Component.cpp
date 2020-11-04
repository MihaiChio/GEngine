#include "Component.h"
#include "Entity.h"

namespace GEngine
{

	void Component::tick()
	{
		onTick();
	}

	void Component::onTick() {}

	void Component::render()
	{
		onRender();
	}

	void Component::onInitialize() {};
	void Component::onRender() {}
	std::shared_ptr<Entity> Component::getEntity()
	{
		return entity.lock(); // MAKES IT ACT LIKE A SHARE POINTER.
	}

	std::shared_ptr<Core> Component::getCore()
	{
		return getEntity()->getCore(); //kinda shortc
	}

	
}

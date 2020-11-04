#include "Entity.h"
#include "Component.h"


namespace GEngine
{
	void Entity::render()
	{
		for (size_t ci = 0; ci < components.size(); ci++)
		{
			components.at(ci)->render();
		}
	}
	void Entity::tick()
	{
		for (size_t ci = 0; ci < components.size(); ci++)
		{
			components.at(ci)->tick();
		}
	}
	std::shared_ptr<Core> Entity::getCore()
	{
		return core.lock();
	}
}
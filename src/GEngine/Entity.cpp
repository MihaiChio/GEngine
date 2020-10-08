#include "Entity.h"
#include "Component.h"


namespace GEngine
{
	void Entity::tick()
	{
		for (size_t ci = 0; ci < components.size(); ci++)
		{
			//Components.at(ci)->tick;
		}
	}
}
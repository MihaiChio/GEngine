#include <vector>
#include <memory>
#include <string>

#include "Component.h"
#include "Transform.h"

namespace GEngine
{
	struct Component;
	struct Core;
	struct Transform;


	struct Entity
	{
		friend struct GEngine::Core; // added namespace as a safeguard

		
		template <typename T, typename ... Args>
		std::shared_ptr<T> addComponent(Args&&... args)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;

			components.push_back(rtn);

			rtn->onInitialize(std::forward<Args>(args)...); //this on initialize.

			return rtn;
		}
		
		
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;

			components.push_back(rtn);
			
			rtn->onInitialize(); //this on initialize.

			return rtn;
		}

		template <typename T>
		std::shared_ptr<T> addComponent(const std::string& _path)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;

			components.push_back(rtn);

			rtn->onInitialize(_path); //this on initialize.

			return rtn;
		} // this is done to enable the function call with a paramter(from sources).

		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (size_t ci = 0; ci < components.size(); ci++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(components.at(ci)); //component.at(ci) will return the component within the loop.
				//dynamic pointer will try to get a component in rtn. If the same type, rtn won't be null.
				
				//MAYBE - Add exceptions.

				if (rtn)
				{
					return rtn;
				}
				else
				{
					return NULL;
				}

			}
		}
		
		void render();
		void tick();
		
		std::shared_ptr<Core> getCore();

		private:
		std::weak_ptr<Core> core;
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Entity> self;
	};
}
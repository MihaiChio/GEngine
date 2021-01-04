#ifndef GEngine_COMPONENT_H
#define GEngine_COMPONENT_H

#include<memory>
#include "glm/glm.hpp"

namespace GEngine
{
	struct Entity;
	struct Core;

	/**
	* Provides the base class for any component that any object added to Entity will inherit.
	*/

	struct Component
	{
		friend struct GEngine::Entity;

		virtual void onInitialize(); /// Base for each component that will be initialized.
		void tick();
		virtual void onTick();

		void render();
		virtual void onRender();

		std::shared_ptr<Entity> getEntity();
		std::shared_ptr<Core> getCore();
		glm::mat4 getModelMatrix(); // shortcut to the model matrix in transform.
		glm::mat4 getProjectionMatrix(); // shortcut to the projection matrix in screen.

	private:
		std::weak_ptr<Entity> entity;
	};
}


#endif // !GEngine_COMPONENT_H
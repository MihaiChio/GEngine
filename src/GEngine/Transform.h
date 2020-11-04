#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace GEngine
{

		struct Transform : public Component
		{
			void onInitialize();
			
			// TODO SETTERS AND GETTERS FOR EVERYTHING V
			
			glm::mat4 getModelMatrix();
			private:
				glm::vec3 pos;
				glm::vec3 scale;
				glm::vec3 rotAxis;
				float rotAngle;
				glm::mat4 modelMatrix; // model is trasnlation, rotation and scale.
				
		};
	
}
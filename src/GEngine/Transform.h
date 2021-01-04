#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace GEngine
{

		struct Transform : public Component
		{
			void onInitialize();
			
			// TODO SETTERS AND GETTERS FOR EVERYTHING V
			
			void setRotAngle(float _rotAngle);
			void setRotAxis(glm::vec3 _rotAxis);
			void setScale(glm::vec3 _scale);
			void setPos(glm::vec3 _Pos);
			void setModelMatrix(glm::mat4 _modelMatrix);

			float getrotAngle();
			glm::vec3 getRotAxis();	
			glm::vec3 getScale();
			glm::vec3 getPos();
			glm::mat4 getModelMatrix();
			private:
				glm::vec3 pos;
				glm::vec3 scale;
				glm::vec3 rotAxis;
				float rotAngle;
				glm::mat4 modelMatrix; // model is trasnlation, rotation and scale.
				
		};
	
}
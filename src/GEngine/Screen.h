#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace GEngine
{
	struct Screen
	{

		int getResX();
		int getResY();
		glm::mat4 getProjectionMatrix(); // might not be the best option. Ask cosmin later.
	private:
		int resX = 800;
		int resY = 600;
		glm::mat4 projectionMatrix = glm::mat4(1.0f); 
	};
}
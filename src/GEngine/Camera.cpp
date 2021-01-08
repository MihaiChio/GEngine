#include "Camera.h"
#include "Entity.h"
#include "Core.h"

void GEngine::Camera::onInitialize()
{
	std::shared_ptr<Camera> selfRef = getEntity()->getComponent<Camera>();
	getCore()->cameraVec.push_back(selfRef);
	//referecing the component itself to add it to the vector within core.
}

rend::mat4 GEngine::Camera::getView()
{
	return rend::inverse(getModelMatrix());
}

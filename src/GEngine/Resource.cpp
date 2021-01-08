#include "Resource.h"
namespace GEngine
{
	void Resource::load(std::string _path)
	{
		path = _path;
		onLoad(_path);
	}
	void Resource::onLoad(std::string path)
	{
	}
	std::string Resource::getPath()
	{
		return path;
	}
	void Resource::setRes(std::weak_ptr<AssetManager> _resource)
	{
		resources = _resource;
	}
	std::weak_ptr<AssetManager> Resource::getAM()
	{
		return resources;
	}
}
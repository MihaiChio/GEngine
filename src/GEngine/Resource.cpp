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
}
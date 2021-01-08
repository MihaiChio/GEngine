#include <string>
#include "AssetManager.h"

namespace GEngine
{
	struct Resource
	{
		void load(std::string _path);
		virtual void onLoad(std::string path);
		std::string getPath();
		void setRes(std::weak_ptr<AssetManager> _resource);
		std::weak_ptr<AssetManager> getAM();


	private:
		std::string path;
		std::weak_ptr<AssetManager> resources;
	};
}
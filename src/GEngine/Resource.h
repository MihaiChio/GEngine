#include <string>
#include "AssetManager.h"

namespace GEngine
{
	struct Resource
	{
		void load(std::string _path);
		virtual void onLoad(std::string path);
		std::string getPath();



	private:
		std::string path;
		std::weak_ptr<AssetManager> resources;
	};
}
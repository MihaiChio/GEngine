#pragma once
#include <memory>
#include <string>
#include <vector>

namespace GEngine
{
	//Needed for context, has to go through Resources -> AM
	/*Core - > AM
	Context->R->AM->Co
	*/
	struct Resource;
	struct Core;
	struct AssetManager
	{
		template<typename T>
		std::shared_ptr<T> load(std::string _path)
		{
			std::shared_ptr<T> rts = std::make_shared<T>(); // returning the resource that was created.
			rts->setRes(self); // asset manager of the resource being loaded is this.
			rts->load(_path);
			resources.push_back(rts); // adding the source to the list.
			return rts;
		}
		std::shared_ptr<Core> getCore();
		void setCore(std::shared_ptr<Core> _core);
		void setSelf(std::weak_ptr<AssetManager> _am);
	private:
		std::weak_ptr<Core> core;
		std::vector<std::shared_ptr<Resource>> resources; // can't find data type.
		std::weak_ptr<AssetManager> self;
	};
}
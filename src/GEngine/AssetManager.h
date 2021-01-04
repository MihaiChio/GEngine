#pragma once
#include <memory>
#include <string>
#include <vector>

namespace GEngine
{
	struct Resource;
	struct Core;
	struct AssetManager
	{
		template<typename T>
		std::shared_ptr<T> load(std::string _path)
		{
			std::shared_ptr<T> rts = std::make_shared<T>(); // returning the resource that was created.
			rts->load(_path);
			resources.push_back(rts); // adding the source to the list.
			return rts;
		}
	private:
		//std::weak_ptr<Core> core;
		std::vector<std::shared_ptr<Resource>> resources; // can't find data type.
	};
}
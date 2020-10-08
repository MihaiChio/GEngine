#include <memory>
#include <vector>


namespace GEngine
{

	struct Entity;
	struct Core
	{
		static std::shared_ptr<Core> initialize();

		std::shared_ptr<Entity> addEntity();

		void start();

	private:
		std::vector<std::shared_ptr<Entity>> entities; // only needs to know that the "entity" struct exists. HAS TO BE DEFINED BEFORE ACCESSED.

	};
}
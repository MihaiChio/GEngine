#include <vector>


namespace GEngine
{
	struct Core;
	struct Keyboard
	{

		void removeKey(int _key);
		bool getKey(int _key);
	private:
		friend struct GEngine::Core;
		std::vector<int> keys;
	};
}
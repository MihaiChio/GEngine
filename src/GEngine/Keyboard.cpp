#include "Keyboard.h"

namespace GEngine
{
	void Keyboard::removeKey(int _key)
	{
		for (std::vector<int>::iterator it = keys.begin(); it != keys.end();) // using iterator because it will go through the element
		{
			if (*it == _key)
			{
				it = keys.erase(it); //IT points at the next element.
			}
			else
			{
				it++;
			}
		}
	}
	bool Keyboard::getKey(int _key)
	{
		for (size_t ki = 0; ki < keys.size(); ki++)
		{
			if (_key == keys.at(ki))
			{
				return true;
			}
				return false;
		}
	}
}
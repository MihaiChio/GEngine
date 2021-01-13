#include "Gamepad.h"
#include <iostream>

namespace GEngine
{

	void Gamepad::removeInput(int _axisButton)
	{
		for (std::vector<int>::iterator it = buttons.begin(); it != buttons.end();)
		{
			if (*it == _axisButton)
			{
				it = buttons.erase(it);
			}
			else
			{
				it++;
			}
		}
	}
	bool Gamepad::getInput(int _axisButon)
	{
		for (size_t bt = 0; bt < buttons.size(); bt++)
		{
			if(_axisButon == buttons.at(bt))
			{
				return true;
			}
			return false;
		}
	}
	void Gamepad::checkForJoystick(int _JoyNo)
	{
		if (_JoyNo > 0)
		{
			//std::cout << "Num of joysticks: " << _JoyNo << std::endl;
			loadJoystick();
		}
		else
		{
			std::cout << "No joystick connected" << std::endl;
		}

	}
	SDL_Joystick* Gamepad::getSDLJoystick()
	{
		return GameController;
	}
	void Gamepad::loadJoystick()
	{
		if (SDL_NumJoysticks() < 1)
		{
			std::cout << "No controller connected" << std::endl;
		}
		else
		{
			GameController = SDL_JoystickOpen(0);
			
		}
	}
	void Gamepad::closeJoystick()
	{
		SDL_JoystickClose(GameController);
		GameController = NULL;
	}
	 int Gamepad::getJoyDead()
	{
		return JOYSTICK_DEAD_ZONE;
	}
	 void Gamepad::setController()
	 {
		 GameController = SDL_JoystickOpen(0);
	 }
}
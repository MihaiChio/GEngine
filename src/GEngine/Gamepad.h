
#include "Exception.h"
#include <SDL.h>
#include <iostream>
#include <vector>


namespace GEngine
{
	struct Core;
	struct Gamepad
	{
		Gamepad() { GameController = nullptr;};
		void removeInput(int _axisButton);
		bool getInput(int _axisButon);
		void checkForJoystick(int _JoyNo);
		SDL_Joystick* getSDLJoystick();
		void loadJoystick(); // has checker.
		void closeJoystick(); // will disconnect the joystick.
		int getJoyDead();
		void setController();
	private:
		friend struct GEngine::Core;
		
		std::vector<int> buttons;
		SDL_Joystick* GameController;
		const int JOYSTICK_DEAD_ZONE = 8000;
	};
}
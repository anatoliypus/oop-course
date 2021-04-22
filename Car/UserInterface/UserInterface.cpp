#include "../Car/Car.h"
#include <iostream>
#include <sstream>
#include <string>

const std::string infoCommand = "Info";
const std::string engineOffCommand = "EngineOff";
const std::string engineOnCommand = "EngineOn";
const std::string setGearCommand = "SetGear";
const std::string setSpeedCommand = "SetSpeed";
const std::string quitCommand = "Exit";

const std::string greeting = "Welcome to the Car class interface!\n\n";
const std::string goodbye = "Goodbye!\n";

bool GetArg(std::istringstream& istr, int& arg)
{
	if (!(istr >> arg) || !(istr.eof()))
	{
		return false;
	}
	return true;
}

void WriteOutGreeting()
{
	std::cout << greeting;
	std::cout << "Command list:\n";
	std::cout << infoCommand << " - get car state\n";
	std::cout << engineOnCommand << " - turn on engine\n";
	std::cout << engineOffCommand << " - turn off engine\n";
	std::cout << setSpeedCommand << " <speed> - set car`s speed\n";
	std::cout << setGearCommand << " <gear> - set car`s gear\n";
	std::cout << std::endl;
}

void Conversation(Car& car)
{
	std::string commandName;
	int arg;
	while (true)
	{
		std::string str;
		std::getline(std::cin, str);
		std::istringstream istr(str);
		istr >> commandName;
		if (commandName.compare(quitCommand) == 0)
		{
			break;
		}
		else if (commandName.compare(engineOffCommand) == 0)
		{
			if (car.TurnOffEngine())
			{
				std::cout << "Engine turned off\n\n";
			}
			else
			{
				std::cout << "Failed to turn off the engine\n\n";
			}
		}
		else if (commandName.compare(engineOnCommand) == 0)
		{
			if (car.TurnOnEngine())
			{
				std::cout << "Engine turned on\n\n";
			}
			else
			{
				std::cout << "Failed to turn on the engine\n\n";
			}
		}
		else if (commandName.compare(setGearCommand) == 0)
		{
			if (!GetArg(istr, arg))
			{
				std::cout << "Wrong parameter given\n\n";
			}
			else if (car.SetGear(arg))
			{
				std::cout << "New gear set\n\n";
			}
			else
			{
				std::cout << "Failed to set new gear\n\n";
			}
		}
		else if (commandName.compare(setSpeedCommand) == 0)
		{
			if (!GetArg(istr, arg))
			{
				std::cout << "Wrong parameter given\n\n";
			}
			else if (car.SetSpeed(arg))
			{
				std::cout << "New speed set\n\n";
			}
			else
			{
				std::cout << "Failed to set new speed\n\n";
			}
		}
		else if (commandName.compare(infoCommand) == 0)
		{
			std::cout << "______________________\n";
			std::cout << "Speed: " << car.GetSpeed() << std::endl;
			std::cout << "Gear: " << car.GetGear() << std::endl;
			std::cout << "Direction: " << car.GetDirection() << std::endl;
			if (car.IsTurnedOn())
			{
				std::cout << "Car is turned on.\n";
			}
			else
			{
				std::cout << "Car is turned off.\n";
			}
			std::cout << "______________________\n\n";
		}
		else
		{
			std::cout << "Unknown command. Please try again.\n";
		}
	}
	std::cout << goodbye;
}

int main()
{
	Car car;
	WriteOutGreeting();
	Conversation(car);
	return 0;
}

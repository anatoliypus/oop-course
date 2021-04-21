#pragma once

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

bool GetArg(std::istringstream& istr, int& arg);
void Conversation(Car& car);

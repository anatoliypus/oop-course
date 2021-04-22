#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

namespace CarSpecs
{
const int GearRMax = 20;
const int GearRMin = 0;

const int Gear1Max = 30;
const int Gear1Min = 0;

const int Gear2Max = 50;
const int Gear2Min = 20;

const int Gear3Max = 60;
const int Gear3Min = 30;

const int Gear4Max = 90;
const int Gear4Min = 40;

const int Gear5Max = 150;
const int Gear5Min = 50;

const std::string standing = "Standing";
const std::string forwards = "Forwards";
const std::string backwards = "Backwards";
} // namespace CarSpecs

struct GearLimit
{
	GearLimit(int max_arg, int min_arg)
	{
		max = max_arg;
		min = min_arg;
	}
	int max, min;
};

class Car
{
public:
	Car();
	bool IsTurnedOn() const;
	int GetGear() const;
	int GetSpeed() const;
	std::string GetDirection() const;

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	int m_gear;
	int m_speed;
	bool m_isTurnedOn;
};

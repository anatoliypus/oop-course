#include "Car.h"

std::unordered_map<int, GearLimit> gearLimits = {
	{ -1, GearLimit(GearRMax, GearRMin) },
	{ 1, GearLimit(Gear1Max, Gear1Min) },
	{ 2, GearLimit(Gear2Max, Gear2Min) },
	{ 3, GearLimit(Gear3Max, Gear3Min) },
	{ 4, GearLimit(Gear4Max, Gear4Min) },
	{ 5, GearLimit(Gear5Max, Gear5Min) },
};

Car::Car()
{
	m_gear = 0;
	m_isTurnedOn = false;
	m_speed = 0;
}

bool Car::IsTurnedOn() const
{
	return m_isTurnedOn;
}

int Car::GetGear() const
{
	return m_gear;
}

int Car::GetSpeed() const
{
	return std::abs(m_speed);
}

std::string Car::GetDirection() const
{
	if (m_speed > 0)
	{
		return forwards;
	}
	else if (m_speed == 0)
	{
		return standing;
	}
	else
	{
		return backwards;
	}
}

bool Car::TurnOnEngine()
{
	if (m_gear != 0 || m_isTurnedOn)
	{
		return false;
	}
	m_isTurnedOn = true;
	return true;
}

bool Car::TurnOffEngine()
{
	if (m_speed != 0 || m_gear != 0 || !m_isTurnedOn)
	{
		return false;
	}
	m_isTurnedOn = false;
	return true;
}

bool Car::SetGear(int gear)
{
	if (!m_isTurnedOn)
	{
		if (gear == 0)
		{
			m_gear = gear;
			return true;
		}
		else
		{
			return false;
		}
	}
	auto iterator = gearLimits.find(gear);
	if (gear != 0 && gear != -1 && (iterator == gearLimits.end() || m_speed > iterator->second.max || m_speed < iterator->second.min))
	{
		return false;
	}
	if (gear == -1 && m_gear != -1 && (m_gear != 0 || m_speed != 0))
	{
		return false;
	}
	m_gear = gear;
	return true;
}

bool Car::SetSpeed(int speed)
{
	if (!m_isTurnedOn)
	{
		if (speed == 0)
		{
			m_speed = 0;
			return true;
		}
		else
		{
			return false;
		}
	}
	if (speed < 0)
	{
		return false;
	}
	if (m_gear != 0)
	{
		const auto limits = gearLimits.at(m_gear);
		if (speed > limits.max || speed < limits.min)
		{
			return false;
		}
	}
	else if (std::abs(m_speed) < speed)
	{
		return false;
	}
	if (m_gear == -1)
	{
		m_speed = speed * -1;
	}
	else
	{
		m_speed = speed;
	}
	return true;
}

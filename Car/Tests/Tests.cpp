#include "../../catch2/catch.hpp"
#include "../Car/Car.h"

TEST_CASE("Testing class construction / getters")
{
	Car car;
	CHECK(car.GetDirection() == "Standing");
	CHECK(car.GetGear() == 0);
	CHECK(car.GetSpeed() == 0);
	CHECK(!car.IsTurnedOn());
}

TEST_CASE("Testing speed and gear setters")
{
	Car car;

	car.SetGear(0);
	CHECK(car.GetGear() == 0);

	car.SetGear(1);
	CHECK(car.GetGear() == 0);

	car.SetSpeed(0);
	CHECK(car.GetSpeed() == 0);

	car.SetSpeed(10);
	CHECK(car.GetSpeed() == 0);

	car.TurnOnEngine();
	CHECK(car.IsTurnedOn());

	car.SetGear(-2);
	CHECK(car.GetGear() == 0);

	car.SetGear(-1);
	CHECK(car.GetGear() == -1);

	car.SetSpeed(GearRMax);
	CHECK(car.GetSpeed() == GearRMax);

	car.SetSpeed(0);
	CHECK(car.GetSpeed() == 0);

	car.SetGear(0);
	CHECK(car.GetGear() == 0);

	car.SetSpeed(-1);
	CHECK(car.GetSpeed() == 0);

	car.SetGear(1);
	CHECK(car.GetGear() == 1);

	car.SetSpeed(Gear1Max);
	CHECK(car.GetSpeed() == Gear1Max);

	car.SetGear(2);
	CHECK(car.GetGear() == 2);

	car.SetSpeed(Gear2Min);
	CHECK(car.GetSpeed() == Gear2Min);

	car.SetSpeed(Gear2Max);
	CHECK(car.GetSpeed() == Gear2Max);

	car.SetGear(3);
	CHECK(car.GetGear() == 3);

	car.SetSpeed(Gear3Min);
	CHECK(car.GetSpeed() == Gear3Min);

	car.SetSpeed(Gear3Max);
	CHECK(car.GetSpeed() == Gear3Max);

	car.SetGear(4);
	CHECK(car.GetGear() == 4);

	car.SetSpeed(Gear4Min);
	CHECK(car.GetSpeed() == Gear4Min);

	car.SetSpeed(Gear4Max);
	CHECK(car.GetSpeed() == Gear4Max);

	car.SetGear(5);
	CHECK(car.GetGear() == 5);

	car.SetSpeed(Gear5Min);
	CHECK(car.GetSpeed() == Gear5Min);

	car.SetSpeed(Gear5Max);
	CHECK(car.GetSpeed() == Gear5Max);

	car.SetGear(6);
	CHECK(car.GetGear() == 5);

	car.SetSpeed(Gear5Max + 1);
	CHECK(car.GetSpeed() == Gear5Max);

	car.SetSpeed(Gear5Min - 1);
	CHECK(car.GetSpeed() == Gear5Max);

	car.SetSpeed(Gear4Max);
	CHECK(car.GetSpeed() == Gear4Max);

	car.SetGear(4);
	CHECK(car.GetGear() == 4);

	car.SetSpeed(Gear4Max + 1);
	CHECK(car.GetSpeed() == Gear4Max);

	car.SetSpeed(Gear4Min - 1);
	CHECK(car.GetSpeed() == Gear4Max);

	car.SetSpeed(Gear3Max);
	CHECK(car.GetSpeed() == Gear3Max);

	car.SetGear(3);
	CHECK(car.GetGear() == 3);

	car.SetSpeed(Gear3Max + 1);
	CHECK(car.GetSpeed() == Gear3Max);

	car.SetSpeed(Gear3Min - 1);
	CHECK(car.GetSpeed() == Gear3Max);

	car.SetSpeed(Gear2Max);
	CHECK(car.GetSpeed() == Gear2Max);

	car.SetGear(2);
	CHECK(car.GetGear() == 2);

	car.SetSpeed(Gear2Max + 1);
	CHECK(car.GetSpeed() == Gear2Max);

	car.SetSpeed(Gear2Min - 1);
	CHECK(car.GetSpeed() == Gear2Max);

	car.SetSpeed(Gear1Max);
	CHECK(car.GetSpeed() == Gear1Max);

	car.SetGear(1);
	CHECK(car.GetGear() == 1);

	car.SetSpeed(Gear1Max + 1);
	CHECK(car.GetSpeed() == Gear1Max);

	car.SetSpeed(Gear1Min - 1);
	CHECK(car.GetSpeed() == Gear1Max);

	car.SetSpeed(0);
	CHECK(car.GetSpeed() == 0);

	car.SetGear(0);
	CHECK(car.GetGear() == 0);

	car.SetSpeed(20);
	CHECK(car.GetSpeed() == 0);

	car.SetGear(-1);
	CHECK(car.GetGear() == -1);

	car.SetSpeed(GearRMax + 1);
	CHECK(car.GetSpeed() == 0);
}

TEST_CASE("Checking switching to the rear gear")
{
	Car car;

	car.SetGear(1);
	CHECK(car.GetGear() == 0);

	car.TurnOnEngine();
	CHECK(car.IsTurnedOn());

	car.SetGear(1);
	CHECK(car.GetGear() == 1);

	car.SetGear(-1);
	CHECK(car.GetGear() == 1);

	car.SetSpeed(10);
	CHECK(car.GetSpeed() == 10);

	car.SetGear(0);
	CHECK(car.GetGear() == 0);

	car.SetGear(-1);
	CHECK(car.GetGear() == 0);

	car.SetSpeed(0);
	CHECK(car.GetSpeed() == 0);

	car.SetGear(-1);
	CHECK(car.GetGear() == -1);

	car.SetSpeed(10);
	CHECK(car.GetSpeed() == 10);

	car.SetGear(0);
	CHECK(car.GetGear() == 0);

	car.SetGear(-1);
	CHECK(car.GetGear() == 0);

	car.SetSpeed(0);
	CHECK(car.GetSpeed() == 0);

	car.SetGear(-1);
	CHECK(car.GetGear() == -1);

	car.SetSpeed(10);
	CHECK(car.GetSpeed() == 10);

	car.SetGear(1);
	CHECK(car.GetGear() == -1);
}

TEST_CASE("Checking direction getter")
{
	Car car;

	CHECK(car.GetDirection() == standing);

	car.TurnOnEngine();
	CHECK(car.IsTurnedOn());

	CHECK(car.GetDirection() == standing);

	car.SetGear(1);
	CHECK(car.GetGear() == 1);
	CHECK(car.GetDirection() == standing);

	car.SetSpeed(Gear1Max);
	CHECK(car.GetDirection() == forwards);

	car.SetGear(0);
	CHECK(car.GetDirection() == forwards);

	car.SetSpeed(0);
	CHECK(car.GetSpeed() == 0);
	CHECK(car.GetDirection() == standing);

	car.SetGear(-1);
	CHECK(car.GetGear() == -1);
	CHECK(car.GetDirection() == standing);
	car.SetSpeed(10);
	CHECK(car.GetSpeed() == 10);
	CHECK(car.GetDirection() == backwards);
}

TEST_CASE("Checking turning on / off methods")
{
	Car car;
	car.TurnOnEngine();
	CHECK(car.IsTurnedOn());

	car.TurnOnEngine();
	CHECK(car.IsTurnedOn());

	car.SetGear(1);
	CHECK(car.GetGear() == 1);
	car.SetSpeed(Gear1Max);
	CHECK(car.GetSpeed() == Gear1Max);
	car.TurnOffEngine();
	CHECK(car.IsTurnedOn());

	car.SetGear(0);
	CHECK(car.GetGear() == 0);
	car.TurnOffEngine();
	CHECK(car.IsTurnedOn());

	car.SetSpeed(0);
	CHECK(car.GetSpeed() == 0);
	car.TurnOffEngine();
	CHECK(!car.IsTurnedOn());
}

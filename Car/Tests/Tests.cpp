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

	car.SetSpeed(CarSpecs::GearRMax);
	CHECK(car.GetSpeed() == CarSpecs::GearRMax);

	car.SetSpeed(0);
	CHECK(car.GetSpeed() == 0);

	car.SetGear(0);
	CHECK(car.GetGear() == 0);

	car.SetSpeed(-1);
	CHECK(car.GetSpeed() == 0);

	car.SetGear(1);
	CHECK(car.GetGear() == 1);

	car.SetSpeed(CarSpecs::Gear1Max);
	CHECK(car.GetSpeed() == CarSpecs::Gear1Max);

	car.SetGear(2);
	CHECK(car.GetGear() == 2);

	car.SetSpeed(CarSpecs::Gear2Min);
	CHECK(car.GetSpeed() == CarSpecs::Gear2Min);

	car.SetSpeed(CarSpecs::Gear2Max);
	CHECK(car.GetSpeed() == CarSpecs::Gear2Max);

	car.SetGear(3);
	CHECK(car.GetGear() == 3);

	car.SetSpeed(CarSpecs::Gear3Min);
	CHECK(car.GetSpeed() == CarSpecs::Gear3Min);

	car.SetSpeed(CarSpecs::Gear3Max);
	CHECK(car.GetSpeed() == CarSpecs::Gear3Max);

	car.SetGear(4);
	CHECK(car.GetGear() == 4);

	car.SetSpeed(CarSpecs::Gear4Min);
	CHECK(car.GetSpeed() == CarSpecs::Gear4Min);

	car.SetSpeed(CarSpecs::Gear4Max);
	CHECK(car.GetSpeed() == CarSpecs::Gear4Max);

	car.SetGear(5);
	CHECK(car.GetGear() == 5);

	car.SetSpeed(CarSpecs::Gear5Min);
	CHECK(car.GetSpeed() == CarSpecs::Gear5Min);

	car.SetSpeed(CarSpecs::Gear5Max);
	CHECK(car.GetSpeed() == CarSpecs::Gear5Max);

	car.SetGear(6);
	CHECK(car.GetGear() == 5);

	car.SetSpeed(CarSpecs::Gear5Max + 1);
	CHECK(car.GetSpeed() == CarSpecs::Gear5Max);

	car.SetSpeed(CarSpecs::Gear5Min - 1);
	CHECK(car.GetSpeed() == CarSpecs::Gear5Max);

	car.SetSpeed(CarSpecs::Gear4Max);
	CHECK(car.GetSpeed() == CarSpecs::Gear4Max);

	car.SetGear(4);
	CHECK(car.GetGear() == 4);

	car.SetSpeed(CarSpecs::Gear4Max + 1);
	CHECK(car.GetSpeed() == CarSpecs::Gear4Max);

	car.SetSpeed(CarSpecs::Gear4Min - 1);
	CHECK(car.GetSpeed() == CarSpecs::Gear4Max);

	car.SetSpeed(CarSpecs::Gear3Max);
	CHECK(car.GetSpeed() == CarSpecs::Gear3Max);

	car.SetGear(3);
	CHECK(car.GetGear() == 3);

	car.SetSpeed(CarSpecs::Gear3Max + 1);
	CHECK(car.GetSpeed() == CarSpecs::Gear3Max);

	car.SetSpeed(CarSpecs::Gear3Min - 1);
	CHECK(car.GetSpeed() == CarSpecs::Gear3Max);

	car.SetSpeed(CarSpecs::Gear2Max);
	CHECK(car.GetSpeed() == CarSpecs::Gear2Max);

	car.SetGear(2);
	CHECK(car.GetGear() == 2);

	car.SetSpeed(CarSpecs::Gear2Max + 1);
	CHECK(car.GetSpeed() == CarSpecs::Gear2Max);

	car.SetSpeed(CarSpecs::Gear2Min - 1);
	CHECK(car.GetSpeed() == CarSpecs::Gear2Max);

	car.SetSpeed(CarSpecs::Gear1Max);
	CHECK(car.GetSpeed() == CarSpecs::Gear1Max);

	car.SetGear(1);
	CHECK(car.GetGear() == 1);

	car.SetSpeed(CarSpecs::Gear1Max + 1);
	CHECK(car.GetSpeed() == CarSpecs::Gear1Max);

	car.SetSpeed(CarSpecs::Gear1Min - 1);
	CHECK(car.GetSpeed() == CarSpecs::Gear1Max);

	car.SetSpeed(0);
	CHECK(car.GetSpeed() == 0);

	car.SetGear(0);
	CHECK(car.GetGear() == 0);

	car.SetSpeed(20);
	CHECK(car.GetSpeed() == 0);

	car.SetGear(-1);
	CHECK(car.GetGear() == -1);

	car.SetSpeed(CarSpecs::GearRMax + 1);
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

	car.SetGear(0);
	CHECK(car.GetGear() == 0);

	car.SetGear(1);
	CHECK(car.GetGear() == 0);
}

TEST_CASE("Checking direction getter")
{
	Car car;

	CHECK(car.GetDirection() == CarSpecs::standing);

	car.TurnOnEngine();
	CHECK(car.IsTurnedOn());

	CHECK(car.GetDirection() == CarSpecs::standing);

	car.SetGear(1);
	CHECK(car.GetGear() == 1);
	CHECK(car.GetDirection() == CarSpecs::standing);

	car.SetSpeed(CarSpecs::Gear1Max);
	CHECK(car.GetDirection() == CarSpecs::forwards);

	car.SetGear(0);
	CHECK(car.GetDirection() == CarSpecs::forwards);

	car.SetSpeed(0);
	CHECK(car.GetSpeed() == 0);
	CHECK(car.GetDirection() == CarSpecs::standing);

	car.SetGear(-1);
	CHECK(car.GetGear() == -1);
	CHECK(car.GetDirection() == CarSpecs::standing);
	car.SetSpeed(10);
	CHECK(car.GetSpeed() == 10);
	CHECK(car.GetDirection() == CarSpecs::backwards);

	car.SetGear(0);
	CHECK(car.GetGear() == 0);
	CHECK(car.GetDirection() == CarSpecs::backwards);
	car.SetSpeed(9);
	CHECK(car.GetSpeed() == 9);
	CHECK(car.GetDirection() == CarSpecs::backwards);
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
	car.SetSpeed(CarSpecs::Gear1Max);
	CHECK(car.GetSpeed() == CarSpecs::Gear1Max);
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

#include <iostream>
#include"Factory.h"

using namespace std;



class SportCar
{
	Engine* engine;
	Tank* tank;
	Wheels* wheels;
public:
	SportCar(SportCarFactory* factory)
	{
		this->engine = factory->createEngine();
		this->tank = factory->createTank();
		this->wheels = factory->createWheels();
	}
	~SportCar()
	{

	}
	void info()const
	{
		engine->info();
		tank->info();
		wheels->info();
	}
};

class Truck
{
	Engine* engine;
	Tank* tank;
	Wheels* wheels;
public:
	Truck(TrackFactory* factory)
	{
		this->engine = factory->createEngine();
		this->tank = factory->createTank();
		this->wheels = factory->createWheels();
	}
	~Truck() { }

	void info() const
	{
		engine->info();
		tank->info();
		wheels->info();
	}
};

class Suv
{
	Engine* engine;
	Tank* tank;
	Wheels* wheels;
public:
	Suv(SuvFactory* factory)
	{
		this->engine = factory->createEngine();
		this->tank = factory->createTank();
		this->wheels = factory->createWheel();
	}
	~Suv() { }

	void info() const
	{
		engine->info();
		tank->info();
		wheels->info();
	}
};


void main()
{
	setlocale(LC_ALL, "Russian");

	SportCar lambarghini(new SportCarFactory);
	lambarghini.info();

	Truck taiga(new TrackFactory);
	taiga.info();

	Suv LandCruser(new SuvFactory);
	LandCruser.info();
}
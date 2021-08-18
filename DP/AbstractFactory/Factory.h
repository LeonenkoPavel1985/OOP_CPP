#pragma once
#include<iostream>
using namespace std;

#include"Engine.h"
#include"Tank.h"
#include "Wheels.h"

class AbstractFactory
{
public:
	virtual Engine* createEngine() = 0;
	virtual Tank* createTank() = 0;
	virtual Wheels* createWheels() = 0;
};

class SportCarFactory :public AbstractFactory
{
public:
	Engine* createEngine()
	{
		return new SportEngine;
	}
	Tank* createTank()
	{
		return new SportTank;
	}
	Wheels* createWheel()
	{
		return new SportWheels;
	}
};

class TrackFactory :public AbstractFactory
{
public:
	Engine* createEngine()
	{
		return new TruckEngine;
	}
	Tank* createTank()
	{
		return new TruckTank;
	}
	Wheels* createWheels()
	{
		return new TruckWheels;
	}
};

class SuvFactory :public AbstractFactory
{
public:
	Engine* createEngine()
	{
		return new SuvEngine;
	}
	Tank* createTank()
	{
		return new SuvTank;
	}
	Wheels* createWheel()
	{
		return new SuvWheels;
	}
};

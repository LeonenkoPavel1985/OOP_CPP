#pragma once
#include <iostream>

using namespace std;

class Wheels
{
protected:
	unsigned int size;
public:
	Wheels(unsigned int size) : size(size) { }
	virtual ~Wheels() { }

	virtual unsigned int get_size() const = 0;

	void info() const
	{
		cout << typeid(*this).name() << endl;
		cout << "Size:\t" << size << endl;
	}
};

class SportWheels :public Wheels
{
public:
	SportWheels() : Wheels(20) { }
	~SportWheels() { }
	unsigned int get_size() const
	{
		return this->size;
	}
};

class TruckWheels :public Wheels
{
public:
	TruckWheels() : Wheels(23) { }
	~TruckWheels() { }
	unsigned int get_size() const
	{
		return this->size;
	}
};

class SuvWheels :public Wheels
{
public:
	SuvWheels() : Wheels(26) { }
	~SuvWheels() { }
	unsigned int get_size() const
	{
		return this->size;
	}
};

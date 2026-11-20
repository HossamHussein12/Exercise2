#pragma once
#include <iostream>
#include <string>
using namespace std;
class Robot
{
protected : 
	string name;
	float batteryLevel;
public :
	Robot(string n, float bl);
	void RechargeBattery();
	void DecreaseBatteryLevel(float am);
	int Compare(Robot*);
	virtual void Attack(Robot*)=0;
	virtual void Print()=0;
	virtual ~Robot();
};


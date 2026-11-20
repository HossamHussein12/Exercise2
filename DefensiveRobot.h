#pragma once
#include "Robot.h"
class DefensiveRobot :
    public Robot
{
private:
    float firePower;
public :
    DefensiveRobot(string name, float battteryLevel,float fp=0);
    void SetFirePower(float p);
    float getFirePower();
    void Print();
    void Attack(Robot* other);
    ~DefensiveRobot();
};


#pragma once
#include "Robot.h"
class NormalRobot :
    public Robot
{
public :
    NormalRobot(string name , float batteryLevel);
    void Print();
    void Attack(Robot* other);
    ~NormalRobot();
};


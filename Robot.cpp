#include "Robot.h"

Robot::Robot(string n, float bl) : name(n),batteryLevel(bl){}
void Robot::RechargeBattery()
{
    batteryLevel = 100;
}

void Robot::DecreaseBatteryLevel(float am)
{
    batteryLevel -= am;
    if (batteryLevel <= 0) RechargeBattery();
}

int Robot::Compare(Robot* robot)
{
    if (this->batteryLevel > robot->batteryLevel)
        return 1;
    else if(this->batteryLevel < robot->batteryLevel)
        return -1;
    else return 0;
}
Robot::~Robot(){}
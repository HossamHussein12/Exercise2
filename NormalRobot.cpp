#include "NormalRobot.h"
#include "DefensiveRobot.h"
//#include "Robot.h"
NormalRobot::NormalRobot(string name, float batteryLevel) : Robot(name,batteryLevel){}
void NormalRobot::Print()
{
    cout << "\nType : Normal Robot" << "\nName : " << name << "\nBatteryLevel : " << batteryLevel ;    
}

void NormalRobot::Attack(Robot* other)
{

    if (other == this || other == nullptr) return;
    DefensiveRobot* defOfOther = dynamic_cast<DefensiveRobot*> (other);
    if (defOfOther != nullptr) {
        this->DecreaseBatteryLevel(defOfOther->getFirePower());
    }
}

NormalRobot::~NormalRobot()
{
}

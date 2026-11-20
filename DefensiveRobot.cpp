#include "DefensiveRobot.h"
#include "NormalRobot.h"
DefensiveRobot::DefensiveRobot(string name, float bl, float fp):Robot(name,bl),firePower(fp){}

void DefensiveRobot::SetFirePower(float p)
{
    firePower = p;
}

float DefensiveRobot::getFirePower()
{
    return firePower;
}

void DefensiveRobot::Print()
{
    cout << "\nType : Defensive Robot " << "\nName : " << name << "\nBatteryLevel : " << batteryLevel << "\nFirePower : " << firePower;
}

void DefensiveRobot::Attack(Robot* other)
{
    if (other == this || other==nullptr) return;
    DefensiveRobot* defOfOther = dynamic_cast<DefensiveRobot*> (other);
    if (defOfOther != nullptr)
    {
        int cmp = this->Compare(defOfOther);
        if (cmp==1) {
            defOfOther->DecreaseBatteryLevel(this->firePower);
        } else if(cmp==-1)
            this->DecreaseBatteryLevel(defOfOther->firePower);
        return;
    }
    else {
        other->DecreaseBatteryLevel(this->firePower);
    }
}

DefensiveRobot::~DefensiveRobot()
{
}

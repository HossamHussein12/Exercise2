#include <iostream>
#include "Robot.h"
#include "DefensiveRobot.h"
#include "NormalRobot.h"

using namespace std;
int main() {
	Robot* robot[100];

	robot[0] = new DefensiveRobot("Defensive1", 90);
	robot[1] = new DefensiveRobot("Defensive2", 80);
	robot[2] = new NormalRobot("Normal1", 70);

	DefensiveRobot* de1 = dynamic_cast<DefensiveRobot*>(robot[0]);
	if(de1!=nullptr) de1->SetFirePower(5);
	DefensiveRobot* de2 = dynamic_cast<DefensiveRobot*>(robot[1]);
	if(de2!=nullptr) de2->SetFirePower(10);

	robot[0]->Print();
	robot[1]->Print();
	robot[2]->Print();

	robot[0]->Attack(robot[1]);
	robot[0]->Print();
	robot[1]->Print();
	robot[2]->Print();

	robot[0]->Attack(robot[2]);
	robot[0]->Print();
	robot[1]->Print();
	robot[2]->Print();

	delete robot[0];
	delete robot[1];
	delete robot[2];

	return 0;
}
#include "unarmed.h"

void Unarmed::entry(){
	//do some entry stuff
	//sound siren
	//blink some lights

	//setPhase(Phase::LOOP);
}

void Unarmed::loop(){
	bool conditionReached = false;

	while (!conditionReached){
		//do some loop stuff
		//blink some more lights
		//take some photos
		//take a measurement of the C02 sensor

		//When the Arm command is sent to rocket
		conditionReached = true;
	}

	//setPhase(Phase::EXIT)
}

void Unarmed::exit(){
	//do some exit stuff
	//sound the alarm

	// if stateMachine.validStateChange?(Unarmed, Armed){
	// 	then run setState(Armed)
	// else{
	// 	ERROR! this state transition is not valid!!
	// }
}
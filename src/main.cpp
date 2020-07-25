#include "unarmed.h"
#include "phase.h"
#include <iostream>

int main() {
    Unarmed * unarmedState = new Unarmed();
    Phase currentPhase = unarmedState->getPhase();

    std::cout << "Current state: " << unarmedState->toString() << std::endl;
    std::cout << "Current phase: " << printPhase(currentPhase) <<std::endl;
    // currentPhase will be equal to Phase::ENTRY

    // Phase::LOOP
    //myState->perform();
    // myState.m_phase will be equal to Phase::LOOP

    //myState->perform();
    //myState->exit();
    // myState.m_phase will be equal to Phase::EXIT

    // Unarmed * unarmed_state = new Unarmed();
    // Phase currentPhase = unarmed_state->getPhase();

    // if(currentPhase == Phase::EXIT){
		// 	std::cout << "Phase is exit" << std::endl;
    // } else {
		// 	std::cout << "Phase is not exit" << std::endl;
    // }

		return 0;
}

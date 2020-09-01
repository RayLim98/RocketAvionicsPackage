#include <unarmed.hpp>
#include <state_machine.hpp>

std::string Unarmed::toString() {
	return std::string("Unarmed");
}

void Unarmed::entry() {
	setPhase(Phase::LOOP);
}

void Unarmed::loop() {
	bool armCommandReceived = false;

	// check if the Arm command has been sent to the rocket
	// when the Arm command is sent to rocket
	armCommandReceived = true;
	if(armCommandReceived) {
		setPhase(Phase::EXIT);
	}
}

void Unarmed::exit() {
	if(m_machine->isValidStateChange(this, m_machine->m_armed)) {
		m_machine->setState(m_machine->m_armed);
	} else {
		throw "State transition not valid";
	}
}

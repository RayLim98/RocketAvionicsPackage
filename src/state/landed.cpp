#include <landed.hpp>
#include <state_machine.hpp>

std::string Landed::toString() {
	return std::string("Landed");
}

void Landed::entry() {
  // Send "Landed" signal
  setPhase(Phase::LOOP);
}

void Landed::loop() {
	bool unarmCommandReceived = false;

	// Check if unarm command has been send to rocket
	if(true) {
		unarmCommandReceived = true;
	}

	if(unarmCommandReceived) {
    setPhase(Phase::EXIT);
	}
}

void Landed::exit() {
	if(m_machine->isValidStateChange(this, m_machine->m_unarmed)) {
		m_machine->setState(m_machine->m_unarmed);
	} else {
		throw "State transition not valid";
	}
}

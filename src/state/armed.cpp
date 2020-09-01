#include <armed.hpp>
#include <state_machine.hpp>

class Unarmed;
class Ascending;

std::string Armed::toString() {
	return std::string("Armed");
}

int Armed::getData() const {
  //assigns rawData to getData(), now accessible to public.
  return rawData;
}

void Armed::setData(int adcData) {
  //assuming we're using something like an arduino with bluetooth to communicate to the software
  //adcData comes from the raw input of the board
  this->rawData = adcData;
}

void Armed::entry() {
  //Send "armed" signal
  setPhase(Phase::LOOP);
}

void Armed::loop() {
  //Will idle until change in state; either through a command or a physical button etc
  int trigger = getData();

  //Stub this temporarily
  trigger = 1;

  if (trigger == 1) { // some random integer to indicate Armed->Ascending signal
    flagLaunch = 10;
    setPhase(Phase::EXIT);
  } else if (trigger == -1) { //random integer to indicate Armed->Unarmed signal
    flagLaunch = 20;
    setPhase(Phase::EXIT);
  }
}

void Armed::exit() {
  //Command signal is dependant on flagLaunch
  //and will run one of two state change function below
  if (flagLaunch == 10 && m_machine->isValidStateChange(this, m_machine->m_ascending)) {
    m_machine->setState(m_machine->m_ascending);
  } else if (flagLaunch == 20 && m_machine->isValidStateChange(this, m_machine->m_unarmed)) {
    m_machine->setState(m_machine->m_unarmed);
  } else {
    throw "State transition not valid";
  }
}

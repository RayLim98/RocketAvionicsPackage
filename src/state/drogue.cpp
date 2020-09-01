#include <drogue.hpp>
#include <state_machine.hpp>

std::string Drogue::toString() {
	return std::string("Drogue");
}

void Drogue::entry() {
  /*
  RTC clock = new RTC();
  m_startTime = clock.getime();
  */
	setPhase(Phase::LOOP);
}

void Drogue::loop() {
  /*
  int const delay = 5;
  if(m_startTime - clock.getTime() >= delay){
    setPhase(Phase::EXIT);
  }
  */
  setPhase(Phase::EXIT);
}

void Drogue::exit() {
  /*
  if(m_machine->isValidStateChange(this, m_machine->m_descending)){
    m_machine->setState(m_machine->m_descending);
  } else {
    throw "State transition not valid";
  }
  */
}


#include <ascending.hpp>
#include <state_machine.hpp>

std::string Ascending::toString() {
	return std::string("Ascending");
}

int Ascending::getAltitude() const {
  return rawAltitude;
}

void Ascending::setAltitude(const int & adcAltitude) {
  rawAltitude = adcAltitude;
}

void Ascending::entry() {
  //do some entry stuff
  //sound siren
  //blink some lights

  setPhase(Phase::LOOP);
}

void Ascending::loop() {
  bool apogeeReached = false;
  int previousAltitude = getAltitude();
  int currentAltitude = getAltitude();
  int counter = 0;

  //updates current altitude
  currentAltitude = getAltitude();

  if (currentAltitude < previousAltitude) {
    //Characteristic of falling
    counter++;
  } else {
    //it is still rising
    counter = 0;
  }

  //updates the previousAltitude for next cycle
  previousAltitude = currentAltitude;

  //condition for apoogee being reached
  if (counter >= countTreshold) {
    //it has started falling
    //apogee reached
    apogeeReached = true;
  }

  //Stub this until it is implemented
  apogeeReached = true;

  if (apogeeReached) {
    setPhase(Phase::EXIT);
  }
}

void Ascending::exit() {
  //do some exit stuff
  //sound the alarm

  if (m_machine->isValidStateChange(this, m_machine->m_apogee)) {
		m_machine->setState(m_machine->m_apogee);
	} else {
		throw "State transition not valid";
	}
}


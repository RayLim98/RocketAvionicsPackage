#include <main_parachute.hpp>
#include <state_machine.hpp>
#include <some_altimeter.hpp>

std::string MainParachute::toString() {
	return std::string("Main-Parachute deployed");
}

double MainParachute::getAltitude() {
  SomeAltimeter* altitude_sensor = new SomeAltimeter();
  return altitude_sensor->getAltitude();
}

void MainParachute::setAltitude(double sensorReading) {
  m_altitudeSensor = sensorReading;
}

void MainParachute::entry() {
  m_currentAlt = getAltitude();
  m_currentAlt = m_previousAlt;
	setPhase(Phase::LOOP);
}

void MainParachute::loop() {
  float const error = 1; //in meters
  // double aX = IMU::accelerationX();
  // double aY = IMU::accelerationY();
  // double aZ = IMU::accelerationZ();
  double aX = 0.5f;
  double aY = 0.5f;
  double aZ = 0.5f;
  m_currentAlt = getAltitude();

  //check if condition is true for a certain period of ticks via m_counter
  //error values implemented to offset the noise in the sensors
  if ((m_currentAlt <= m_previousAlt - error) || (m_currentAlt >= m_previousAlt + error)) {
     if (aX > -1 && aX < 1) {
       if (aY > -1 && aY < 1) {
         if (aZ > -1 && aZ < 1) {
           ++m_hasLandedCounter;
         }
       }
    }
    //has landed condition
    if (m_hasLandedCounter == 100) {
      setPhase(Phase::EXIT);
    }
  } else {
    m_hasLandedCounter = 0;
  }
  //updates for next cycles comparision
  m_previousAlt = m_currentAlt;
}

void MainParachute::exit() {
  if (m_machine->isValidStateChange(this, m_machine->m_landed)) {
    m_machine->setState(m_machine->m_landed);
  } else {
    throw "State transition not valid";
  }
}


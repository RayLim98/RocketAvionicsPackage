#include <apogee.hpp>
#include <state_machine.hpp>

std::string Apogee::toString() {
  return std::string("Apogee");
}

int Apogee::getAltitude() const {
  return rawAltitude;
}

void Apogee::entry() {
  //Deploy Drogue parachute

  setPhase(Phase::LOOP);
}

void Apogee::loop() {
  if (stateToTransitionTo == 0) {
    /*
    SWITCHING FROM LIGHT TO DETECTING DECELERATION
    
    Take Height
    Loop 20ms Delay
      Take Height
      Compare to Last Recorded Height
      If the Height difference is getting smaller by a reasonable margin between increments
        Add 1 to the itteration of deceleration counter
      
      If the itteration of deceleration is greater than 5
        StateToTransitionTo = 10;

    */

    //do some loop stuff
    int previousAltitude = getAltitude();
    //do apogee stuff (take burst photo)

    //int lumens = LightSensor::read();

    // To replace the light sensor implementation with rate of descent based one
    if (lightThreshold > 100) {
      //Seeing as sensor reading is greater than the threshold, is eligble to transition states
      stateToTransitionTo = 10;
    } else if (timeElapsed > 5) {
      //(unsure as to how to set it up for a timer)
      //time is in seconds
      stateToTransitionTo = 20;
    }
  }

  setPhase(Phase::EXIT);
}

void Apogee::exit() {
  if (stateToTransitionTo == 10) {
    //set state to DrogueDeployed
  } else if (stateToTransitionTo == 20) {
    //set state to Descending
  }
}

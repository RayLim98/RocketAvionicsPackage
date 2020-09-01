#include <iostream>
#include <state_machine.hpp>
#include <some_barometer.hpp>

bool systemShouldContinue = true; // This flag to be controlled by telemetry
int updateCount = 0; // Counter for testing, removed in production

int main() {
  // Set up logging on local storage
  // create new file on local file storage

  // Set up sensors
  SomeBarometer * example_barometer = new SomeBarometer();

  // Set up telemetry
  // instatiate telemetry object

  // Set up state machine
  StateMachine * state_machine = new StateMachine();

  std::cout << "Initial state: " << state_machine->getCurrentState().toString() << std::endl;
  std::cout << "Initial phase: " << printPhase(state_machine->getCurrentState().getPhase()) <<std::endl;
  std::cout << "Initial pressure: " << example_barometer->getPressure() <<std::endl;

  // ------------------------ Loop section --------------------------------------

  // While system should continue operating (this can be controlled by telemetry)
  while (systemShouldContinue && updateCount < 20) {
    state_machine->getCurrentState().perform();
    std::cout << "Current state: " << state_machine->getCurrentState().toString() << std::endl;
    std::cout << "Current phase: " << printPhase(state_machine->getCurrentState().getPhase()) <<std::endl;
    std::cout << "Current pressure: " << example_barometer->getPressure() <<std::endl;

    // For local testing
    ++updateCount;
  }

  delete state_machine;
  return 0;
}

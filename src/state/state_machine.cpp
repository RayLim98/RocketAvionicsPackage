#include <state_machine.hpp>

bool StateMachine::isValidStateChange(State * from, State * to) const {
  for (std::pair<State *, State *> validTransition : m_stateTransitions) {
    if (validTransition == std::pair<State *, State *>(from, to)) {
      return true;
    }
  }

  return false;
}

void StateMachine::setState(State * state) {
  this->m_currentState = state;
}

State & StateMachine::getCurrentState() const {
  return *m_currentState;
}

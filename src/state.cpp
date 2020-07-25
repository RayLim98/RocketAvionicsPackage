#include "state.h"

void State::perform() {
  switch(m_phase) {
    case Phase::ENTRY:
      entry();
      break;
    case Phase::LOOP:
      loop();
      break;
    case Phase::EXIT:
      exit();
      break;
    default:
      return;
  }
}

Phase State::getPhase(){
  return m_phase;
}

void State::setPhase(Phase phase) {
    m_phase = phase;
    return;
};

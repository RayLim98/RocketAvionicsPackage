#include <state.hpp>

void State::perform() {
  switch (m_phase) {
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

Phase State::getPhase() const {
  return this->m_phase;
}

void State::setPhase(Phase phase) {
  this->m_phase = phase;
}

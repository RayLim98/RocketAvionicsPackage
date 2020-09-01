#ifndef PHASE_H
#define PHASE_H

#include <iostream>
#include <string>

enum class Phase {
    ENTRY,
    LOOP,
    EXIT
};

inline std::string printPhase(Phase phase) {
  switch (phase) {
    case Phase::ENTRY:
      return std::string("Entry");
      break;
    case Phase::LOOP:
      return std::string("Loop");
      break;
    case Phase::EXIT:
      return std::string("Exit");
      break;
    default:
      throw "How?";
  }
}

#endif

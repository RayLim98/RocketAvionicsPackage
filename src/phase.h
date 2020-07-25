#ifndef PHASE_H
#define PHASE_H

#include <iostream>

enum Phase { 
    ENTRY = 1,
    LOOP = 2,
    EXIT = 3
};

inline std::string printPhase(Phase phase){
  switch(phase) {
    case ENTRY:
      return std::string("Entry");
      break;
    case LOOP:
      return std::string("Loop");
      break;
    case EXIT:
      return std::string("Exit");
      break;
    default:
      return std::string("Derp");
      break;
  }
}

#endif

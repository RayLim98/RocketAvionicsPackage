#ifndef STATE_H
#define STATE_H

#include "phase.h"

class State {
  public:
    State() {
      m_phase = Phase::ENTRY;
    }

    void perform();
    Phase getPhase();

  private:
    Phase m_phase;

    // The following means that any class inheriting State HAS to define an entry, do and exit method
    virtual void entry();
    virtual void loop();
    virtual void exit();

    void setPhase(Phase phase);
};

#endif

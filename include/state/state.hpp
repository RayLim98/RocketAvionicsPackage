#ifndef STATE_H
#define STATE_H

#include <phase.hpp>
#include <string>

class State {
 public:
    State() {
      m_phase = Phase::ENTRY;
    }
    ~State() {}

    Phase getPhase() const;
    void setPhase(Phase phase);
    void perform();

    //Virtual toString function to be overriden by inheriting classes
    virtual std::string toString() = 0;

  private:
    Phase m_phase;

    //Virtual methods to be overriden by inheriting classes
    virtual void entry() = 0;
    virtual void loop() = 0;
    virtual void exit() = 0;
};

#endif

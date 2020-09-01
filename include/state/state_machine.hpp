#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <map>
#include <utility>
#include <state.hpp>
#include <unarmed.hpp>
#include <armed.hpp>
#include <ascending.hpp>
#include <apogee.hpp>
#include <landed.hpp>

class StateMachine {
  public:
    StateMachine(bool hasMainParachute = true, bool hasDrogueParachute = true) {
      // Set intial parameters
      this->m_hasMainParachute = hasMainParachute;
      this->m_hasDrogueParachute = hasDrogueParachute;

      // Initialise all states (pre-allocating memory)
      this->m_unarmed = new Unarmed(this);
      this->m_armed = new Armed(this);
      this->m_ascending = new Ascending(this);
      this->m_apogee = new Apogee(this);
      this->m_landed = new Landed(this);

      // Set initial state to Unarmed
      setState(m_unarmed);

      // Transitions from Unarmed
      m_stateTransitions.insert(std::pair<State *, State *>(m_unarmed, m_armed));

      // Transitions from Armed
      m_stateTransitions.insert(std::pair<State *, State *>(m_armed, m_unarmed));
      m_stateTransitions.insert(std::pair<State *, State *>(m_armed, m_ascending));

      // Transitions from Ascending
      m_stateTransitions.insert(std::pair<State *, State *>(m_ascending, m_apogee));

      // Transitions from Landed
      m_stateTransitions.insert(std::pair<State *, State *>(m_landed, m_unarmed));
    }

    ~StateMachine() {
      m_currentState = nullptr;
      m_unarmed = nullptr;
      m_armed = nullptr;
      m_ascending = nullptr;
      m_apogee = nullptr;
      m_landed = nullptr;
    }

    bool isValidStateChange(State * from, State * to) const;
    void setState(State * state);
    State & getCurrentState() const;

    State * m_currentState;
    Unarmed * m_unarmed;
    Armed * m_armed;
    Ascending * m_ascending;
    Apogee * m_apogee;
    Landed * m_landed;

  private:
    bool m_hasMainParachute;
    bool m_hasDrogueParachute;

    std::multimap<State *, State *> m_stateTransitions;
};

#endif

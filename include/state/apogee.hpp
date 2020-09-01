#ifndef APOGEE_H
#define APOGEE_H

#include <state.hpp>
#include <string>

class StateMachine;

class Apogee : public State {
	public:
		explicit Apogee(StateMachine * machine) {
      setPhase(Phase::ENTRY);
			m_machine = machine;
    }

    int getAltitude() const;
    int stateToTransitionTo = 0;
    int timeElapsed = 0;

    std::string toString() override;

  private:
    int rawAltitude;
    StateMachine * m_machine;

    // We do not need to change this value during runtime
    static constexpr int lightThreshold = 10;

    void entry() override;
    void loop() override;
    void exit() override;
};

#endif

#ifndef LANDED_H
#define LANDED_H

#include <state.hpp>
#include <string>

class StateMachine;

class Landed : public State {
 public:
	  explicit Landed(StateMachine * machine) {
			setPhase(Phase::ENTRY);
			m_machine = machine;
    }

    std::string toString() override;

 private:
		StateMachine * m_machine;

		void entry() override;
		void loop() override;
		void exit() override;
};

#endif

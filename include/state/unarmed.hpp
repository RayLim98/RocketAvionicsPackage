#ifndef UNARMED_H
#define UNARMED_H

#include <state.hpp>
#include <string>

class StateMachine;

class Unarmed : public State {
	public:
		explicit Unarmed(StateMachine * machine) {
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

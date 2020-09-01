#ifndef DROGUE_H
#define DROGUE_H

#include <state.hpp>
#include <string>

class StateMachine;

class Drogue : public State {
	public:
		explicit Drogue(StateMachine * machine) {
			setPhase(Phase::ENTRY);
			m_machine = machine;
    }

    std::string toString();

	private:
		StateMachine * m_machine;

		double m_startTime;
		void entry();
		void loop();
		void exit();
};

#endif

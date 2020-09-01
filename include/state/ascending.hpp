#ifndef ASCENDING_H
#define ASCENDING_H

#include <state.hpp>
#include <string>

class StateMachine;

class Ascending : public State {
	public:
		explicit Ascending(StateMachine * machine) {
      setPhase(Phase::ENTRY);
			m_machine = machine;
    }

		int getAltitude() const;
		std::string toString() override;

	private:
		int rawAltitude;
		StateMachine * m_machine;

		// We do not need to tune this value during runtime
		static constexpr int countTreshold = 10;

		void setAltitude(const int & adcAltitude);

		void entry() override;
		void loop() override;
		void exit() override;
};

#endif


#ifndef MAIN_PARACHUTE_H
#define MAIN_PARACHUTE_H

#include <state.hpp>
#include <string>

class StateMachine;

class MainParachute : public State {
	public:
		explicit MainParachute(StateMachine * machine) {
			setPhase(Phase::ENTRY);
			m_machine = machine;
    }

    std::string toString();
		double getAltitude();

	private:
		StateMachine * m_machine;
		double m_altitudeSensor;
		double m_previousAlt;
		double m_currentAlt;
		int m_hasLandedCounter = 0;

		void setAltitude(double sensorReading);
		void entry();
		void loop();
		void exit();
};

#endif

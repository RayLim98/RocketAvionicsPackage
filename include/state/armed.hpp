#ifndef ARMED_H
#define ARMED_H

#include <state.hpp>
#include <string>

class StateMachine;

class Armed : public State {
	public:
		explicit Armed(StateMachine * machine) {
      setPhase(Phase::ENTRY);
			m_machine = machine;
    }

    int getData() const;
    std::string toString() override;

  private:
    StateMachine * m_machine;
    int flagLaunch;
    int rawData;

    void setData(int adcData);
    void entry() override;
    void loop() override;
    void exit() override;
};

#endif

#ifndef ARMED_H
#define ARMED_H

#include "state.h"

class Armed : public State {
  public:
	int getData();

  private:
	int flagLaunch;
	int rawData;
	void setData(int adcData);
  	void entry();
  	void loop();
  	void exit();

};

#endif

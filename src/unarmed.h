#ifndef UNARMED_H
#define UNARMED_H

#include "state.h"

class Unarmed : public State {
	private:
		void entry();
		void loop();
		void exit();
};

#endif

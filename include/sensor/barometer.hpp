#ifndef BAROMETER_H
#define BAROMETER_H

#include <string>

class Barometer {
	public:
		Barometer() {}

    virtual float getPressure() const = 0;
    virtual std::string toJsonString() const = 0;
};

#endif

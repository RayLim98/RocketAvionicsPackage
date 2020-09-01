#ifndef THERMOMETER_H
#define THERMOMETER_H

#include <string>

class Thermometer {
	public:
		Thermometer() {}

    virtual float getTemperature() const = 0;
    virtual std::string toJsonString() const = 0;
};

#endif

#ifndef SOME_THERMOMETER_H
#define SOME_THERMOMETER_H

#include <thermometer.hpp>
#include <string>

class SomeThermometer : public Thermometer {
	public:
		SomeThermometer() {}

    float getTemperature() const;
    std::string toJsonString() const;
};

#endif

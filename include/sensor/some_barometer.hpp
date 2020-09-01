#ifndef SOME_BAROMETER_H
#define SOME_BAROMETER_H

#include <barometer.hpp>
#include <string>

class SomeBarometer : public Barometer {
	public:
		SomeBarometer() {}

    float getPressure() const;
    std::string toJsonString() const;
};

#endif

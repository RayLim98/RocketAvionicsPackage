#ifndef SOME_ALTIMETER_H
#define SOME_ALTIMETER_H

#include <altimeter.hpp>
#include <string>

class SomeAltimeter : public Altimeter {
	public:
		SomeAltimeter() {}

    float getAltitude() const;
    std::string toJsonString() const;
};

#endif

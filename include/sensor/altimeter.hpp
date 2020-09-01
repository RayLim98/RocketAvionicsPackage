#ifndef ALTIMETER_H
#define ALTIMETER_H

#include <string>

class Altimeter {
	public:
		Altimeter() {}

    virtual float getAltitude() const = 0;
    virtual std::string toJsonString() const = 0;
};

#endif

#ifndef HYDROMETER_H
#define HYDROMETER_H

#include <string>

class Hydrometer {
	public:
		Hydrometer() {}

    virtual float getHumidity() const = 0;
    virtual std::string toJsonString() const = 0;
};

#endif

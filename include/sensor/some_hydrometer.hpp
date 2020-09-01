#ifndef SOME_HYDROMETER_H
#define SOME_HYDROMETER_H

#include <hydrometer.hpp>
#include <string>

class SomeHydrometer : public Hydrometer {
	public:
		SomeHydrometer() {}

    float getHumidity() const;
    std::string toJsonString() const;
};

#endif

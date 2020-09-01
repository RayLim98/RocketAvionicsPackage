#include <some_altimeter.hpp>
#include <json.hpp>

float SomeAltimeter::getAltitude() const {
  // Logic here to get the Altitude from the Altitude sensor
  // We can either use a pre-existing library or develop it ourselves

  return -1;
}

std::string SomeAltimeter::toJsonString() const {
  nlohmann::json j;
  j["timestamp"] = 1234; // should be getTime()
  j["altitude"] = getAltitude();

	return j.dump();
}

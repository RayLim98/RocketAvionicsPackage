#include <some_barometer.hpp>
#include <json.hpp>

float SomeBarometer::getPressure() const {
  // Logic here to get the pressure from the pressure sensor
  // We can either use a pre-existing library or develop it ourselves

  return -1;
}

std::string SomeBarometer::toJsonString() const {
  nlohmann::json j;
  j["timestamp"] = 1234; // should be getTime()
  j["pressure"] = getPressure();

  return j.dump();
}

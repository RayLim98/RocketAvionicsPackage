#include <some_thermometer.hpp>
#include <json.hpp>

float SomeThermometer::getTemperature() const {
  // Logic here to get the temp from the temp sensor
  // We can either use a pre-existing library or develop it ourselves

  return -1;
}

std::string SomeThermometer::toJsonString() const {
  nlohmann::json j;
  j["timestamp"] = 1234; // should be getTime()
  j["temperature"] = getTemperature();

  return j.dump();
}

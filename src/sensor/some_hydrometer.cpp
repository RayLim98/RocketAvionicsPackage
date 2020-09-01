#include <some_hydrometer.hpp>
#include <json.hpp>

float SomeHydrometer::getHumidity() const {
  // Logic here to get the humidity from the humidity sensor
  // We can either use a pre-existing library or develop it ourselves

  return -1;
}

std::string SomeHydrometer::toJsonString() const {
  nlohmann::json j;
  j["timestamp"] = 1234; // should be getTime()
  j["humidity"] = getHumidity();

  return j.dump();
}

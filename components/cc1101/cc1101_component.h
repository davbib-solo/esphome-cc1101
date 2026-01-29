#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/spi/spi.h"

namespace esphome {
namespace cc1101 {

class CC1101Sensor : public esphome::sensor::Sensor, public esphome::Component {
 public:
  void set_spi_device(esphome::spi::SPIClient *device) { this->spi_device_ = device; }

  void setup() override {
  }

  void loop() override {
  }

 protected:
  esphome::spi::SPIClient *spi_device_{nullptr};
};

}  // namespace cc1101
}  // namespace esphome

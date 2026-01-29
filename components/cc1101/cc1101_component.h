#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/spi/spi.h"

namespace esphome {
namespace cc1101 {

class CC1101Sensor : public sensor::Sensor, public Component {
 public:
  void set_spi_device(spi::SPIDevice *dev) { this->spi_dev_ = dev; }

  void setup() override {
    ESP_LOGI("cc1101", "CC1101 setup() called");
  }

  void loop() override {
    ESP_LOGV("cc1101", "CC1101 loop() running");
  }

 protected:
  spi::SPIDevice *spi_dev_{nullptr};
};

}  // namespace cc1101
}  // namespace esphome

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

    if (this->spi_dev_ == nullptr) {
      ESP_LOGE("cc1101", "SPI device not set");
      return;
    }

    // Read CC1101 PARTNUM register (0x30)
    uint8_t reg = 0x30 | 0x80;  // 0x80 = read single byte
    uint8_t value = 0;

    this->spi_dev_->enable();
    this->spi_dev_->transfer(&reg, 1);
    this->spi_dev_->transfer(&value, 1);
    this->spi_dev_->disable();

    ESP_LOGI("cc1101", "CC1101 PARTNUM register: 0x%02X", value);
  }

  void loop() override {
    // Quiet loop for now
  }

 protected:
  spi::SPIDevice *spi_dev_{nullptr};
};

}  // namespace cc1101
}  // namespace esphome

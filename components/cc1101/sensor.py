import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.components import spi

cc1101_ns = cg.esphome_ns.namespace("cc1101")
CC1101Sensor = cc1101_ns.class_("CC1101Sensor", sensor.Sensor, cg.Component)

cg.add(cg.include("cc1101_component.h"))

CONFIG_SCHEMA = sensor.sensor_schema().extend(
    {
        cv.GenerateID(): cv.declare_id(CC1101Sensor),
        cv.Required("spi_id"): cv.use_id(spi.SPIDevice),
    }
)

async def to_code(config):
    var = cg.new_Pvariable(config[cv.GenerateID()])
    await sensor.register_sensor(var, config)
    await cg.register_component(var, config)
    spi_dev = await cg.get_variable(config["spi_id"])
    cg.add(var.set_spi_device(spi_dev))

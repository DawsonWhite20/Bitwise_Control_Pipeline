#include "_74HC595.h"

#include "driver/spi_master.h"

#define PIN_SPICS 5

static spi_device_handle_t _74HC595_handle;

esp_err_t _74HC595_init(spi_host_device_t host_device) {
    spi_device_interface_config_t dev_config = {
        .clock_speed_hz = 1000000, // 1MHz
        .mode = 0, // (CPOL, CPHA) = (0, 0); Device idles at logical low and sampled at logical high
        .queue_size = 1,
        .spics_io_num = PIN_SPICS, // GPIO pin connected to ST_CP
    };

    ESP_ERROR_CHECK(spi_bus_add_device(host_device, &dev_config, &_74HC595_handle));

    return ESP_OK;
}

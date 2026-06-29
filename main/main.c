#include <stdio.h>
#include "esp_log.h"
#include "driver/spi_master.h";

#define PIN_MOSI 23
#define PIN_MISO -1
#define PIN_CLK 18

// Tag for testing with ESP
static const char *TAG = "MAIN";

void main(void) {   
    // ESP32 is the host device
    spi_host_device_t host_device;

    spi_bus_config_t bus_config = {
        .mosi_io_num = PIN_MOSI,
        .miso_io_num = PIN_MISO,
        .sclk_io_num = PIN_CLK,
        .quadwp_io_num = -1, // Quad mode not being used
        .quadhd_io_num = -1,
        .max_transfer_sz = 4092,
    };

    ESP_ERROR_CHECK(spi_bus_initialize(host_device, &bus_config, SPI_DMA_CH_AUTO));
}

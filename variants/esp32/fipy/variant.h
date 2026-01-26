/*
 * Pycom FiPy variant
 *
 * Based on LoPy4 configuration from Meshtastic forum:
 * https://meshtastic.discourse.group/t/pycom-lopy4-basic-functionality/7153
 *
 * FiPy pinout: https://docs.pycom.io/datasheets/development/fipy/
 *
 * Note: FiPy uses SX1276 LoRa chip. All DIO pins are wired through a diode
 * bridge to a single GPIO (23), so DIO0/1/2 all map to GPIO23.
 * LORA_RESET is not connected on Pycom boards.
 *
 * Errata reference:
 * https://forum.pycom.io/topic/3403/wiring-of-dio-pins-of-lora-sx127x-chip-to-esp32
 */

// Disable GPS (not present on FiPy module itself)
#undef GPS_RX_PIN
#undef GPS_TX_PIN

// I2C pins for FiPy (directly exposed on P9=SDA, P10=SCL header pins)
#define I2C_SDA 12
#define I2C_SCL 13

// WS2812 RGB LED on GPIO0
#define HAS_NEOPIXEL
#define NEOPIXEL_COUNT 1
#define NEOPIXEL_DATA 0
#define NEOPIXEL_TYPE (NEO_GRB + NEO_KHZ800)

// No user button on FiPy module
// #define BUTTON_PIN

// LoRa Radio - SX1276 (RF95 compatible)
#define USE_RF95

// SPI pins for LoRa (directly exposed on P4=CLK, P11=MOSI, P14=MISO header)
#define LORA_SCK 5
#define LORA_MISO 19
#define LORA_MOSI 27
#define LORA_CS 18 // LoRa/Sigfox Select (internal function on GPIO18)

// DIO pins - All wired through diode bridge to GPIO23
// See errata: https://forum.pycom.io/topic/3483/erratum-in-lopy4-specification-document
#define LORA_DIO0 23 // LoRa/Sigfox Interrupt (internal function on GPIO23)
#define LORA_DIO1 23 // Directly connected to DIO0 via diode bridge
#define LORA_DIO2 23 // Directly connected to DIO0 via diode bridge

// RESET is not connected on FiPy/LoPy4
#define LORA_RESET -1

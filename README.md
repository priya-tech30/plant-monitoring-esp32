# Plant Monitoring System (ESP32)

An IoT project that monitors a plant's soil moisture and the surrounding air using an ESP32. It reads the sensors every 2 seconds and prints the plant's status on the serial monitor.

## Components
- ESP32
- Soil moisture sensor (analog)
- DHT11 temperature and humidity sensor
- Jumper wires, breadboard

## Pin connections
| Component | ESP32 pin |
|---|---|
| Soil moisture sensor (analog out) | GPIO 34 |
| DHT11 (data) | GPIO 4 |
| Power | 3.3V and GND |

## How it works
1. The ESP32 reads the analog value from the soil moisture sensor.
2. The value is compared against thresholds:
   - Above 3200: **DRY**
   - Above 2500: **NEEDS WATER**
   - Otherwise: **MOIST**
3. The DHT11 reads air temperature and humidity.
4. Everything is printed on the serial monitor every 2 seconds.

## Sample output
Dry soil:

![Serial output when soil is dry](screenshots/dry.png)

After watering:

![Serial output after watering](screenshots/wet.png)

## Library required
- DHT sensor library by Adafruit (install from Arduino IDE Library Manager, along with Adafruit Unified Sensor)

## How to run
1. Open `plant_monitoring_esp32.ino` in Arduino IDE.
2. Select your ESP32 board and port.
3. Upload the code and open the Serial Monitor at 115200 baud.

## Future improvements
- Water pump that turns on automatically when the soil is dry
- Mobile app or cloud dashboard for remote monitoring
- Calibration of the soil thresholds for different plants

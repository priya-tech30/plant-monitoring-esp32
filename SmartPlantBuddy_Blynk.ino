#include "DHT.h"

#define SOIL_PIN 34
#define DHT_PIN 4
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void readSensors() {
  int soilValue = analogRead(SOIL_PIN);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.println("\n----- SMART PLANT BUDDY -----");

  Serial.print("Soil Raw Value: ");
  Serial.println(soilValue);

  if (soilValue > 3200)
    Serial.println("Soil Status: DRY");
  else if (soilValue > 2500)
    Serial.println("Soil Status: NEEDS WATER");
  else
    Serial.println("Soil Status: MOIST");

  if (!isnan(humidity) && !isnan(temperature)) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Air Humidity: ");
    Serial.print(humidity);
    Serial.println("%");
  } else {
    Serial.println("DHT11 reading failed!");
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Smart Plant Buddy Started!");
}

void loop() {
  readSensors();
  delay(2000);
}

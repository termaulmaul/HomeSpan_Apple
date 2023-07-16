#include "HomeSpan.h"
#include "LED.h"
#include "DEV_Identify.h"
#include "DEV_Sensors.h"
#include "DEV_RELAY.h"


void setup() {
  Serial.begin(115200);
  homeSpan.begin(Category::Bridges, "ESP32 Bridge");

  new SpanAccessory();
  new DEV_Identify("maul.Labs Smart System", "SmartHomeFactory", "123-ABC", "HS Bridge", "0.9", 3);
  new Service::HAPProtocolInformation();
  new Characteristic::Version("1.1.0");

  new SpanAccessory();
  new DEV_Identify("DHT11 Temp Sensor", "SmartHomeFactory", "123-ABC", "Sensor", "0.9", 0);
  // Create a Temperature Sensor (see DEV_Sensors.h for definition)
  new DEV_TempSensor();

  new SpanAccessory();
  new DEV_Identify("DHT11 Humidity Sensor", "SmartHomeFactory", "123-ABC", "Sensor", "0.9", 0);
  // Create a Humidity Sensor (see DEV_Sensors.h for definition)
  new DEV_HumSensor();

  // Accessory 1: LED
  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify();
    new LED(15); 

  // Accessory 2: Relay Switch 1
  new SpanAccessory();
    new Service::AccessoryInformation();    
      new Characteristic::Identify();                       
    new DEV_RELAY(17);  // instantiates a new relay on pin 17

  // Accessory 3: Relay Switch 2
  new SpanAccessory();
    new Service::AccessoryInformation();    
      new Characteristic::Identify();                       
    new DEV_RELAY(18);  // instantiates a new relay on pin 18

  // Accessory 3: Relay Switch 3
  new SpanAccessory();
    new Service::AccessoryInformation();    
      new Characteristic::Identify();                       
    new DEV_RELAY(19);  // instantiates a new relay on pin 18

}

void loop() {
  homeSpan.poll();
}

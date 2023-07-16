struct LED : Service::LightBulb {
  int ledPin;
  SpanCharacteristic *power;

  LED(int ledPin) : Service::LightBulb() {
    power = new Characteristic::On();
    this->ledPin = ledPin;
    pinMode(ledPin, OUTPUT);
  }

  bool update() {
    digitalWrite(ledPin, power->getNewVal());
    return true;
  }
};

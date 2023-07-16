struct DEV_RELAY : Service::Switch {
  int relayPin;
  SpanCharacteristic *power;

  DEV_RELAY(int relayPin) : Service::Switch() {
    power = new Characteristic::On();
    this->relayPin = relayPin;
    pinMode(relayPin, OUTPUT);
  }

  boolean update() {
    bool powerState = power->getNewVal();
    digitalWrite(relayPin, !powerState);  // Menggunakan negasi (!) untuk membalikkan nilai powerState
    return true;
  }
};

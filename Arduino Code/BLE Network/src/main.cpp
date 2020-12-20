#include <Arduino.h>
#include <ArduinoBLE.h>

#define RED 22
#define BLUE 24
#define GREEN 23
#define LED_PWR 25

BLEService ledservice("13649686-E822-422A-A54A-50896D5EC4C9");

void setup() {
  Serial.begin(9600);
  //pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  //pinMode(GREEN, OUTPUT);
  //pinMode(LED_PWR, OUTPUT);

  if(!BLE.begin())
  {
    Serial.println("starting BLE failed");

    while(1);
  }

  BLE.setLocalName("LED");
  BLE.advertise();
}

void loop() {
  BLEDevice central = BLE.central();

  if(central)
  {
    Serial.print("Connected to Central MAC: ");
    Serial.println(central.address());
    digitalWrite(BLUE, HIGH);
  }

  while(central.connected());

  digitalWrite(BLUE,LOW);
  Serial.print("Disconnected from central MAC: ");
  Serial.println(central.address());

  // digitalWrite(RED, HIGH);
  // digitalWrite(BLUE, LOW);
  // digitalWrite(GREEN, LOW);
  // Serial.println("RED");

  // delay(2000);

  // digitalWrite(RED, LOW);
  // digitalWrite(BLUE, HIGH);
  // digitalWrite(GREEN, LOW);
  // Serial.println("BLUE");

  // delay(2000);

  // digitalWrite(RED, LOW);
  // digitalWrite(BLUE, LOW);
  // digitalWrite(GREEN, HIGH);
  // Serial.println("GREEN");

  // delay(2000);

}
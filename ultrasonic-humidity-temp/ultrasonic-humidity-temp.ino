/*
* Ultrasonic Sensor HC-SR04 and DHT-11 humidity and temperature sensor
*/

#include "DHT.h"

// Define Constants

#define dhtPin 7
#define dhtType DHT11
#define trigPin 9
#define echoPin 10

// Define Variables

float humidity;
float temp;
long duration;
int distance;

DHT dht(dhtPin, dhtType);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin (9600);
  dht.begin();
}

void loop()
{

  delay(2000);

    humidity = dht.readHumidity();
    temp= dht.readTemperature();

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration*0.034/2;

    Serial.print("Humid: ");
    Serial.print(humidity);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.print(" C, ");
    Serial.print("Distance: ");

    if (distance >= 400 || distance <= 2) {
    Serial.print("Out of range");
    }
    else {
    Serial.println(distance);
    }
}

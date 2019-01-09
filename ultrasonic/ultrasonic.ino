/*
* Ultrasonic Sensor HC-SR04
*/

#define trigPin 9
#define echoPin 10
#define ledPin 4

long duration;
int distance;
const unsigned int upperThreshold = 250;
const unsigned int lowerThreshold = 100;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  if(distance>upperThreshold)
  {
    digitalWrite(ledPin, HIGH);
    Serial.println(distance);
  }
  else if(distance<lowerThreshold)
  {
    digitalWrite(ledPin, LOW);
    Serial.println(distance);
  }
}

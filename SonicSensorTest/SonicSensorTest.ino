#define trigPin1 12
#define echoPin1 13

long duration, distance, LeftSensor;
void setup() {
 Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);

}

void loop() {
Serial.print("Distance: ");   //debug line
SonarSensor(trigPin1, echoPin1);
LeftSensor = distance;

Serial.print(LeftSensor);
Serial.print(" - ");
}

void SonarSensor (int trigPin, int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
}

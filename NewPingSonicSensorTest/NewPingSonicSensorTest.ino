#include <NewPing.h>
//NewPing setup of pins and maximum distance
#define TRIGGER_PIN 12
#define ECHO_PIN 13
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters).

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(115200);   //Note: sample had a rate of 115200 baud. Will 9600 work?

}

void loop() {   //sample code borrowed from the internet
  delay(50);   // Wait 50ms between pings (about 20 pings/sec). 
                 // 29ms should be the shortest delay between pings.
    Serial.print("Ping: ");
    Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print 
                                   // result (0 = outside set distance range)
    Serial.println("cm");
}

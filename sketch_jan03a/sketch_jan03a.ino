
#include <DHT_U.h>
#define ctsPin 2 // Pin for capactitive touch sensor
#define kntpin 4

// int ledPin = 13; // pin for the LED
#define ledPin 13
#include <Adafruit_Sensor.h>

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

const int DHTPin = 5;     // what digital pin we're connected to
int n = 0;
DHT dht(DHTPin, DHTTYPE);
int mydelay = 300;
void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  pinMode(ledPin, OUTPUT);  
  pinMode(ctsPin, INPUT);
  pinMode(kntpin, INPUT);

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.

 int ctsValue = digitalRead(ctsPin);
 if (ctsValue==1) {
    if (mydelay==300){
      mydelay = 2000;  
    } else {
      mydelay = 300;
    }
    
    Serial.print("boton: ");
    Serial.println(ctsValue);    
 } 

  //delay(600);

  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }


  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  delay(mydelay);
}



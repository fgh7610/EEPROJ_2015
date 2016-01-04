#include <DHT.h>
#define DHTPIN 2    // what pin we're connected to
#define DHTTYPE DHT11   // DHT 22  (AM2302) 
int ledPin = 10;
int analogin0 = A0;
int analogin1 = A1;
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {

  Serial.begin(115200); 
  dht.begin();
}
 
void loop() {
  // Wait a few seconds between measurements.
  delay(2000); 
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  int val = analogRead(analogin0);
  int val1 = analogRead(analogin1);
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
 }     
  Serial.print(t);  
       Serial.print(" "); 
  Serial.print(h);  
       Serial.print(" "); 
  Serial.print((1023 - val) / 1023.0 * 100);
       Serial.print(" "); 
  Serial.println((1023 - val1) / 1023.0 * 100);

 
}

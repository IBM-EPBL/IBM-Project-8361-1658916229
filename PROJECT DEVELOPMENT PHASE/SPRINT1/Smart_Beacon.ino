#include <dht.h>

#define dht_apin A0                                               // Analog Pin 0 is connected to DHT sensor
#define mqt_apin A1                                               // Analog Pin 1 is connected to MQT 135 sensor
dht DHT;
int sensorValue;
 
void setup(){
 
  Serial.begin(9600);                                             
  Serial1.begin(9600);                                            
  delay(500);                                                
}
 
void loop(){
 
    DHT.read11(dht_apin);                                         
    sensorValue = analogRead(mqt_apin);

    //Send Humidity status to Python Code
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");

    //Send Temperature status to Python Code
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");

    //Send AirQuality sensor value to Python code
    Serial.print("AirQua=");
    Serial.print(sensorValue, DEC);                               
    Serial.println(" PPM");

    //Send signals to the Wearable
    Serial1.println("H T A");
    Serial1.println(DHT.humidity);
    Serial1.println(DHT.temperature);
    Serial1.println(sensorValue, DEC);
    
    delay(100);                                                  

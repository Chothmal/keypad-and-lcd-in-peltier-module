#define BLYNK_PRINT Serial  
#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>  
  
char auth[] = " r1EyjanS44ogJquagYoSyZ7S6fnOUxYK"; // the auth code that you got on your gmail and Blynk app  
char ssid[] = "OPPO F19"; // username or ssid of your WI-FI  
char pass[] = "7340270011"; // password of your Wi-Fi  
  
void setup()  
{  
// Debug console  
Serial.begin(9600);  
pinMode(D4,OUTPUT);  
   
digitalWrite(D4,HIGH);  
Blynk.begin(auth, ssid, pass);  
}  
  
void loop()  
{  
Blynk.run();  
}  

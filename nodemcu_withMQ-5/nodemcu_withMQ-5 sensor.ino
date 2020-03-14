//https://github.com/MinhazBicon

//Blynk MQ-2 Smoke Detector

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define BLYNK_PRINT Serial    // Commentout this to dissable print
char auth[] = "46Tfc6OEy01Lkm5v9T1fpYRvTjm6Qq_f"; //Enter Authentication code sent by Blynk app
 

char ssid[] = "NETGEAR50";  //Enter WIFI Name
char pass[] = "minhazbiconp@ssw0rd"; //Enter WIFI Password
 
SimpleTimer timer;
 
int mq2 = A0; // smoke sensor is connected with the analog pin A0 of your node mcu 
int data = 0; 
void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, getSendData);
}
 
void loop() 
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
}
 
void getSendData()
{
data = analogRead(mq2); 
  Blynk.virtualWrite(V2, data);
}

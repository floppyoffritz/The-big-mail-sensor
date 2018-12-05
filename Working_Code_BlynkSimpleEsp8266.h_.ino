#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

char auth[] = "d907d4e972544b41a107de9c9bd2bd35";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "iPhone";
char pass[] = "diarra10";

int fsrAnalogPin = A0; // FSR is connected to analog A0
     // connect Red LED to pin 11 (PWM pin)
int fsrReading;      // the analog reading from the FSR resistor divider
int LEDbrightness;


BlynkTimer timer;

void youHaveMail()
{
 
}

void setup()  
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  // Notify immediately on startup
  Blynk.notify("Checking For Mail...");
  // Setup a function to be called every minute
}

void loop()
{
  Blynk.run();
  timer.run();
  
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print("Analog reading = ");
  Serial.println(fsrReading);

  Blynk.virtualWrite(V1, fsrReading);

  if (fsrReading < 315){  
  Blynk.notify(String("You've Got Mail!"));
  }
  
  delay(1000);
  
}




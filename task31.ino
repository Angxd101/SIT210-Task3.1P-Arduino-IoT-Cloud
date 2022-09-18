#include "thingProperties.h"
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  dht.begin();
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();
  
 pinMode(LED_BUILTIN, OUTPUT);
  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(4);
  ArduinoCloud.printDebugInfo();
  
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  temp= dht.readTemperature();
  onLed_State();
  delay(30000); //Delay 30 sec.
  
  
}

void onLed_State()  {
  // Add your code here to act upon LedState change
  if (led_state)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

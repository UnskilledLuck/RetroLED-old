#include <FastLED.h>

#define LED_PIN 2
#define NUM_LEDS 140

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
int currentPin = -1;
int ledCounter = 0;
int ledOn = 0;
while(true){
  leds[ledOn] = CRGB(50,50,50);
  // if we're looking for input
  if (currentPin == -1) {
    /*for (int x = 0; x <= 10; x++){
      if (analogRead(x) > 0) {
        delay(1);
        if (analogRead(x) > 0) {
          currentPin = x;
		  Serial.println("input");
          Serial.println(currentPin);
          //Serial.println("value" + analogRead(currentPin));
        }
      }*/
    }
    delay(1);
  } 
  else { // We have input on a pin
    /*bool definitelyOn;
	leds[ledOn] = CRGB(0,0,0);
    switch (currentPin) {
      case 0: definitelyOn = masterSystem(currentPin); break;
      case 1: definitelyOn = megaDrive(currentPin); break;
      case 2: definitelyOn = saturn(currentPin); break;
      case 3: definitelyOn = dreamcast(currentPin); break;
      case 4: definitelyOn = playstation(currentPin); break;
      case 5: definitelyOn = playstation2(currentPin); break;
      case 6: definitelyOn = snes(currentPin); break;
      case 7: definitelyOn = n64(currentPin); break;
      case 8: definitelyOn = gamecube(currentPin); break;
      case 9: definitelyOn = wii(currentPin); break;
      case 10: definitelyOn = xbox(currentPin); break;
      default: Serial.println("Invalid state!");
    }
    if (definitelyOn == true) lightShow(currentPin);*/
    currentPin = -1;
  }
  if (ledCounter == 500){
	  Serial.println("led on");
	  leds[ledOn] = CRGB(0,0,0);
	  ledOn++;
	  ledCounter = 0;
  }
  ledCounter++;
  if (ledOn == 140) ledOn = 0;
}
} // end main loop
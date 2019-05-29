#include <FastLED.h>

#define LED_PIN 2
#define NUM_LEDS 140


CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:
//  for (int i = 0; i<= 139; i++) {
//    leds[i] = CRGB(255,0,0);
//    FastLED.show();
//    delay(30);
//  }
//
//  for (int i = 139; i>=0; i--){
//    leds[i] = CRGB(0,0,255);
//    FastLED.show();
//    delay(30);
//  }

// There are 25 notes in the gamecube opening. The lights turn on from 12 o'clock and rotate clockwise. 
// 140/25 is about 5 leds each with 6 3/5 times.

  int count = 1; // for working out when the 6th led is needed.
  for (int i = 0; i <= 139; ){
	  // turns off the previous leds. 
      for (int j = 6; j > 1; j--){
        int x = i + 20 - j; // The 20 is how many leds to the center of the screen
        if (x > 139) x = x - 140;
        if (x < 0) x = x + 140;
        leds[x] = CRGB(0,0,0);
      }
	  
	  //Turn on the next sequence of leds
      for (int j = 0; j < 4; j++){
        int x = i + 20;
        if (x > 139) x = x - 140;
        if (x < 0) x = x + 140;
        leds[x] = CRGB(75,0,130); // Indigo
        i++;
      }
	  
	  // Turn on an extra led if required
      if (count >= 1 && count <= 3){
        int x = i + 20;
        if (x > 139) x = x - 140;
        if (x < 0) x = x + 140;
        leds[x] = CRGB(75,0,130);
        i++;
      }
      count++;
      if (count == 6) count = 0;
      FastLED.show();
      delay (130); // timing between notes
    }
	
	// after sequence turn off leds
    for (int j = 8; j > 1; j--){
      int x = 22 - j;
      leds[x] = CRGB(0,0,0);
    }
    FastLED.show();
    delay (400); // wait for final note
	
	// Turn on all leds then fade
	int red = 75;
	int blue = 125;
	for (int i = 0; i <= 139; i++) {
		leds[i] = CRGB(red,0,blue);
	}
	while (red > 0){
		red--;
		blue--;
		for (int i = 0; i <= 139; i++) {
		  leds[i] = CRGB(red,0,blue);
		}
		blue--;
		FastLED.show();
		delay(1);
		for (int i = 0; i <= 139; i++) {
		  leds[i] = CRGB(red,0,blue);
		}
		blue--;
		red--;
		FastLED.show();
		delay(1);
		for (int i = 0; i <= 139; i++) {
		  leds[i] = CRGB(red,0,blue);
		}
		blue--;
		red--;
		FastLED.show();
		delay(1);
		for (int i = 0; i <= 139; i++) {
		  leds[i] = CRGB(red,0,blue);
		}
		blue--;
		FastLED.show();
		delay(1);
		for (int i = 0; i <= 139; i++) {
		  leds[i] = CRGB(red,0,blue);
		}
		FastLED.show();
		delay(1);
	}
    delay (5000);
    for (int i = 0; i <= 139; i++) {
      leds[i] = CRGB(0,0,0);
    }
    FastLED.show();
}

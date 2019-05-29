
#include <FastLED.h>

#define LED_PIN 2
#define NUM_LEDS 140

CRGB leds[NUM_LEDS];
int red = 10;
int green = 0;
int blue = 0;

bool checkPinReallyOn (int pin){
  int ms = 0;
  for (int x = 0; x < 40; x++) {
    if (analogRead(pin) > 0) ms++;
  }
  if (ms > 38) {
    return true;
  } else {
    return false;
  }
}

bool masterSystem(int pin){
  // Startup show
  if (checkPinReallyOn(pin) == true) {
    Serial.println("Master System");
    delay(5000);
    return true;
  } else return false;
} // end mastersystem

bool megaDrive(int pin){
  // Startup show
  if (checkPinReallyOn(pin) == true) {
    Serial.println("MegaDrive/Genesis");
    delay(5000);
	return true;
  } else return false;
} // end megadrive

bool saturn(int pin){
  // Startup show
  if (checkPinReallyOn(pin) == true){
    Serial.println("Saturn");
    delay(5000);
    return true;
  } else return false;
}// END SATURN

bool dreamcast(int pin){
  // Startup show
  if (checkPinReallyOn(pin) == true) {
    Serial.println("Dreamcast");
    delay(5000);
    return true;
  } else return false;
} // END DREAMCAST

bool playstation(int pin){
  // Startup show
  if (checkPinReallyOn(pin) == true){
    Serial.println("Playstation");
    delay(5000);
    return true;
  } else return false;
} // END PS

bool playstation2(int pin){
  // Startup show
  if (checkPinReallyOn(pin) == true){
    Serial.println("Playstation 2");
    delay(5000);
    return true;
  } else return false;
} // END PS2

bool snes(int pin){
  // Startup show
  if (checkPinReallyOn(pin) == true) {
    Serial.println("Super Nintendo");
    delay(5000);
    return true;
  } else return false;
} // END SNES

bool n64(int pin){
  // Startup show
  if (checkPinReallyOn(pin) == true){
    Serial.println("Nintendo 64");
    delay(5000);
    return true;
  } else return false;
} // END N64

bool gamecube(int pin){
  // Startup show  
  if (checkPinReallyOn(pin) == true){
    Serial.println("Game Cube");
    // There are 25 notes in the gamecube opening. The lights turn on from 12 o'clock and rotate clockwise. 
    // 140/25 is about 5 leds each with 6 3/5 times.
    
      int count = 1; // for working out when the 6th led is needed.
      delay(2000);
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

    return true;
  } else return false;
}// end gamecube

bool wii(int pin){
  // Startup show
  if (checkPinReallyOn(pin) == true){ 
	Serial.println("Wii");
    delay(5000);
    return true;
  } else return false;
} // END WII

bool xbox(int pin){
  // Startup show
  if (checkPinReallyOn(pin) == true){
    Serial.println("XBox");
    delay(5000);
    return true;
  } else return false;
}

bool lightShow(int pin){
  int count = 0; // counts the number of milliseconds the console outputs 0 volts
  Serial.println("Start Lightshow");
  int ledTime = 10;
  while (count < 100){ // if the console has had no signal for 100ms it will turn off the light show.
    // This is where the generic light show goes
    if (ledTime == 20) { // updates leds every 20ms
		// each led is equal to the value of the last.
      for (int i = 139; i >= 1; i--) {
        leds[i] = leds[i-1];
      }
    	leds[0] = CRGB(red,green,blue); // new led is given a colour
      if (leds[0] == leds[3]){ // leds are in blocks of 4. once a block has been finished the new colour is updated.
      	if (red == 10 && green < 10 && blue == 0) { green++; }
      	else if (green == 10 && blue < 10 && red == 0) { blue++; }
      	else if (blue == 10 && red < 10 && green == 0) { red++; }
      	else if (red == 10 && blue > 0) { blue--; }
      	else if (green == 10 && red > 0) { red--; }
      	else if (blue == 10 && green > 0) { green--; }
      }
      FastLED.show();
      ledTime = 0; // reset
    }
    ledTime++;
	// check if getting 0 volts. if we are increment.
    if (analogRead(pin) > 0) {
      count = 0;
    } else {
      count ++;
    }
    delay(1);
  }
  
  Serial.println("End Lightshow");
  // Turn off leds
  for (int i = 139; i >= 0; i--) {
    leds[i] = CRGB(0,0,0);
  }
}

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
    for (int x = 0; x <= 10; x++){
      if (analogRead(x) > 0) {
        delay(1);
        if (analogRead(x) > 0) {
          currentPin = x;
		  Serial.println("input");
          Serial.println(currentPin);
          //Serial.println("value" + analogRead(currentPin));
        }
      }
    }
    delay(1);
  } 
  else { // We have input on a pin
    bool definitelyOn;
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
    if (definitelyOn == true) lightShow(currentPin);
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

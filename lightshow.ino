
int currentPin = -1;

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
}

bool megaDrive(int pin){
  // Startup show
  bool on = checkPinReallyOn(pin);
  if (on == true) {
    Serial.println("MegaDrive/Genesis");
    delay(5000);
  }
  return on;
}

bool saturn(int pin){
  // Startup show
  int ms = 0;
  for (int x = 0; x < 40; x++) {
    if (analogRead(pin) > 0) ms++;
  }
  if (ms > 38){
    Serial.println("Saturn");
    delay(5000);
    return true;
  } else {
    return false;
  }
}

bool dreamcast(int pin){
  // Startup show
  int ms = 0;
  for (int x = 0; x < 40; x++) {
    if (analogRead(pin) > 0) ms++;
  }
  if (ms > 38) {
    Serial.println("Dreamcast");
    delay(5000);
    return true;
  } else {
    return false;
  }
}

bool playstation(int pin){
  // Startup show
  int ms = 0;
  for (int x = 0; x < 40; x++) {
    if (analogRead(pin) > 0) ms++;
  }
  if (ms > 38){
    Serial.println("Playstation");
    delay(5000);
    return true;
  } else {
    return false;
  }
}

bool playstation2(int pin){
  // Startup show
  int ms = 0;
  for (int x = 0; x < 40; x++) {
    if (analogRead(pin) > 0) ms++;
  }
  if (ms > 38){
    Serial.println("Playstation 2");
    delay(5000);
    return true;
  } else {
    return false;
  }
}

bool snes(int pin){
  // Startup show
  int ms = 0;
  for (int x = 0; x < 40; x++) {
    if (analogRead(pin) > 0) ms++;
  }
  if (ms > 38) {
    Serial.println("Super Nintendo");
    delay(5000);
    return true;
  } else {
    return false;
  }
}

bool n64(int pin){
  // Startup show
  int ms = 0;
  for (int x = 0; x < 40; x++) {
    if (analogRead(pin) > 0) ms++;
  }
  if (ms > 38){
    Serial.println("Nintendo 64");
    delay(5000);
    return true;
  } else {
    return false;
  }
}

bool gamecube(int pin){
  // Startup show
  int ms = 0;
  for (int x = 0; x < 40; x++) {
    if (analogRead(pin) > 0) ms++;
  }
  if (ms > 38){
    Serial.println("Game Cube");
    delay(5000);
    return true;
  } else {
    return false;
  }
}

bool wii(int pin){
  // Startup show
  int ms = 0;
  for (int x = 0; x < 40; x++) {
    if (analogRead(pin) > 0) ms++;
  }
  if (ms > 38){ Serial.println("Wii");
    delay(5000);
    return true;
  } else {
    return false;
  }
}

bool xbox(int pin){
  // Startup show
  int ms = 0;
  for (int x = 0; x < 40; x++) {
    if (analogRead(pin) > 0) ms++;
  }
  if (ms > 38){
    Serial.println("XBox");
    delay(5000);
    return true;
  } else {
    return false;
  }
}

bool lightShow(){
  int count = 0;
  Serial.println("Start Lightshow");
  while (count < 30){
    // This is where the generic light show goes
    
    if (analogRead(currentPin) > 0) {
      count = 0;
    } else {
      count ++;
    }
    delay(1);
  }
  Serial.println("End Lightshow");
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  // if we're looking for input
  if (currentPin == -1) {
    for (int x = 0; x <= 10; x++){
      if (analogRead(x) > 0) {
        delay(1);
        if (analogRead(x) > 0) {
          currentPin = x;
          Serial.println(currentPin);
          //Serial.println("value" + analogRead(currentPin));
        }
      }
    }
    delay(1);
  } 
  
  // We have input on a pin
  else {
    bool definitelyOn;
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
    if (definitelyOn == true) lightShow();
    currentPin = -1;
  }
  
} // end main loop

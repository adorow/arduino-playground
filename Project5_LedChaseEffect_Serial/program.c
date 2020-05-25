// Project 5 - LED Chase Effect (with the ability to change the ledDelay via Serial port)
// Create array for LED pins
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int ledDelay(65); // delay between changes
int direction = 1;
int currentLED = 0;
unsigned long changeTime;

void setup() {
  // we can communicate via Serial to read a new delay
  Serial.begin(9600);

  // set all pins to output
  for (int x = 0; x < 10; x++) {
    pinMode(ledPin[x], OUTPUT);
  }
  changeTime = millis();
}

void loop() {
  // if there are new entries, take the latest and use it
  while (Serial.available() > 0) {
    int newDelay = Serial.parseInt();
    if (newDelay > 0) {
      ledDelay = newDelay;
    }
    Serial.print(newDelay);
  }

  // if it has been ledDelay ms since last change
  if ((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }
}

void changeLED() {
  // turn off all LED's
  for (int x = 0; x < 10; x++) {
    digitalWrite(ledPin[x], LOW);
  }
  // turn on the current LED
  digitalWrite(ledPin[currentLED], HIGH);
  // increment by the direction value
  currentLED += direction;
  // change direction if we reach the end
  if (currentLED == 9) {
    direction = -1;
  }
  if (currentLED == 0) {
    direction = 1;
  }
}
// Project 5 - LED bouncing like a ball effect
// Create array for LED pins
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int ledDelay(65); // delay between changes
int direction = 1;
int currentLED = 0;
unsigned long changeTime;

int maxHeight = 9;

void setup() {
// set all pins to output
    for (int x=0; x<10; x++) {
        pinMode(ledPin[x], OUTPUT);
    }
    changeTime = millis();
}

void loop() {
    // if it has been ledDelay ms since last change
    if ((millis() - changeTime) > ledDelay) {
        changeLED();
        changeTime = millis();
    }
}

void changeLED() {
    // turn off all LED's
    for (int x=0; x<10; x++) {
        digitalWrite(ledPin[x], LOW);
    }
    // turn on the current LED
    digitalWrite(ledPin[currentLED], HIGH);

    // increment by the direction value
    currentLED += direction;

    // is going up
    if (direction == 1) {
        if (currentLED == maxHeight) {
            direction = -1;
            maxHeight = max(0, maxHeight - 1);
        }
    } else { // is going down
        if (currentLED == 0) {
            direction = 1;
        }
    }

    // restart at the end
    if (maxHeight == 0) maxHeight = 9;
}
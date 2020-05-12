/*
Project 1 - LED Flasher
*/

/*
 LED_BUILTIN refers to a LED that is built into most Arduino boards.
 This constant evaluates to the proper pin number (usually 14).
 Not sure what would happen (if anything) on boards that do not have a builtin LED.
 */

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(4000);
}

/*
Project 2 - S.O.S. Morse Code Signaler
*/

// LED connected to digital pin 10
const int ledPin = 10;

// units according to: https://en.wikipedia.org/wiki/Morse_code (https://upload.wikimedia.org/wikipedia/commons/thumb/b/b5/International_Morse_Code.svg/630px-International_Morse_Code.svg.png)
const int MORSE_UNIT = 100;
const int DOT = MORSE_UNIT * 1;
const int DASH = MORSE_UNIT * 3;
const int SPACE_BTWN_PARTS = MORSE_UNIT * 1;
const int SPACE_BTWN_LETTERS = MORSE_UNIT * 3;
const int SPACE_BTWN_WORDS = MORSE_UNIT * 7;

const int WAIT_BEFORE_REPEAT = 5000;

const char phrase[] = "SOS";

void setup() {
  // Board configuration
  pinMode(ledPin, OUTPUT);
}

void loop() {

  for (int i=0; i<strlen(phrase); i++) {
    if (i > 0) delay(SPACE_BTWN_LETTERS);
    char ch = tolower(phrase[i]);

    if (ch == ' ') {
      delay(SPACE_BTWN_WORDS);
    } else if ((ch >= 'a' && ch <= 'z') || ((ch >= '0' && ch <= '9'))) {
      char* sequence = lookup(ch);
      signal(sequence);
    } else {
      // not a valid character - ignore
    }

  }

  delay(WAIT_BEFORE_REPEAT);

}

char* lookup(char c) {
  switch(tolower(c)) {
    case 'a': return ".-";
    case 'b': return "-...";
    case 'c': return "-.-.";
    case 'd': return "-..";
    case 'e': return ".";
    case 'f': return "..-.";
    case 'g': return "--.";
    case 'h': return "....";
    case 'i': return "..";
    case 'j': return ".---";
    case 'k': return "-.-";
    case 'l': return ".-..";
    case 'm': return "--";
    case 'n': return "-.";
    case 'o': return "---";
    case 'p': return ".--.";
    case 'q': return "--.-";
    case 'r': return ".-.";
    case 's': return "...";
    case 't': return "-";
    case 'u': return "..-";
    case 'v': return "...-";
    case 'w': return ".--";
    case 'x': return "-..-";
    case 'y': return "-.--";
    case 'z': return "--..";

    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---...";
    case '9': return "----.";
    case '0': return "-----";

    default: return "";
  }
}

void signal(char* letter) {
  for (int i=0; i < strlen(letter);i++) {
    if (i > 0) delay(SPACE_BTWN_PARTS);
    digitalWrite(ledPin, HIGH);
    delay(letter[i] == '.' ? DOT : DASH);
    digitalWrite(ledPin, LOW);
  }
}



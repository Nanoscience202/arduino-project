#include <Arduino.h>

#define BUTTON 8
#define LED 7
#define CHECK 10

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(CHECK, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600);
}

void loop() {
  double counter = 0;

  // wait for input
  while (digitalRead(BUTTON) == LOW) {
  }

  // do stuff while it's pressed
  while (digitalRead(BUTTON) == HIGH) {
    digitalWrite(CHECK, HIGH);
    counter += 0.01;
    // microphone listen for words
    // use library to convert audio to text
    // store text in a string
  }
  digitalWrite(CHECK, LOW);

  // send data to python
  Serial.println(counter);
  // wait until data is sent
  Serial.flush();

  // read python response
  String word;

  while (1) {
    // read word
    char inByte = Serial.read();

    // if end of response, quit
    if (inByte = '\n') {
      break;
    }

    // check if it's the end of a word
    if (inByte = ' ') {
      // speaker speak the word
      word = "";
    } else {
      word.concat(inByte);
    }
  }
}

#line 1 "/Users/vincentliu/phys-project/Main/Main.ino"
#include <Arduino.h>

#define BUTTON 8
#define LED 7
#define CHECK 10

#line 7 "/Users/vincentliu/phys-project/Main/Main.ino"
void setup();
#line 15 "/Users/vincentliu/phys-project/Main/Main.ino"
void loop();
#line 7 "/Users/vincentliu/phys-project/Main/Main.ino"
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
  }
  digitalWrite(CHECK, LOW);

  // send data to python
  Serial.println(counter);
  // wait until data is sent
  Serial.flush();

  // read python response
  String res = Serial.readStringUntil('\n');

  // do stuff based on the response
  digitalWrite(LED, HIGH);
  delay(res.toInt());
  digitalWrite(LED, LOW);
}


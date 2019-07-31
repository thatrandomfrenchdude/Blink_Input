int led = 13; //not necessary

void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available() > 0) {
    int flashes = Serial.read() % 48;
    for (int i = 0; i < flashes; i++) {
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(200);
    }
  }
}

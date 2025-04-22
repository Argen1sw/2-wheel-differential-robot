volatile int count = 0;

void encoderISR() {
  count++;
}

void setup() {
  Serial.begin(115200);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), encoderISR, CHANGE);
}

void loop() {
  Serial.println(count);
  delay(500);
}
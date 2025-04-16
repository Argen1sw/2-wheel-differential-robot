#ifdef USE_BASE
#ifdef ARDUINO_ENC_COUNTER

volatile long left_enc_pos = 0;
volatile long right_enc_pos = 0;

void leftEncoderISR() {
  bool a = digitalRead(LEFT_ENC_PIN_A);
  bool b = digitalRead(LEFT_ENC_PIN_B);

  if (a == b) {
    left_enc_pos++;
  } else {
    left_enc_pos--;
  }
}

void rightEncoderISR() {
  bool a = digitalRead(RIGHT_ENC_PIN_A);
  bool b = digitalRead(RIGHT_ENC_PIN_B);

  if (a == b) {
    right_enc_pos++;
  } else {
    right_enc_pos--;
  }
}

void setupEncoders() {
  pinMode(LEFT_ENC_PIN_A, INPUT);
  pinMode(LEFT_ENC_PIN_B, INPUT);
  pinMode(RIGHT_ENC_PIN_A, INPUT);
  pinMode(RIGHT_ENC_PIN_B, INPUT);

  attachInterrupt(digitalPinToInterrupt(LEFT_ENC_PIN_A), leftEncoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(RIGHT_ENC_PIN_A), rightEncoderISR, CHANGE);
}

long readEncoder(int i) {
  if (i == LEFT) return left_enc_pos;
  else return right_enc_pos;
}

void resetEncoder(int i) {
  if (i == LEFT) {
    left_enc_pos = 0;
  } else {
    right_enc_pos = 0;
  }
}

void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif  // ARDUINO_ENC_COUNTER
#endif  // USE_BASE
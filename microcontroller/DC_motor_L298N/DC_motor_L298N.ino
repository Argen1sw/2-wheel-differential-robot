// Encoder output to Arduino Interrupt pin. Tracks the pulse count.
#define ENC_IN_RIGHT_A 6

volatile long right_wheel_pulse_count = 0;

int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

void setup() {

  // Open the serial port at 9600 bps
  Serial.begin(9600); 
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  // Set pin states of the encoder
  pinMode(ENC_IN_RIGHT_A , INPUT_PULLUP);
  // Every time the pin goes high, this is a pulse
  attachInterrupt(digitalPinToInterrupt(ENC_IN_RIGHT_A), right_wheel_pulse, RISING);
}

void loop() {
  
  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(9, 100); //ENA pin
  analogWrite(10, 200); //ENB pin

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(1000);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(1000);

  Serial.print(" Pulses: ");
  Serial.println(right_wheel_pulse_count);
}

// Increment the number of pulses by 1
void right_wheel_pulse() {
  right_wheel_pulse_count++;
}
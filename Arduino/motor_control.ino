#define POT A0
#define ENA 9
#define IN1 2
#define IN2 3

// Threshold value to prevent motor jitter around the center position (512)
const int DEADZONE = 40; 

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  // Ensure the motor is stopped at startup
  analogWrite(ENA, 0);
}

void loop() {
  int val = analogRead(POT);
  int center = 512;
  int diff = val - center;

  // If the potentiometer is within the deadzone, safely stop the motor
  if (abs(diff) < DEADZONE) {
    stopMotor();
    return;
  }

  // Map the remaining pot deviation to a 0-255 PWM speed value
  int speed = map(abs(diff), DEADZONE, 512, 0, 255);
  
  // Boundary checking to protect against speed value overflows
  if (speed < 0) speed = 0;
  if (speed > 255) speed = 255;

  // Determine motor direction and speed based on the potentiometer position
  if (diff > 0) {
    motorCW(speed);   // Clockwise rotation
  } else {
    motorCCW(speed);  // Counter-Clockwise rotation
  }
}

// Function to stop the motor safely
void stopMotor() {
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

// Function for Clockwise rotation
void motorCW(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed);
}

// Function for Counter-Clockwise rotation
void motorCCW(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speed);
}

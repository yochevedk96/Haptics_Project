// Simple stepper motor control using STEP and DIR pins

// Pin definitions
const int dirPin = 3;    // Direction pin
const int stepPin = 2;   // Step pin
const int enPin  = 8;    // Enable pin (optional)

// Motor control variables
int stepsPerRevolution = 2000; // Typical for 1.8° motors
int stepDelay = 500;         // Microseconds between steps (speed control)

void setup() {
  // Set pins as outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  //pinMode(enPin, OUTPUT);

  //digitalWrite(enPin, LOW);   // Enable driver (LOW active for most drivers)

  Serial.begin(9600);
  Serial.println("Stepper control ready");
}

void loop() {
  // Rotate motor clockwise
  digitalWrite(dirPin, HIGH);
  stepMotor(stepsPerRevolution);  // one revolution
  delay(1000);

  // Rotate motor counterclockwise
  digitalWrite(dirPin, LOW);
  stepMotor(stepsPerRevolution);
  delay(1000);
}

void stepMotor(int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelay);
  }
}

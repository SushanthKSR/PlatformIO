// Define pin connections
const int stepPin = 3; // Step pin connected to digital pin 3
const int dirPin = 4; // Direction pin connected to digital pin 4

void setup() {
  // Set the pinMode for step and direction pins as OUTPUT
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop() {
  // Set the direction to clockwise
  digitalWrite(dirPin, HIGH);
  
  // Step the motor 200 steps in one revolution
  for (int i = 0; i < 200; i++) {
    // Pulse the step pin with a delay between steps
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000); // Adjust this delay for your motor's speed
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000); // Adjust this delay for your motor's speed
  }

  delay(1000); // Wait for a second

  // Set the direction to counterclockwise
  digitalWrite(dirPin, LOW);

  // Step the motor 200 steps in the opposite direction
  for (int i = 0; i < 200; i++) {
    // Pulse the step pin with a delay between steps
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000); // Adjust this delay for your motor's speed
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000); // Adjust this delay for your motor's speed
  }

  delay(1000); // Wait for a second before the next rotation
}

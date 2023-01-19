// -------------------------------------------------
// Copyright (c) 2023 HiBit <https://www.hibit.dev>
// -------------------------------------------------

// Send to motor with jumper (no speed)
void sendToMotor(motor motor, int directionPin1, int directionPin2)
{
  // Set direction
  digitalWrite(directionPin1, motor.direction.input1);
  digitalWrite(directionPin2, motor.direction.input2);
}

// Send to motor without jumper
void sendToMotor(motor motor, int speedPin, int directionPin1, int directionPin2)
{
  // Set speed
  analogWrite(speedPin, motor.speed);

  // Set direction
  digitalWrite(directionPin1, motor.direction.input1);
  digitalWrite(directionPin2, motor.direction.input2);
}

// -------------------------------------------------
// Copyright (c) 2023 HiBit <https://www.hibit.dev>
// -------------------------------------------------

void sendToMotorA(motor motor)
{
  sendToMotor(motor, ENA, IN1, IN2);
}

void sendToMotorB(motor motor)
{
  sendToMotor(motor, ENB, IN3, IN4);
}

void sendToMotor(motor motor, int speedPin, int directionPin1, int directionPin2)
{
  // Set speed
  analogWrite(speedPin, motor.speed);

  // Set direction
  digitalWrite(directionPin1, motor.direction.input1);
  digitalWrite(directionPin2, motor.direction.input2);
}

// -------------------------------------------------
// Copyright (c) 2023 HiBit <https://www.hibit.dev>
// -------------------------------------------------

void setMotorSpeed(motor &motor, int speed)
{
  motor.speed = constrain(speed, 0, 255); // Force values between 0-255 (PWM)
}

void minMotorSpeed(motor &motor)
{
  setMotorSpeed(motor, 0);
}

void maxMotorSpeed(motor &motor)
{
  setMotorSpeed(motor, 255);
}

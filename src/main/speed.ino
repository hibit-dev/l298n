// -------------------------------------------------
// Copyright (c) 2023 HiBit <https://www.hibit.dev>
// -------------------------------------------------

void setMotorSpeed(motor &motor, int speed)
{
  motor.speed = max(0, min(255, speed)); // Force values between 0-255 (PWM)
}

void minMotorSpeed(motor &motor)
{
  setMotorSpeed(motor, 0);
}

void maxMotorSpeed(motor &motor)
{
  setMotorSpeed(motor, 255);
}

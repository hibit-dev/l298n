// -------------------------------------------------
// Copyright (c) 2023 HiBit <https://www.hibit.dev>
// -------------------------------------------------

void unsetMotorDirection(motor &motor)
{
  motor.direction.input1 = LOW;
  motor.direction.input2 = LOW;
}

void setMotorDirectionForward(motor &motor)
{
  motor.direction.input1 = HIGH;
  motor.direction.input2 = LOW;
}

void setMotorDirectionBackward(motor &motor)
{
  motor.direction.input1 = LOW;
  motor.direction.input2 = HIGH;
}

bool isMotorDirectionUnset(motor &motor)
{
  return motor.direction.input1 == LOW && motor.direction.input2 == LOW;
}

bool isMotorDirectionForward(motor &motor)
{
  return motor.direction.input1 == HIGH && motor.direction.input2 == LOW;
}

bool isMotorDirectionBackward(motor &motor)
{
  return motor.direction.input1 == LOW && motor.direction.input2 == HIGH;
}

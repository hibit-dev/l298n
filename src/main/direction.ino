// -------------------------------------------------
// Copyright (c) 2023 HiBit <https://www.hibit.dev>
// -------------------------------------------------

void unsetDirection(motor &motor)
{
  motor.direction.input1 = LOW;
  motor.direction.input2 = LOW;
}

void setDirectionForward(motor &motor)
{
  motor.direction.input1 = HIGH;
  motor.direction.input2 = LOW;
}

void setDirectionBackward(motor &motor)
{
  motor.direction.input1 = LOW;
  motor.direction.input2 = HIGH;
}

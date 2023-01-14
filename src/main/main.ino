// -------------------------------------------------
// Copyright (c) 2023 HiBit <https://www.hibit.dev>
// -------------------------------------------------

// Motor A
#define ENA 10 //PWM
#define IN1 9
#define IN2 8

// Motor B
#define ENB 3 //PWM
#define IN3 4
#define IN4 5

struct motor {
  byte speed = 0;

  struct {
    byte input1 = LOW;
    byte input2 = LOW;
  } direction;
};

motor motorA, motorB;

void setup()
{
  Serial.begin(115200);

  // Set speed & control pins to output for motor A
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Set speed & control pins to output for motor B
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Init with default values
  sendToMotorA(motorA);
  sendToMotorB(motorB);
}

void loop()
{
  Serial.println("Motors are stopped now");
  Serial.println("Set direction FORWARD");
  delay(2000);

  setDirectionForward(motorA);
  setDirectionForward(motorB);

  Serial.println("Gradually increase motors speed to max");

  increaseMotorsSpeed();

  Serial.println("Motors are on full speed now");
  delay(2000);
  Serial.println("Gradually decrease motors speed to min");

  decreaseMotorsSpeed();

  Serial.println("Motors are stopped now");
  Serial.println("Set direction BACKWARD");
  delay(2000);

  setDirectionBackward(motorA);
  setDirectionBackward(motorB);

  Serial.println("Gradually increase motors speed to max");

  increaseMotorsSpeed();

  Serial.println("Motors are on full speed now");
  delay(2000);
  Serial.println("Gradually decrease motors speed to min");

  decreaseMotorsSpeed();

}

void increaseMotorsSpeed()
{
  for (int speed = 0; speed <= 255; speed++) {
    setMotorSpeed(motorA, speed);
    setMotorSpeed(motorB, speed);

    sendToMotorA(motorA);
    sendToMotorB(motorB);

    delay(20); // Add small delay between changes
  }
}


void decreaseMotorsSpeed()
{
  for (int speed = 255; speed >= 0; speed--) {
    setMotorSpeed(motorA, speed);
    setMotorSpeed(motorB, speed);

    sendToMotorA(motorA);
    sendToMotorB(motorB);

    delay(20); // Add small delay between changes
  }
}

// -------------------------------------------------
// Copyright (c) 2023 HiBit <https://www.hibit.dev>
// -------------------------------------------------

// Motor A
#define ENA_PIN 10 //PWM
#define IN1_PIN 9
#define IN2_PIN 8

// Motor B
#define ENB_PIN 3 //PWM
#define IN3_PIN 4
#define IN4_PIN 5

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

  // Set PWM & direction pins to output for both motor
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);

  pinMode(ENB_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);

  // Init with default values
  sendToMotorA();
  sendToMotorB();
}

void loop()
{
  Serial.println("Motors are stopped now");
  Serial.println("Set direction FORWARD");
  delay(2000);

  setMotorDirectionForward(motorA);
  setMotorDirectionForward(motorB);

  Serial.println("Gradually increase motors speed to max");

  increaseMotorsSpeed();

  Serial.println("Motors are on full speed now");
  delay(2000);
  Serial.println("Gradually decrease motors speed to min");

  decreaseMotorsSpeed();

  Serial.println("Motors are stopped now");
  Serial.println("Set direction BACKWARD");
  delay(2000);

  setMotorDirectionBackward(motorA);
  setMotorDirectionBackward(motorB);

  Serial.println("Gradually increase motors speed to max");

  increaseMotorsSpeed();

  Serial.println("Motors are on full speed now");
  delay(2000);
  Serial.println("Gradually decrease motors speed to min");

  decreaseMotorsSpeed();

}

void sendToMotorA()
{
  sendToMotor(motorA, ENA_PIN, IN1_PIN, IN2_PIN);
}

void sendToMotorB()
{
  sendToMotor(motorB, ENB_PIN, IN3_PIN, IN4_PIN);
}

void increaseMotorsSpeed()
{
  for (int speed = 0; speed <= 255; speed++) {
    setMotorSpeed(motorA, speed);
    setMotorSpeed(motorB, speed);

    sendToMotorA();
    sendToMotorB();

    delay(20); // Add small delay between changes
  }
}


void decreaseMotorsSpeed()
{
  for (int speed = 255; speed >= 0; speed--) {
    setMotorSpeed(motorA, speed);
    setMotorSpeed(motorB, speed);

    sendToMotorA();
    sendToMotorB();

    delay(20); // Add small delay between changes
  }
}

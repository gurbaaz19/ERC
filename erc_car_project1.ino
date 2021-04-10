  // Left Motor (A)
  int enableA = 10;
  int input1 = 9;
  int input2 = 8;
  // Right Motor (B)
  int enableB = 5;
  int input3 = 7;
  int input4 = 6;

  void setup()
  {
    // Declare motor control pins to be in output
    pinMode(enableA, OUTPUT);
    pinMode(enableB, OUTPUT);
    pinMode(input1, OUTPUT);
    pinMode(input2, OUTPUT);
    pinMode(input3, OUTPUT);
    pinMode(input4, OUTPUT);
    pinMode(13, OUTPUT);
    Serial.begin(115200);
    // A 2s delay before starting main loop
    // The LED at pin 13 will turn on for ~2s to indicate delay
    digitalWrite(13, HIGH);
    delay(1900);
    digitalWrite(13, LOW);
    delay(100);
  }

  void moveBot(bool dir, int spd)
  {
    // Motor A
    digitalWrite(input1, dir);
    digitalWrite(input2, !dir);
    // Motor B
    digitalWrite(input3, dir);
    digitalWrite(input4, !dir);
    // Set motor speed to spd
    analogWrite(enableA, spd);
    analogWrite(enableB, spd);
  }

  void clockwiseBot(bool dir, int spd)
  {
    // Motor A
    digitalWrite(input1, dir);
    digitalWrite(input2, !dir);
    // Motor B
    digitalWrite(input3, dir);
    digitalWrite(input4, !dir);
    // Set motor speed to spd
    analogWrite(enableA, spd);
    analogWrite(enableB, 0);
  }

  void anticlockwiseBot(bool dir, int spd)
  {
    // Motor A
    digitalWrite(input1, dir);
    digitalWrite(input2, !dir);
    // Motor B
    digitalWrite(input3, dir);
    digitalWrite(input4, !dir);
    // Set motor speed to spd
    analogWrite(enableA, 0);
    analogWrite(enableB, spd);
  }

  void circleBot(bool dir, int spd)
  {
    // Motor A
    digitalWrite(input1, dir);
    digitalWrite(input2, !dir);
    // Motor B
    digitalWrite(input3, !dir);
    digitalWrite(input4, dir);
    // Set motor speed to spd
    analogWrite(enableA, spd);
    analogWrite(enableB, spd - 50);
    //Rotation Duration
  }

  //Turn off both motors
  void stopMotors()
  {
    //digitalWrite(input1, LOW);
    //digitalWrite(input2, LOW);
    //digitalWrite(input3, LOW);
    //digitalWrite(input4, LOW);
    analogWrite(enableA, 0);
    analogWrite(enableB, 0);
  }

  void loop()
  {
    while (Serial.available() == 0)
    {
      Serial.println("Enter a command");
      delay(100);
    }
    if (Serial.readString() == "Forward")
    {
      // Move forward for 2s at a speed of 200
      Serial.println("Forward");
      moveBot(true, 200);
    }
    if (Serial.readString() == "Clockwise")
    {
      // Move forward for 2s at a speed of 200
      Serial.println("Clockwise");
      clockwiseBot(true, 200);
    }
    if (Serial.readString() == "Anticlockwise")
    {
      // Move forward for 2s at a speed of 200
      Serial.println("Anticlockwise");
      clockwiseBot(false, 200);
    }
    //Move bot in a circle
    if (Serial.readString() == "Circle")
    {
      Serial.println("Circle");
      circleBot(false, 200);
    }

    // Stop motors
    if (Serial.readString() == "Stop")
    {
      Serial.println("Stop");
      stopMotors();
    }
  }
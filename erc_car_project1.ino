// Left Motor (A)
int enableA = 10;
int input1 = 9;
int input2 = 8;
// Right Motor (B)
int enableB = 5;
int input3 = 7;
int input4 = 6;
int RPM = 586;
float T = (60 / 586); //Time for one revolution
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
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
  digitalWrite(input3, LOW);
  digitalWrite(input4, LOW);
  analogWrite(enableA, 0);
  analogWrite(enableB, 0);
  Serial.begin(115200);
  // A 2s delay before starting main loop
  // The LED at pin 13 will turn on for ~2s to indicate delay
  digitalWrite(13, HIGH);
  delay(1900);
  digitalWrite(13, LOW);
  delay(100);
}

void loop()
{
  //Serial.available()=0;
  while (Serial.available() == 0)
  {
    Serial.println("Enter a command");
    delay(100);
  }
  if (Serial.readString() == "Forward")
  {
    Serial.println("Forward");
    // Motor A
    digitalWrite(input1, true);
    digitalWrite(input2, false);
    // Motor B
    digitalWrite(input3, true);
    digitalWrite(input4, false);
    analogWrite(enableA, 255);
    analogWrite(enableB, 255);
  }
  else if (Serial.readString() == "Clockwise")
  {
    Serial.println("Clockwise");
    //Motor A
    digitalWrite(input1, true);
    digitalWrite(input2, false);
    // Motor B
    digitalWrite(input3, true);
    digitalWrite(input4, false);
    analogWrite(enableA, 255);
    analogWrite(enableB, 0);
    delay(T / 4);
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    digitalWrite(input3, LOW);
    digitalWrite(input4, LOW);
    analogWrite(enableA, 0);
    analogWrite(enableB, 0);
  }
  else if (Serial.readString() == "Anticlockwise")
  {
    Serial.println("Anticlockwise");
    //Motor A
    digitalWrite(input1, false);
    digitalWrite(input2, true);
    // Motor B
    digitalWrite(input3, false);
    digitalWrite(input4, true);
    analogWrite(enableA, 0);
    analogWrite(enableB, 255);
    delay(T / 4);
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    digitalWrite(input3, LOW);
    digitalWrite(input4, LOW);
    analogWrite(enableA, 0);
    analogWrite(enableB, 0);
  }
  //Move bot in a circle
  else if (Serial.readString() == "Circle")
  {
    Serial.println("Circle");
    //Motor A
    digitalWrite(input1, true);
    digitalWrite(input2, false);
    // Motor B
    digitalWrite(input3, true);
    digitalWrite(input4, false);
    analogWrite(enableA, 255);
    analogWrite(enableB, 100);
  }

  // Stop motors
  else if (Serial.readString() == "Stop")
  {
    Serial.println("Stop");
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    digitalWrite(input3, LOW);
    digitalWrite(input4, LOW);
    analogWrite(enableA, 0);
    analogWrite(enableB, 0);
  }
}

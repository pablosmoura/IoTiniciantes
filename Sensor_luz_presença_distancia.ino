// C++ code
//
int distancia = 0;

int presenca = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(A5, INPUT);
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  Serial.println(analogRead(A5));
  if (analogRead(A5) > 450) {
    Serial.println("Esta escuro");
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
  } else {
    Serial.println("Esta claro");
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
  delay(1000); // Wait for 1000 millisecond(s)

  presenca = digitalRead(7);
  if (digitalRead(7) == 1) {
    tone(6, 523, 1000); // play tone 60 (C5 = 523 Hz)
  }
  delay(1000); // Wait for 1000 millisecond(s)

  distancia = 0.01723 * readUltrasonicDistance(10, 9);
  if (distancia <= 100) {
    digitalWrite(3, HIGH);
    digitalWrite(8, LOW);
  } else {
    digitalWrite(3, LOW);
    digitalWrite(8, HIGH);
  }
}
// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(4, OUTPUT);

  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(4, HIGH);
  delay(3000); // Wait for 3000 millisecond(s)
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(4, HIGH);
}
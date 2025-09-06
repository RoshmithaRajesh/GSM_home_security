
int statusLED = 12;
int alarmLED = 8;
int pirSensorPin = 5;

int Gnd1 = 13;
int Gnd2 = 9;

void setup() {
  Serial.begin(9600);

  pinMode(statusLED, OUTPUT);
  pinMode(alarmLED, OUTPUT);
  pinMode(Gnd1, OUTPUT);
  pinMode(Gnd2, OUTPUT);
  pinMode(pirSensorPin, INPUT);

  digitalWrite(Gnd1, LOW);
  digitalWrite(Gnd2, LOW);
  digitalWrite(statusLED, LOW);
  digitalWrite(alarmLED, LOW);

  delay(15000);
  digitalWrite(statusLED, HIGH);   // System ready indicator
}

void loop() {
  if (digitalRead(pirSensorPin) == HIGH) {
    digitalWrite(alarmLED, HIGH);
    Serial.println("Motion detected!");
    
    Serial.println("ATD+918075672633;");   // Replace with your number
    delay(15000);   // Wait for call duration

    Serial.println("ATH");
    digitalWrite(alarmLED, LOW);
    delay(1000);
  }
}

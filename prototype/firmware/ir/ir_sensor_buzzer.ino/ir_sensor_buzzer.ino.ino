#define IR_SENSOR 18
#define BUZZER 25

void setup() {
  Serial.begin(115200);

  pinMode(IR_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(BUZZER, LOW);

  Serial.println("IR Sensor + Buzzer Started...");
}

void loop() {

  int sensorState = digitalRead(IR_SENSOR);

  if (sensorState == LOW) {

    Serial.println("OBJECT DETECTED");

    digitalWrite(BUZZER, HIGH);
    delay(200);

    digitalWrite(BUZZER, LOW);
    delay(200);

  } else {

    Serial.println("NO OBJECT");

    digitalWrite(BUZZER, LOW);
    delay(200);
  }
}
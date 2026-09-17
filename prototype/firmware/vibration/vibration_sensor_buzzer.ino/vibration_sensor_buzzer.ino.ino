#define VIBRATION_PIN 27
#define BUZZER 26

// SW-420 common logic:
// LOW  = VIBRATION
// HIGH = NO VIBRATION
#define VIBRATION_STATE LOW

// Number of readings used for confirmation
#define SAMPLE_COUNT 5

bool vibrationDetected = false;

bool checkVibration() {

  int vibrationCount = 0;

  for (int i = 0; i < SAMPLE_COUNT; i++) {

    if (digitalRead(VIBRATION_PIN) == VIBRATION_STATE) {
      vibrationCount++;
    }

    delay(10);
  }

  // Majority of readings must indicate vibration
  return vibrationCount >= 3;
}

void setup() {

  Serial.begin(115200);

  pinMode(VIBRATION_PIN, INPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(BUZZER, LOW);

  delay(1000);

  Serial.println();
  Serial.println("================================");
  Serial.println(" ESP32 VIBRATION SENSOR + BUZZER");
  Serial.println("================================");
  Serial.println("System Ready...");
  Serial.println();
}

void loop() {

  bool currentVibration = checkVibration();

  // Vibration START
  if (currentVibration && !vibrationDetected) {

    vibrationDetected = true;

    Serial.println(">>> VIBRATION DETECTED <<<");

    digitalWrite(BUZZER, HIGH);
  }

  // Vibration STOP
  if (!currentVibration && vibrationDetected) {

    vibrationDetected = false;

    Serial.println(">>> VIBRATION STOPPED <<<");

    digitalWrite(BUZZER, LOW);
  }

  delay(50);
}
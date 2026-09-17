/*
  Smart Conveyor Inspection System
  --------------------------------
  Current Prototype

  Hardware:
  - ESP32
  - 2 IR sensors sharing GPIO 18
  - SW-420 vibration sensor on GPIO 27
  - IR alert buzzer on GPIO 25
  - Vibration alert buzzer on GPIO 26

  IR logic:
  LOW  = Object detected
  HIGH = No object

  Vibration logic:
  LOW  = Vibration detected
  HIGH = No vibration
*/

#define IR_SENSOR 18
#define IR_BUZZER 25

#define VIBRATION_PIN 27
#define VIBRATION_BUZZER 26

#define VIBRATION_STATE LOW
#define SAMPLE_COUNT 5

bool vibrationDetected = false;
bool irDetected = false;


// --------------------------------------------------
// VIBRATION CHECK
// --------------------------------------------------

bool checkVibration() {

  int vibrationCount = 0;

  for (int i = 0; i < SAMPLE_COUNT; i++) {

    if (digitalRead(VIBRATION_PIN) == VIBRATION_STATE) {
      vibrationCount++;
    }

    delay(10);
  }

  return vibrationCount >= 3;
}


// --------------------------------------------------
// SETUP
// --------------------------------------------------

void setup() {

  Serial.begin(115200);

  pinMode(IR_SENSOR, INPUT);
  pinMode(IR_BUZZER, OUTPUT);

  pinMode(VIBRATION_PIN, INPUT);
  pinMode(VIBRATION_BUZZER, OUTPUT);

  digitalWrite(IR_BUZZER, LOW);
  digitalWrite(VIBRATION_BUZZER, LOW);

  delay(1000);

  Serial.println();
  Serial.println("==========================================");
  Serial.println(" SMART CONVEYOR INSPECTION PROTOTYPE");
  Serial.println("==========================================");
  Serial.println("ESP32 System Ready");
  Serial.println();
}


// --------------------------------------------------
// MAIN LOOP
// --------------------------------------------------

void loop() {

  // ---------------- IR SENSOR ----------------

  int irState = digitalRead(IR_SENSOR);

  if (irState == LOW) {

    if (!irDetected) {

      irDetected = true;

      Serial.println("[IR] OBJECT DETECTED");
    }

    // Alert buzzer
    digitalWrite(IR_BUZZER, HIGH);

  } else {

    if (irDetected) {

      irDetected = false;

      Serial.println("[IR] NO OBJECT");
    }

    digitalWrite(IR_BUZZER, LOW);
  }


  // ---------------- VIBRATION ----------------

  bool currentVibration = checkVibration();

  if (currentVibration && !vibrationDetected) {

    vibrationDetected = true;

    Serial.println("[VIBRATION] VIBRATION DETECTED");

    digitalWrite(VIBRATION_BUZZER, HIGH);
  }

  if (!currentVibration && vibrationDetected) {

    vibrationDetected = false;

    Serial.println("[VIBRATION] VIBRATION STOPPED");

    digitalWrite(VIBRATION_BUZZER, LOW);
  }


  delay(50);
}
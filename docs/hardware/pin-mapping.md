# ESP32 Prototype Pin Mapping

| Component | ESP32 GPIO | Function |
|---|---:|---|
| IR Sensor 1 | GPIO 18 | IR detection |
| IR Sensor 2 | GPIO 18 | Shared IR detection input |
| IR Buzzer | GPIO 25 | IR alert |
| Vibration Sensor | GPIO 27 | Vibration detection |
| Vibration Buzzer | GPIO 26 | Vibration alert |

## Important Note

Both IR sensors currently share GPIO 18.

Therefore, the current prototype treats their signal as a shared/combined input. Individual IR sensor identification is not available in the current wiring.

Separate GPIO inputs can be assigned in a future hardware revision if independent sensor identification is required.
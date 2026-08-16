// Automatic plant watering system
const int SENSOR_PIN = A0;   // Capacitive sensor input
const int RELAY_PIN = 8;     // relay control output

// Calibration
const int AIR_VALUE = 490;   // 0% Moisture or fully dry
const int WATER_VALUE = 204; // 100% Moisture or fully wet

// Trigger threshold in Percentage
const int WATERING_THRESHOLD_PERCENT = 30; // Water plant when soil drops below 30% moisture

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  
  // Ensure relay starts turned off
  digitalWrite(RELAY_PIN, LOW); 
}

void loop() {
  int rawValue = analogRead(SENSOR_PIN);
  
  // Map values (490 -> 204) to percentage (0% -> 100%)
  int moisturePercent = map(rawValue, AIR_VALUE, WATER_VALUE, 0, 100);
  
  // Keep percentage bounded between 0% and 100%
  moisturePercent = constrain(moisturePercent, 0, 100);

  // print readable data to Serial Monitor
  Serial.print("Raw Sensor: ");
  Serial.print(rawValue);
  Serial.print(" | Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  // check if moisture dropped below 30% threshold
  if (moisturePercent < WATERING_THRESHOLD_PERCENT) {
    Serial.println("ALERT: Soil moisture is low! Activating pump...");
    
    digitalWrite(RELAY_PIN, HIGH); // turn pump on
    delay(3000);                   // run pump for 3 seconds
    digitalWrite(RELAY_PIN, LOW);  // turn pump off
    
    delay(10000);                  // wait 10 seconds for water to soak into soil
  } else {
    Serial.println("STATUS: Moisture level optimal.");
  }

  delay(2000); // check moisture every 2 seconds
}

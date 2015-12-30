int RELAY_1 = 2;
int LED_1 = 13;

bool enabled = false;

void setup() {
  pinMode(RELAY_1, OUTPUT);  
  pinMode(LED_1, OUTPUT);
  digitalWrite(RELAY_1, LOW);
  digitalWrite(LED_1, LOW);
  enabled = false;
}

void loop() {
  delay(5000);
  
  if (enabled) {
    digitalWrite(RELAY_1, LOW);
    digitalWrite(LED_1, LOW);
  } else {
    digitalWrite(RELAY_1, HIGH);
    digitalWrite(LED_1, HIGH);
  }
  
  enabled = !enabled;
}

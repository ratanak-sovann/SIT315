/*  
    Arduino with PIR motion sensor and LED
    Sense-Think-Act System
*/

int led = LED_BUILTIN;       // The pin for the LED
int sensor = 2;              // The pin for the PIR motion sensor
int motionFlag = LOW;        // System status (motion detected or not)
int sensorValue = 0;         // To store the sensor reading

void setup() {
  pinMode(led, OUTPUT);      // Set LED pin as output
  pinMode(sensor, INPUT);    // Set PIR sensor pin as input
  Serial.begin(9600);        // Initialize Serial for monitoring
}

void loop(){
  // Sense: Read sensor value
  sensorValue = digitalRead(sensor);   

  // Think: Update motion flag based on sensor value
  if (sensorValue == HIGH) {           // If motion is detected
    motionFlag = HIGH;
    Serial.println("Motion detected!");  // Print status to Serial
  } 
  else {                               // If no motion is detected
    motionFlag = LOW;
    Serial.println("No motion detected!");  // Print status to Serial
  }

  // Act: Turn LED on/off based on motionFlag
  if (motionFlag == HIGH) {
    digitalWrite(led, HIGH);   // Turn LED ON
    Serial.println("LED ON");  // Print actuator status to Serial
  } 
  else {
    digitalWrite(led, LOW);    // Turn LED OFF
    Serial.println("LED OFF"); // Print actuator status to Serial
  }

  delay(500);  // Wait for 500ms before next loop
}

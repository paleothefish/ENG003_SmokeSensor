// Define the pin connections
#define LED_PIN 12
#define MEASURE_PIN A1
#define RED_LED1 8
#define RED_LED2 7
#define RED_LED3 4

// Define the sampling parameters
#define SAMPLE_TIME_MS 280
#define DELAY_TIME_MS 80
#define LED_OFF_DELAY_TIME_MS 9680

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
  
  // Configure the pins
  pinMode(LED_PIN, OUTPUT);
  pinMode(MEASURE_PIN, INPUT);
}

void loop() {
  // Turn on the LED
  digitalWrite(LED_PIN, LOW);
  
  // Wait for the sample time
  delayMicroseconds(SAMPLE_TIME_MS);
  
  // Take a measurement
  float measure = analogRead(MEASURE_PIN);
  
  // Wait for the rest of the sample time
  delayMicroseconds(DELAY_TIME_MS);
  
  // Turn off the LED
  digitalWrite(LED_PIN, HIGH);
  
  // Wait for the LED to turn off
  delayMicroseconds(LED_OFF_DELAY_TIME_MS);
  
  // Print the measurement to the serial monitor
  Serial.println(measure);

  if (measure > 300.0) {
    digitalWrite(RED_LED1, HIGH);
    digitalWrite(RED_LED2, HIGH);
    digitalWrite(RED_LED3, HIGH);
  } else {
    digitalWrite(RED_LED1, LOW);
    digitalWrite(RED_LED2, LOW);
    digitalWrite(RED_LED3, LOW);
  }
}

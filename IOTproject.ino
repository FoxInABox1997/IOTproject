/*Noise Detector
 * This sketch reads in a a sound such as a baby's cry.
 * It should rad in the noise and compare it to the threshold.
 * If the noise is above the threshold level the light will turn on.
 * It will also output a message.
 * Once the noise goes below the threshold level the light will go off.


 */


// these constants won't change:
const int ledPin = 8;      // led connected to digital pin 13
const int noiseSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 20;  // threshold value to decide when the the light turns on.


// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin
int ledState = LOW;         // variable used to store the last LED status, to toggle the light

void setup() {
  pinMode(ledPin, OUTPUT); // declare the ledPin as as OUTPUT
  Serial.begin(9600);       // use the serial port
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(noiseSensor);

  // if the sensor reading is greater than the threshold:
  if (sensorReading >= threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, HIGH);
    // send the string "Shush!" back to the computer, followed by newline
    Serial.println("Shush!");
  }
  delay(100);  // delay to avoid overloading the serial port buffer
}

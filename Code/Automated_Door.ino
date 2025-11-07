#include <Servo.h> 
// Pin definitions 
const int pirPin = 2;     
// PIR sensor pin (outside) 
const int trigPin = 3;    // Ultrasonic sensor Trig pin (inside) 
const int echoPin = 4;    // Ultrasonic sensor Echo pin (inside) 
const int servoPin = 9;   // Servo motor control pin 
// Threshold distance (in cm) 
const int distanceThreshold = 20; 
// Servo object 
Servo myServo; 
void setup() { 
pinMode(pirPin, INPUT); 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
myServo.attach(servoPin); 
myServo.write(0); // Keep the door closed initially 
Serial.begin(9600); // Start serial communication 
Serial.println("System Initialized"); 
} 
void loop() { 
// Read PIR sensor (outside motion detection) 
bool motionDetected = digitalRead(pirPin) == HIGH; 
// Read distance from ultrasonic sensor (inside obstacle 
detection) 
long distance = measureDistance(); 
// Print sensor readings to Serial Monitor with a slower rate 
Serial.print("Motion: "); 
Serial.print(motionDetected ? "Detected" : "Not Detected"); 
Serial.print(" | Distance: "); 
Serial.print(distance); 
Serial.println(" cm"); 
// Act based on sensor data 
if (motionDetected) { 
if (distance > distanceThreshold) { 
Serial.println("Motion detected, and no obstacle inside. 
Opening door..."); 
myServo.write(90); // Open the door 
delay(5000);       
// Keep the door open for 5 seconds 
myServo.write(0);  // Close the door 
Serial.println("Door closed."); 
} else { 
Serial.println("Motion detected, but obstacle inside. Door 
can't be opened."); 
} 
} else if (distance <= distanceThreshold) { 
Serial.println("Obstacle detected inside, but no motion 
outside. Door remains closed."); 
} 
delay(1000); // Slower delay for better understanding of 
serial monitoring 
} 
long measureDistance() { 
// Send a 10us pulse to the Trig pin 
digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(trigPin, LOW); 
// Read the Echo pin and calculate distance 
long duration = pulseIn(echoPin, HIGH); 
long distance = duration * 0.034 / 2; // Convert to cm 
return distance; 
}
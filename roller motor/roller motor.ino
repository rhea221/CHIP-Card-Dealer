// #include <Servo.h>
// Servo myservo;

// void setup() {
//   myservo.attach(8); //attaches the servo on pin 9 
//     myservo.write(80); //rotate counterclockwise at slow speed
// }

// void loop() {
//   currentTime = millis();
//   if ()
// }


#include <Servo.h>
Servo myServo;        // Create Servo object to control the servo 

//YELLOW DC MOTOR PINS
int ena = 5;
int in1 = 6;
int in2 = 7;

void setup() { 
  myServo.attach(8);  // Servo is connected to digital pin 9 

  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
} 

void loop() { 
  myServo.writeMicroseconds(2000);    // turns forward at maximum speed
  delay(200);   // run for 2 ms
  myServo.writeMicroseconds(1500);    // stop
  delay(200);   // run for 2 ms
  myServo.writeMicroseconds(1000);    // turns backwards at maximum speed
  delay(200);   // run for 2 ms
  myServo.writeMicroseconds(1500);
 

  //MOTOR CODE
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena, 255);
  delay(2000);
  
}
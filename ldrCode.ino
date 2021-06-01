#include <Servo.h> // include the servo library
Servo servoMotor;
int ledVerde = 13; 
int ledRojo = 12;
int lecturasensor1;
int lecturasensor2;
int servoPin = 2; // Pin de control del Servo

void setup() {
  servoMotor.attach(servoPin);
  servoMotor.write(1); // bajada de barrera
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
}
void loop() {
  lecturasensor1 = analogRead(A0);
  lecturasensor2 = analogRead(A2);
  
  Serial.println(lecturasensor1);
  Serial.println(lecturasensor2);
  
  if (lecturasensor1 > 550) {
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
  } else {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRojo, LOW);
  }

  if (lecturasensor2 > 550){
    servoMotor.write(10); // bajada de barrera
//    delay(5500);
  }
  else {
    servoMotor.write(95); // Subida de barrera
    delay(3500);
  }

}

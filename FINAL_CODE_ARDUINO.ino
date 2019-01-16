#include <Servo.h>              //This is where I include the servo library and assign the pins as integers.

const int servoPin = 3;

const int buzzerPin = 12;

const int ldrPin = A1;

Servo Servo1;


void setup() {

  Servo1.attach(servoPin);      //
  
  Serial.begin(9600);

  pinMode(servoPin, OUTPUT);

  pinMode(buzzerPin, OUTPUT);

  pinMode(ldrPin, INPUT);

}

void loop() {
  int ldrStatus = analogRead(ldrPin);     //I used this println to check the values of my LDR when in light or dark.
  Serial.println(ldrStatus);
  
  if (ldrStatus >= 130) {                 // Here I use an if-statement to make sure my servo and buzzer react to my LDR.
    
    tone(buzzerPin, 100);
    Servo1.write(90);
    delay(100);
    tone(buzzerPin, 150);
    Servo1.write(180); 
    delay(100);
  }

   else  {
    noTone(buzzerPin);                //And here I make sure it turns off when my LDR is in low lighting.
  }

}

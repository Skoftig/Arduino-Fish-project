
#include <Servo.h>              //This is where I include the servo library and assign the pins as integers.

//constants
const int servoPin = 3;
const int buzzerPin = 12;
const int ldrPin = A1;

Servo Servo1;


void setup() {

  Servo1.attach(servoPin);      //The Servo motor is assigned to it's pin integer.
  
  Serial.begin(9600);           //The arduino will listen to serial port 9600.

  pinMode(servoPin, OUTPUT);

  pinMode(buzzerPin, OUTPUT);

  pinMode(ldrPin, INPUT);

}

void loop() {
  int ldrStatus = analogRead(ldrPin);     //This println is used to check the values of the LDR.
  Serial.println(ldrStatus);
  
  if (ldrStatus >= 130) {                 //If the LDR reads above 130, it's surroundings are light and the Servo and buzzer will respond.
    
    tone(buzzerPin, 165); //E note
    noTone(buzzerPin);
    delay(1000);
    tone(buzzerPin, 165);
    noTone(buzzerPin);
    delay(1000);
    tone(buzzerPin, 165);
    noTone(buzzerPin);
    delay(1000);
    tone(buzzerPin, 131); // C note
    delay(1000);
    tone(buzzerPin, 165);
    delay(100);
    tone(buzzerPin, 196); //G note
    delay(150);
    tone(buzzerPin, 98); // lower G note
    delay(150);
    tone(buzzerPin, 131);
    delay(100); 
     
    Servo1.write(90);
    delay(1000);
    Servo1.write(180); 
    delay(1000);
    Servo1.write(0); 
    delay(1000);
  }

   else  {
    noTone(buzzerPin);                //When the LDR's value drop below 130, it is dark and the process shuts off.
    delay(1000);
  }

}

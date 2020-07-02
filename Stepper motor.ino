
#include <Stepper.h>

const int stepsPerRevolution = 200;  


Stepper Stepper1(stepsPerRevolution, 2, 3, 4, 5);
Stepper Stepper2(stepsPerRevolution, 6, 7, 8, 9);

int stepCount = 0;       

void setup() {
  pinMode(A4,INPUT);
  pinMode (A5,INPUT);
  Serial.begin(9600);
}


void loop() {
  int s1=analogRead(A5);
  s1=map(s1,0,1023,0,5);
  int s2=analogRead(A4);
  s2=map(s2,0,1023,0,5);
  Stepper1.step(s1);
  Stepper2.step(s2);
  Serial.print("steps:");
  Serial.println(stepCount);
  stepCount++;
  delay(500);
}

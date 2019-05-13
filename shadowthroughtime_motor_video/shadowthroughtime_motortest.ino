#include <Stepper.h>
const int stepsPerRevolution = 512;
Stepper motor1(stepsPerRevolution, 23, 31, 30, 22);
Stepper motor2(stepsPerRevolution, 25, 33, 32, 24);
Stepper motor3(stepsPerRevolution, 27, 35, 34, 26);
Stepper motor4(stepsPerRevolution, 29, 37, 36, 28);

Stepper motor5(stepsPerRevolution, 39, 47, 46, 38);
Stepper motor6(stepsPerRevolution, 41, 49, 48, 40);
Stepper motor7(stepsPerRevolution, 43, 51, 50, 42);
Stepper motor8(stepsPerRevolution, 45, 53, 52, 44);

int n = 8;
int x = 1;
int s = 1;


void setup() {
  // put your setup code here, to run once:

  motor1.setSpeed(n);
  motor2.setSpeed(n);
  motor3.setSpeed(n);
  motor4.setSpeed(n);
  motor5.setSpeed(n);
  motor6.setSpeed(n);
  motor7.setSpeed(n);
  motor8.setSpeed(n);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor1.step(-s);
  motor2.step(-s);
  motor3.step(s);
  motor4.step(s);
  
  motor5.step(-s);
  motor6.step(-s);
  motor7.step(s);
  motor8.step(s);
  
  x = x + s;
  if (x > 1024 || x < 1) {
    s = s * -1;
  }
  Serial.print("steps:" );
  Serial.println(s);
  delay (10);
}

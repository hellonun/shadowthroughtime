const int transistorPin1 = 2;
const int transistorPin2 = 3;
const int transistorPin3 = 4;
const int transistorPin4 = 5;

float intensity = 255;
float change = 0.4;

void setup() {
  //  pinMode(transistorPin1, OUTPUT);
  //  pinMode(transistorPin2, OUTPUT);
  pinMode(transistorPin3, OUTPUT);
  pinMode(transistorPin4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (intensity <= 0 || intensity >= 255) {
    change = -change;
  }

  intensity = intensity +  change;


  float result = sineFade(intensity, 0, 255);
  float result2 = map(result, 0, 255, 255, 0);

  if (result < 50) {
    result = 50;
  }
  if (result2 < 50) {
    result2 = 50;
  }

  analogWrite(transistorPin1, result);
  analogWrite(transistorPin2, result2);
  analogWrite(transistorPin3, result2);
  analogWrite(transistorPin4, result);

  delay(5);
  Serial.println(result);
}

float sineFade(int inValue, int minValue, int maxValue) {
  float angle = map(inValue, minValue, maxValue, 0, 179);
  float result = (sin((angle * PI / 180) + PI / 2) + 1) * 127.5;
  return result;
}

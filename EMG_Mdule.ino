const int analogPin = A0;
const int ledCount = 5;
int rawValue;
float rmsValue; 
int ledPins[] = {2,3,4,5,6};

void setup() {
  for (int thisLed = 0; thisLed <= ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop() {

  Serial.begin(9600);
  long sum = 0; 2
  for(int i = 0; i < 1000; i++)
  {
    rawValue = analogRead(analogPin); 
    sum += rawValue * rawValue;
    delay(0.0001); 
  }
  rmsValue = sqrt(sum/1000);

  Serial.print("Raw Value = " ); 
  Serial.print(rawValue);
  Serial.print("\t RMS Value = "); 
  Serial.println(rmsValue);


  int ledLevel = map(rawValue, 0,1023, 0, ledCount);

  for (int thisLed = 0; thisLed < ledCount; thisLed++) {

    if (thisLed <= ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
      delay(1);
    } else {
      digitalWrite(ledPins[thisLed], LOW);
    }
    
     }
}
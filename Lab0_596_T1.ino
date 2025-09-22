
// the number of the LED pin 
const int ledPin = 5;  // 5 corresponds to GPIO5 
const int vrPin = 36; 
  // 36 corresponds to GPIO36 
// setting PWM properties 
const int freq = 5000; 
const int resolution = 8;
void setup(){ 
  Serial.begin(115200);   
  // set GPIO36 as input 
  pinMode(vrPin, INPUT); 
   
  ledcAttach(ledPin, freq, resolution); 
 
} 
  
void loop(){ 
  // read the voltage level at GPIO36 
  int vr_value = analogRead(vrPin); 
  int dutyCycle = map(vr_value, 0, 4095, 0, 255); 
  Serial.println(dutyCycle); 
   
  ledcWrite(ledPin, dutyCycle); 
 
  delay(100); 
} 



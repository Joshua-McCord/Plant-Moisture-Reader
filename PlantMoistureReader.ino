
int plantMoistureReadPin = A0; 
int val = 0;  // variable to store the value read

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(plantMoistureReadPin, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  delay(500);
  int reading = mapMoistureToPercentage(analogRead(plantMoistureReadPin));
  Serial.println(reading);       
}  

int mapMoistureToPercentage(int moistureReading) {
  int tmp =  -1 * (moistureReading - 440);
  if(tmp < 0) {
    tmp = 0;
  } else if (tmp > 240) {
    tmp = 240;
  }
  tmp *= 100;
  tmp /= 240;
  return tmp;
}

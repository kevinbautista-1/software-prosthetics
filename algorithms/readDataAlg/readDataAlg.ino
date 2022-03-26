void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Establishes sample rate

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A0)); // Reads the analog pin of interest
  delay(15); // creates some delay to view data

}

void setup() {
  // put your setup code here, to run once:
  pinMode(49,OUTPUT);
  pinMode(47, OUTPUT);
  fan(5000,2000);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  

}

void fan(int time_on, int time_off) {
  digitalWrite(49, HIGH);
  digitalWrite(47, LOW);
  delay(time_on);
  digitalWrite(49, LOW);
  digitalWrite(47, LOW);
  delay(time_off);
  digitalWrite(49, LOW);
  digitalWrite(47, HIGH);
  delay(time_on);
  digitalWrite(49, LOW);
  digitalWrite(47, LOW);
  delay(time_off);

}


#define MOTOR1_P1 3
#define MOTOR1_P2 2
#define MOTOR2_P1 5
#define MOTOR2_P2 4
#define MOTOR3_P1 13
#define MOTOR3_P2 12
#define MOTOR4_P1 7
#define MOTOR4_P2 6
#define MOTOR_PWM1 10
#define MOTOR_PWM2 11


void setup() {
    pinMode(MOTOR1_P1, OUTPUT);
    pinMode(MOTOR1_P2, OUTPUT);
    pinMode(MOTOR2_P1, OUTPUT);
    pinMode(MOTOR2_P2, OUTPUT);
    pinMode(MOTOR3_P1, OUTPUT);
    pinMode(MOTOR3_P2, OUTPUT);
    pinMode(MOTOR4_P1, OUTPUT);
    pinMode(MOTOR4_P2, OUTPUT);
    pinMode(MOTOR_PWM1, OUTPUT);
    pinMode(MOTOR_PWM2, OUTPUT);
}

void loop() {
  analogWrite(MOTOR_PWM1, 250);
  analogWrite(MOTOR_PWM2, 250);
  digitalWrite(MOTOR1_P1, LOW);
  digitalWrite(MOTOR1_P2, HIGH);
  digitalWrite(MOTOR2_P1, HIGH);
  digitalWrite(MOTOR2_P2, LOW);
  digitalWrite(MOTOR3_P1, LOW);
  digitalWrite(MOTOR3_P2, HIGH);
  digitalWrite(MOTOR4_P1, HIGH);
  digitalWrite(MOTOR4_P2, LOW);
  //Enes100.println("Turning left");
  
}

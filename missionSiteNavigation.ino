#include "Arduino.h"
#include "Enes100.h"
//#include "Tank.h"

#define MOTOR1_P1 2
#define MOTOR1_P2 3
#define MOTOR2_P1 4
#define MOTOR2_P2 5
#define MOTOR3_P1 12
#define MOTOR3_P2 13
#define MOTOR4_P1 6
#define MOTOR4_P2 7
#define MOTOR_PWM1 10
#define MOTOR_PWM2 11

void setup() {
  //Serial.begin(9600);
  delay(2000);
    Enes100.begin("Fireboys", FIRE, 284, 9, 8);
    //Tank.begin();
    delay(2000);
    Enes100.println("Fireboys Starting Drive");

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

    analogWrite(MOTOR_PWM1, 100);
    analogWrite(MOTOR_PWM2, 100);
}
void loop() {
    float x, y, t; bool v;
    x = Enes100.getX();  // Your X coordinate! 0-4, in meters, -1 if no aruco is not visibility (but you should use Enes100.isVisible to check that instead)
    y = Enes100.getY();  // Your Y coordinate! 0-2, in meters, also -1 if your aruco is not visible.
    t = Enes100.getTheta();  //Your theta! -pi to +pi, in radians, -1 if your aruco is not visible.
    v = Enes100.isVisible(); // Is your aruco visible? True or False.
    
    //Enes100.print("Ultrasonic Reading: ");
    //Enes100.println(Tank.readDistanceSensor(1));
    //If the OTV spawns in ZOne A it will run the code below
    //It will exit out of the code once it reaches the next part of the course
    turnLeft(50);
  /*if(x < 0.7){
    if (y >= 1.3){
      Enes100.println("Zone A ");
      while(t > -1.55 || t < -1.655){
        if (t<=(PI/2) && t>0 || t<=0 && t>=-(PI/2)){
          turnRight(50);
          t = Enes100.getTheta();
        } 
        if (t>(PI/2) && t<(PI) || t>-(PI) && t<-(PI/2)){
          turnLeft(50);
          t = Enes100.getTheta();
        }
      }
      while (t <= -1.55 && t >= -1.655 && y > 0.4){
         moveForward(50);
         y = Enes100.getY();
      }
      //Tank.turnOffMotors();
      stopMoving();
      /*while (t > -1.655 && t < 0){ //Code for turning from zone C to obstacles.
        //Tank.setLeftMotorPWM(-50);
        //Tank.setRightMotorPWM(50);
        t = Enes100.getTheta();
      }
      //Tank.turnOffMotors();
      while (t < 0.5 && t > -0.5 && x < 0.8){
        //Tank.setLeftMotorPWM(50);
        //Tank.setRightMotorPWM(50);
        x = Enes100.getX();
      }
      //Tank.turnOffMotors();
     }
     //If the OTV spawns in Zone C it will run the code below
     //It will exit out of the code once it reaches the next part of the course
    else if (y <= 0.7){
      Enes100.println("Zone C");
      while(t < 1.55 || t > 1.655){
        if (t<=(PI/2) && t>0 || t<=0 && t>=-(PI/2)){
          turnLeft(50);
          t = Enes100.getTheta();
        } 
        if (t>(PI/2) && t<(PI) || t>-(PI) && t<-(PI/2)){
          turnRight(50);
          t = Enes100.getTheta();
        }
      }
      while (t >= 1.55 && t <= 1.655 && y < 1.51){
        moveForward(50);
        y = Enes100.getY();
      }
      //Tank.turnOffMotors();
      stopMoving();
      /*while (t < 1.655 && t > 0){
        //Tank.setLeftMotorPWM(50);
        //Tank.setRightMotorPWM(-50);
        t = Enes100.getTheta();
      }
      //Tank.turnOffMotors();
      while(t < 0.5 && t > -0.5 && x < 0.8){
        //Tank.setLeftMotorPWM(50);
        //Tank.setRightMotorPWM(50);
        x=Enes100.getX();
      }
    //Tank.turnOffMotors();
    stopMoving();
    }
  }*/
}

void turnRight(int speed){
  speed = (speed/100)*255;
  analogWrite(MOTOR_PWM1, speed);
  analogWrite(MOTOR_PWM2, speed);
  digitalWrite(MOTOR1_P1, HIGH);
  digitalWrite(MOTOR1_P2, LOW);
  digitalWrite(MOTOR2_P1, LOW);
  digitalWrite(MOTOR2_P2, HIGH);
  digitalWrite(MOTOR3_P1, HIGH);
  digitalWrite(MOTOR3_P2, LOW);
  digitalWrite(MOTOR4_P1, LOW);
  digitalWrite(MOTOR4_P2, HIGH);
  Enes100.println("Turning right");
}

void turnLeft(int speed){
  speed = (speed/100)*255;
  analogWrite(MOTOR_PWM1, speed);
  analogWrite(MOTOR_PWM2, speed);
  digitalWrite(MOTOR1_P1, LOW);
  digitalWrite(MOTOR1_P2, HIGH);
  digitalWrite(MOTOR2_P1, HIGH);
  digitalWrite(MOTOR2_P2, LOW);
  digitalWrite(MOTOR3_P1, LOW);
  digitalWrite(MOTOR3_P2, HIGH);
  digitalWrite(MOTOR4_P1, HIGH);
  digitalWrite(MOTOR4_P2, LOW);
  Enes100.println("Turning left");
}

void moveForward(int speed){
  speed = (speed/100)*255;
  analogWrite(MOTOR_PWM1, speed);
  analogWrite(MOTOR_PWM2, speed);
  digitalWrite(MOTOR1_P1, HIGH);
  digitalWrite(MOTOR1_P2, LOW);
  digitalWrite(MOTOR2_P1, HIGH);
  digitalWrite(MOTOR2_P2, LOW);
  digitalWrite(MOTOR3_P1, HIGH);
  digitalWrite(MOTOR3_P2, LOW);
  digitalWrite(MOTOR4_P1, HIGH);
  digitalWrite(MOTOR4_P2, LOW);
  Enes100.println("moving Forward");
}

void stopMoving(){
  analogWrite(MOTOR_PWM1, 0);
  analogWrite(MOTOR_PWM2, 0);
  digitalWrite(MOTOR1_P1, LOW);
  digitalWrite(MOTOR1_P2, LOW);
  digitalWrite(MOTOR2_P1, LOW);
  digitalWrite(MOTOR2_P2, LOW);
  digitalWrite(MOTOR3_P1, LOW);
  digitalWrite(MOTOR3_P2, LOW);
  digitalWrite(MOTOR4_P1, LOW);
  digitalWrite(MOTOR4_P2, LOW);
  Enes100.println("stopped moving");
}
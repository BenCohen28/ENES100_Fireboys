#include "Arduino.h"
#include "Enes100.h"
#include "Tank.h"



void setup() {
    Enes100.println("hi");
    Enes100.begin("Simulator", FIRE, 3, 8, 9);
    Tank.begin();
    
    Enes100.println("Starting driving");
    Tank.setLeftMotorPWM(80);
    Tank.setRightMotorPWM(80);
    
}

void loop() {
    float x, y, t; bool v;
    x = Enes100.getX();  // Your X coordinate! 0-4, in meters, -1 if no aruco is not visibility (but you should use Enes100.isVisible to check that instead)
    y = Enes100.getY();  // Your Y coordinate! 0-2, in meters, also -1 if your aruco is not visible.
    t = Enes100.getTheta();  //Your theta! -pi to +pi, in radians, -1 if your aruco is not visible.
    v = Enes100.isVisible(); // Is your aruco visible? True or False.
     //Zone5
    if (x >= 3.3){
      Enes100.println("Zone 5 ");
      Tank.turnOffMotors();
      if (y >= 1.3){
       Enes100.println("Zone A");
      } else if (y >= 0.7){
       Enes100.println("Zone B");
      } else if (y >= 0){
       Enes100.println("Zone C");
      }
    }
    //Zone4
    else if (x >= 2.6){
      Enes100.println("Zone 4 ");
      if (y >= 1.3){
        Enes100.println("Zone A");
      } else if (y >= 0.7){
        Enes100.println("Zone B");
      } else if (y >= 0){
        Enes100.println("Zone C");
      }
    } 
    //Zone3    
    else if (x >= 1.4){
      Enes100.println("Zone 3 ");
      if (y >= 1.3){
        Enes100.println("Zone A");
      } else if (y >= 0.7){
        Enes100.println("Zone B");
      } else if (y >= 0){
        Enes100.println("Zone C");
      }
    } 
    //Zone2
    else if (x >= 0.8){
      Enes100.println("Zone 2 ");
      if (y >= 1.3){
        Enes100.println("Zone A");
      } else if (y >= 0.7){
        Enes100.println("Zone B");
      } else if (y >= 0){
        Enes100.println("Zone C");
      }
    } 
    //Zone1
    else if (x >= 0){
       Enes100.println("Zone 1 ");
      if (y >= 1.3){
        Enes100.println("Zone A");
      } else if (y >= 0.7){
        Enes100.println("Zone B");
      } else if (y >= 0){
        Enes100.println("Zone C");
      }
    }

    
    if (v) // If the ArUco marker is visible
    {
        Enes100.print(x); // print out the location
        Enes100.print(",");
        Enes100.print(y);
        Enes100.print(",");
        Enes100.println(t);
    }
    else { // otherwise
        Enes100.println("Not visible"); // print not visible
    }
}

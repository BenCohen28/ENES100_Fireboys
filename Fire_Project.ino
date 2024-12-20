#include <Enes100.h>

void setup() {
    // Initialize Enes100 Library
    Enes100.begin("fireboys", FIRE, 543, 3, 2);
    // Team Name, Mission Type, Marker ID, Wifi Module TX Pin, Wifi Module RX Pin
    //Enes100.begin("It's Lit", FIRE, 205, 3, 2);
    // At this point we know we are connected.
    Serial.begin(9600);
    Enes100.println("Connected...");
}

void loop() {
    float x, y, t; bool v; // Declare variables to hold the data
    //Enes100.getX will make sure you get the latest data available to you about your OTV's location.
    //The first time getX is called, X, Y, theta and visibility are queried and cached.
    //Subsequent calls return from the cache, so there is no performance gain to saving the function response to a variable.

    x = Enes100.getX();  // Your X coordinate! 0-4, in meters, -1 if no aruco is not visibility (but you should use Enes100.isVisible to check that instead)
    y = Enes100.getY();  // Your Y coordinate! 0-2, in meters, also -1 if your aruco is not visible.
    t = Enes100.getTheta();  //Your theta! -pi to +pi, in radians, -1 if your aruco is not visible.
    v = Enes100.isVisible(); // Is your aruco visible? True or False.

    //Enes100.println("hello world");
    //Zone5
    if (x >= 3.5){
      Serial.print("Zone 5 ");
      if (y >= 1.3){
        Serial.println("Zone A");
      } else if (y >= 0.7){
        Serial.println("Zone B");
      } else if (y >= 0){
        Serial.println("Zone C");
      }
    }
    //Zone4
    else if (x >= 2.6){
      Serial.print("Zone 4 ");
      if (y >= 1.3){
        Serial.println("Zone A");
      } else if (y >= 0.7){
        Serial.println("Zone B");
      } else if (y >= 0){
        Serial.println("Zone C");
      }
    } 
    //Zone3    
    else if (x >= 1.4){
      Serial.print("Zone 3 ");
      if (y >= 1.3){
        Serial.println("Zone A");
      } else if (y >= 0.7){
        Serial.println("Zone B");
      } else if (y >= 0){
        Serial.println("Zone C");
      }
    } 
    //Zone2
    else if (x >= 0.8){
      Serial.print("Zone 2 ");
      if (y >= 1.3){
        Serial.println("Zone A");
      } else if (y >= 0.7){
        Serial.println("Zone B");
      } else if (y >= 0){
        Serial.println("Zone C");
      }
    } 
    //Zone1
    else if (x >= 0){
      Serial.print("Zone 1 ");
      if (y >= 1.3){
        Serial.println("Zone A");
      } else if (y >= 0.7){
        Serial.println("Zone B");
      } else if (y >= 0){
        Serial.println("Zone C");
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

    // Transmit the number of candles that are lit
    //Enes100.mission(NUM_CANDLES, 4);
    // Transmit the topography of the fire mission (TOP_A for topography A)
    //Enes100.mission(TOPOGRAPHY, TOP_A);
    Serial.print("x = ");
    Serial.print(x);
    Serial.print(", Y = ");
    Serial.print(y);
    Serial.print(", Theta = ");
    Serial.print(t);
    Serial.println();
    delay(1000);
}

#include <Arduino.h>
#include <Servo.h>
    
// header files
#include "../include/button_1.h"
#include "../include/button_1.cpp"

// Create: object
Servo myservo;

const int ServoPIN = 9;

// Create & assign: Servo position
int pos = 0;
int a = 0;

// Pins
const int PIN_button = 4;
const int PIN_LED = 2;

// Button
int button_press = 0;
int button_on = 0;

// left = 1, right = 2
int direction = 0;

const int pause = 200;
int output = 1;

// Main Function
void setup() 
{
  //serial speed (bits per second)
  Serial.begin(9600);
  //Serial.begin(115200);

  // Output
  Serial.println("MYCROMARS");
  Serial.println("Arduino uno Servo Motor\n");
 
  // Pin
  myservo.attach(ServoPIN);

  // Activate: Pins 
  pinMode( PIN_LED, OUTPUT);
  pinMode( PIN_button, INPUT_PULLUP);

}

// Step Function
void loop() 
{
  // Function: button ON/OFF
  button_1(PIN_button, PIN_LED, &button_press, &button_on);


  // Start position
  if (a == 0 && button_on == 1) {
    output = 0;
    a = 1;

    delay(pause);

    Serial.println("left");

    for (pos = 90; pos >= 0; pos -= 1)
    {
      // Direction Start
      direction = 1;
      
      // Output
      //Serial.println(pos);

      // Motor
      myservo.write(pos);
      
      // Function: button OFF
      button_1(PIN_button, PIN_LED, &button_press, &button_on);

       // Stop
      if (button_on == 0){break;}

      delay(10);
    }
    // Correction
    pos ++;

    // Direction
    if (pos == 0){direction = 2;}

    // Serial.print("Position: ");
    // Serial.println(pos);

    delay(pause);
  }


  // Function: button OFF
  if (button_on == 1)
  {
    button_1(PIN_button, PIN_LED, &button_press, &button_on);
  }


  // right
  if (direction == 2 && button_on == 1)
  {
      output = 0;
      Serial.println("right");
  
      for (pos = pos; pos <= 180; pos += 1)
      {
        // Output
        //Serial.println(pos);

        // Motor Position
        myservo.write(pos);

        // Function: button OFF
        button_1(PIN_button, PIN_LED, &button_press, &button_on);

        // Stop
        if (button_on == 0){break;}

        delay(10);
      }

      // Correction
      pos --;

      // Direction
      if (pos == 180){direction = 1;}

      // Serial.print("Position: ");
      // Serial.println(pos);

      delay(pause);
  }


  // Function: button OFF
  if (button_on == 1)
  {
    button_1(PIN_button, PIN_LED, &button_press, &button_on);
  }
  

  // left
  if (direction == 1 && button_on == 1)
  {
      output = 0;
      Serial.println("left");

      for (pos = pos; pos >= 0; pos -= 1)
      {
        // Output
        //Serial.println(pos);

        // Motor 
        myservo.write(pos);
        
        // Function: button OFF
        button_1(PIN_button, PIN_LED, &button_press, &button_on);
        
        // Stop
        if (button_on == 0){break;}

        delay(10);
      }

      // Correction
      pos ++;

      // Direction
      if (pos == 0){direction = 2;}

      // Serial.print("Position: ");
      // Serial.println(pos);

      delay(pause);
  }

  // Output
  if (button_on == 0 && output == 0){
      output = 1;
      Serial.print("Position: ");
      Serial.println(pos);
    }

delay(10);
}
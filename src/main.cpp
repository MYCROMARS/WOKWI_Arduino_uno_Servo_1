#include <Arduino.h>
#include <Servo.h>

// Create: object
Servo myservo;

int ServoPIN = 9;

// Create & assign: Servo position
int pos = 0;

int a = 0;

// Pins
// const int rgb[] = {0, 6, 5, 3}; 

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
  // pinMode( rgb[1], OUTPUT);

}

// Step Function
void loop() 
{

  if (a == 0) {
    a = 1;
    delay(2000);

     Serial.println("left");
    for (pos = 90; pos >= 0; pos -= 1)
    {
      myservo.write(pos);
      delay(10);
    }

  }
  
  Serial.println("right");

  for (pos = 0; pos <= 180; pos += 1)
  {
    myservo.write(pos);
    delay(10);
  }
  
  
  delay(500);

  Serial.println("left");
  for (pos = 180; pos >= 0; pos -= 1)
  {
    myservo.write(pos);
    delay(10);
  }

  delay(500);
}
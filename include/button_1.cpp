#include <Arduino.h>

void button_1(int PIN_button1, int PIN_LED1, int *button_press1, int *button_on1)
{
  // LED green
  //digitalWrite(x, HIGH);

  if (digitalRead(PIN_button1) == LOW)
  {  
    if (*button_press1 == 0){
      *button_press1 = 1;
 
      // Switch ON/OFF
      if (*button_on1 == 0) {
        *button_on1 = 1;
        Serial.println("ON");
        digitalWrite(PIN_LED1, HIGH);
      }
      else if (*button_on1 == 1)
      {
        *button_on1 = 0; 
        Serial.println("OFF");
        digitalWrite(PIN_LED1, LOW);
      }
    }
  }
  else {
    // button free
    *button_press1 = 0;
    //a = 0;
  }
}
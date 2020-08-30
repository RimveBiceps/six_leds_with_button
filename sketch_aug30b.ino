/* 
Control six LED lights on a button click.
Requirements:
  6x Led lights
  6x 220 Ohm resistors
  1x 10k Ohm resistor
  1x Button
  16x Wires
  1x Arduino Uno :)
Email:kanapka.rimvydas@gmail.com
Website:www.rilog.ml
2020.08.30
*/
/**************************************/
const int lowestLedPin = 7; // the lowest led attached to pin 7
const int highestLedPin = 12; // the highest led attached to pin 12
const int buttonPin = 13; // button pin 13

int buttonState = 0; // button state may be High or low (1 or 0)
/**************************************/
void setup()
{
  //set pins 7 through 12 as output 
  for(int thisPin = lowestLedPin;thisPin <= highestLedPin;thisPin++)
  {
    pinMode(thisPin,OUTPUT); //initialize thisPin as an output
  }
  pinMode(buttonPin,INPUT); // set pin 13 as input
  
  Serial.begin(9600); // initialize serial monitor on 9600
} 
/****************************************/
void loop()
{
  buttonState = digitalRead(buttonPin);
   
  if (buttonState == HIGH)
  {
    Serial.println("Button On"); // print to serial monitor on button click
    light_pattern(); // call light managing function
  }
}
/****************************************/
void light_pattern()
{
  /*
  iterate over the pins
  turn the led on from lowest to the highest
  */
  
  for(int thisPin = lowestLedPin; thisPin <= highestLedPin; thisPin++)
    {
    digitalWrite(thisPin,HIGH);//turn this led on
    delay(100);//wait for 100 ms
    }
  //fade from the highest to the lowest
  for(int thisPin = highestLedPin; thisPin>=lowestLedPin; thisPin--)
  {
    digitalWrite(thisPin,LOW); //turn this led off
    delay(100);//wait for 100 ms
  }
  for(int thisPin = highestLedPin; thisPin>=lowestLedPin; thisPin--)
  {
    digitalWrite(thisPin,HIGH); //turn this led on
    delay(100);//wait for 100 ms
  }
  for(int thisPin = lowestLedPin; thisPin <= highestLedPin; thisPin++)
  {
    digitalWrite(thisPin,LOW); //turn this led off
    delay(100);//wait for 100 ms
  }
}

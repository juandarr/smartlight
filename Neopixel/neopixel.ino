/**************************************************************
Simple control of neopixel lights via CodeBender
 **************************************************************/

#include <Adafruit_NeoPixel.h>

#define PIN 8

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;
bool value = false;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);

int shift = 1;



void setup()
{
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  
  strip.begin();
  strip.setBrightness(20);
  strip.show();
  
}

void color()
{
  
  for(int i=0; i< strip.numPixels(); i++)
  {
    strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) +shift) & 255));
  }
  strip.setBrightness(20);
  strip.show();
}

void rainbow()
{
  shift++;
  if (shift==250) shift=1;
  for(int i=0; i< strip.numPixels(); i++)
  {
    strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) +shift) & 255));
  }
  strip.setBrightness(20);
  strip.show();
}

void off()
{
  
  for(int i=0; i< strip.numPixels(); i++)
  {
    strip.setPixelColor(i, 0,0,0);
  }
  
  strip.show();
}

void loop()
{
 
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  if (buttonState)
  {
    rainbow();
  }else
  {
    off();
  }
  delay(1);        // delay in between reads for stability
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

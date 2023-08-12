
#define NUM_LEDS 8
#include <FastLED.h>
CRGB leds[NUM_LEDS];
unsigned long startMillis; // some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 1000;
bool bbounce = true;
int ledi = 0;int rem ;
#include "func.h"
// How many leds in your strip?

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3
#define CLOCK_PIN 13

// Define the array of leds

void setup()
{
	Serial.begin(9600);
	Serial.println("resetting");
	FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
	FastLED.setBrightness(1);
	fill_gradient(leds, NUM_LEDS, CHSV(50, 255, 255), CHSV(100, 255, 255), LONGEST_HUES);
	//fill_solid(leds + 4, 4, CRGB::Black); // CRGB(128,0,0);
	FastLED.show();
	//delay(3000);
	startMillis = millis();
}

void loop()
{
	 cyclon();
	//knightrider(100, CRGB::Green);
	//showRPM();
}

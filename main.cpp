    #include <Adafruit_NeoPixel.h>
    #ifdef __AVR__
     #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
    #endif
    
    // Which pin on the Arduino is connected to the NeoPixels?
    // On a Trinket or Gemma we suggest changing this to 1:
    #define LED_PIN    3
    
    // How many NeoPixels are attached to the Arduino?
    #define LED_COUNT 8
    
    // Declare our NeoPixel strip object:
    Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
    // Argument 1 = Number of pixels in NeoPixel strip
    // Argument 2 = Arduino pin number (most are valid)
    // Argument 3 = Pixel type flags, add together as needed:
    //   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
    //   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
    //   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
    //   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
    //   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
    
    
    // setup() function -- runs once at startup --------------------------------
    
    void setup() {
      // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
      // Any other board, you can remove this part (but no harm leaving it):
    #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
      clock_prescale_set(clock_div_1);
    #endif
      // END of Trinket-specific code.
    
      strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
      strip.show();            // Turn OFF all pixels ASAP
      strip.setBrightness(10); // Set BRIGHTNESS to about 1/5 (max = 255)
      Serial.begin(9600);
    }
    
    
    // loop() function -- runs repeatedly as long as board is on ---------------
    

    //g_vons functions for animated effects
    
    void knightRider(uint32_t color, int wait, int barLength) {
      uint32_t off = (0, 0, 0);
      int i=0;
      int j=0;
      int k=0;
       while(i<strip.numPixels()) {
          for(int k=0; k<barLength; k++) {
           strip.setPixelColor(k, color);         //  Set pixel's color (in RAM)
           strip.show();                          //  Update strip to match
           delay(wait);                           //  Pause for a moment
            }
          for(int j=0; j<strip.numPixels(); j++) {
           strip.setPixelColor(j, off);         //  Set Bar Pixel 1 to 0 (in RAM)
           strip.setPixelColor(j+barLength, color);         //  Set next Bar pixel to color (in RAM)
           strip.show();                          //  Update strip to match
           delay(wait); 
           }
          for(int k=strip.numPixels(); k>strip.numPixels()-barLength; k--) {
           strip.setPixelColor(k, color);         //  Set pixel's color (in RAM)
           strip.show();                          //  Update strip to match
           delay(wait);                           //  Pause for a moment
            }
          for(int j=strip.numPixels(); j>0; j--) {
           strip.setPixelColor(j, off);         //  Set Bar Pixel 1 to 0 (in RAM)
           strip.setPixelColor(j-barLength, color);         //  Set next Bar pixel to color (in RAM)
           strip.show();                          //  Update strip to match
           delay(wait); 
           }
          strip.setPixelColor(0, off);
          strip.show();                          //  Update strip to match
          delay(wait);
    }
    }


        void loop() {
    //g_vons loop functions
        knightRider(strip.Color(255,  0,  0), 60, 3); // Red Bar
      
      // Fill along the length of the strip in various colors...
    //  colorWipe(strip.Color(255,   0,   0), 50); // Red
    //  colorWipe(strip.Color(  0, 255,   0), 50); // Green
    //  colorWipe(strip.Color(  0,   0, 255), 50); // Blue
    //  colorWipe(strip.Color(  200,   0, 255), 50); // Purple
    
      // Do a theater marquee effect in various colors...
    //  theaterChase(strip.Color(127, 127, 127), 50); // White, half brightness
    //  theaterChase(strip.Color(127,   0,   0), 50); // Red, half brightness
    //  theaterChase(strip.Color(  0,   0, 127), 50); // Blue, half brightness
    
    //  rainbow(10);             // Flowing rainbow cycle along the whole strip
    //  theaterChaseRainbow(50); // Rainbow-enhanced theaterChase variant
    }
    
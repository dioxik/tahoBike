
bool update_ms(const unsigned long period){

currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  if (currentMillis - startMillis >= period)  //test whether the period has elapsed
  {
      //if so, change the state of the LED.  Uses a neat trick to change the state
    startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED state.
    //Serial.println("mils true");
    return true;
  }else{ //Serial.println("mils false");
    return false;}

}
void fadeall()
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i].nscale8(250);
    }
}

void cyclon()
{

    static uint8_t hue = 0;
    // Serial.print("x");
    //  First slide the led in one direction
    for (int i = 0; i < NUM_LEDS; i++)
    {
        // Set the i'th led to red
        leds[i] = CHSV(hue++, 255, 255);
        // Show the leds
        FastLED.show();
        // now that we've shown the leds, reset the i'th led to black
        // leds[i] = CRGB::Black;
        fadeall();
        // Wait a little bit before we loop around and do it again
        delay(10);
    }
    // Serial.print("x");

    // Now go in the other direction.
    for (int i = (NUM_LEDS)-1; i >= 0; i--)
    {
        // Set the i'th led to red
        leds[i] = CHSV(hue++, 255, 255);
        // Show the leds
        FastLED.show();
        // now that we've shown the leds, reset the i'th led to black
        // leds[i] = CRGB::Black;
        fadeall();
        // Wait a little bit before we loop around and do it again
        delay(10);
    }
}


//bool update_ms = true;
// uint8_t pos;
void knightrider(const unsigned long period, CRGB color)
{
    // a colored dot going in one direction with fading tail
    // fadeToBlackBy(leds, NUM_LEDS, 3); // change 10 to smaller or larger number to adjust the length of the tail.
    // uint8_t u = beat8(BPM, 0);        // BPM will allow you to adjust the speed the dot is moving.
    // if (u > 220){bbounce = !bbounce;}
    // uint8_t pos;
    //  if(bbounce){pos = map(u, 0, 255, 0, NUM_LEDS-1 );}
    //  else {pos = map(u, 0, 255, NUM_LEDS-1, 0  );}

    //   Serial.println(pos);
    // leds[pos] = color;
    // FastLED.show();

    // fadeall();
    if (bbounce && update_ms(period))
    {
        fadeToBlackBy(leds, NUM_LEDS, 3);
        if (ledi <= NUM_LEDS)
        {
            fill_solid(leds, NUM_LEDS, CRGB::Black); // CRGB(128,0,0);
            if(ledi-2 > 0){leds[ledi - 2].setRGB(0, 18, 0);}
            if(ledi-1 > 0){leds[ledi - 1].setRGB(0, 168, 0);}
            leds[ledi].setRGB(0, 255, 0);
            FastLED.show();
            ledi++;
        }
        else
        {
            bbounce = !bbounce;
        }
    }
    if (!bbounce && update_ms(period))
    {

        fadeToBlackBy(leds, NUM_LEDS, 3);
        if (ledi >= 0)
        {
            fill_solid(leds, NUM_LEDS, CRGB::Black);
            if(ledi+2 < NUM_LEDS){leds[ledi + 2].setRGB(0, 18, 0);}
            if(ledi+1 < NUM_LEDS){leds[ledi + 1].setRGB(0, 168, 0);}
            leds[ledi].setRGB(0, 255, 0);
            FastLED.show();
            ledi--;
        }
        else
        {
            bbounce = !bbounce;
        }
    }

   // delay(100);
}

void showRPM(){
    //int rem


if (update_ms(500)){
    rem = random(1, 5);
    	fill_gradient(leds, NUM_LEDS, CHSV(50, 255, 255), CHSV(100, 255, 255), LONGEST_HUES);
	//fill_solid(leds +(NUM_LEDS - rem) , rem, CRGB::Black); // CRGB(128,0,0);
	FastLED.show();}else{    for (int i = 0; i < NUM_LEDS; i++)
    {
        if(i >= (NUM_LEDS - rem)){leds[i].nscale8(150);FastLED.show();}
    }}
}









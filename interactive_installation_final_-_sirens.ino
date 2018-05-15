#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>          // Library for NeoPixels
#ifdef __AVR__
#include <avr/power.h>
#endif
#define pinPix 6                       // Pin driving NeoPixel Ring or String
#define numPix 12                       // Number of NeoPixels in the Ring or Strip

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4, 2);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
long threshold_a; // long store large numbers
long threshold_b;
long threshold_c;
int led = 3;
// Setup NeoPixel Ring
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number driving the strip
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel myNeoPixels = Adafruit_NeoPixel(numPix, pinPix, NEO_GRB + NEO_KHZ800);

int delayval = 50; // delay for half a second

void setup() {
  myNeoPixels.begin();   // Initialize the NeoPixel array in the Arduino's memory,
  myNeoPixels.show();    // turn all pixels off, and upload to ring or string
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);

  threshold_a = 10000;
  threshold_b = 10000 ;
  threshold_c = 100;

}
void loop() {

  long start = millis();
  long total1 =  cs_4_2.capacitiveSensor(30);
  Serial.print(millis() - start);        // check on performance in milliseconds
  Serial.print("\t");                    // tab character for debug windown spacing

  Serial.println(total1);                  // print sensor output 1
  if (total1 > threshold_a) {
    breathe (20, 100, 255, 0, 0);
    ledTrail (100, 255, 0, 255, 0, 0, 0);
    // Pause; R,G,B foreground; R,G,B background
  }
  if (total1 < threshold_a) {
    for (int i = 0; i < numPix; i++) {

      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      myNeoPixels.setPixelColor(i, myNeoPixels.Color(0, 0, 150)); // blue

      myNeoPixels.show(); // This sends the updated pixel color to the hardware.

      delay(delayval); // Delay for a period of time (in milliseconds).
    }
      if (total1 > threshold_a) {
        Serial.println("69");
      }
      if (total1 < threshold_a) {
        Serial.println("0");
      }
    }

  }

const byte extra = 4; // how many ahead, and behind, to light up

void ledTrail(int pause, byte Rf, byte Gf, byte Bf, byte Rb, byte Gb, byte Bb) {

  int tmpR, tmpG, tmpB;         // Temp values

  for (int i = 0; i < numPix; i++) {
    myNeoPixels.setPixelColor(i, Rf, Gf, Bf);

    // now go "extra" pixels ahead and behind
    for (int s = 1; s < extra + 1; s++)
    {
      tmpR = (Rf * (extra - s)) / extra;     // Multiply first to avoid truncation errors
      tmpG = (Gf * (extra - s)) / extra;
      tmpB = (Bf * (extra - s)) / extra;
      myNeoPixels.setPixelColor((i + s) % numPix, tmpR, tmpG, tmpB);
      myNeoPixels.setPixelColor((i + numPix - s) % numPix, tmpR, tmpG, tmpB);
    }

    myNeoPixels.show();
    delay(pause);
  }
}

// Pause = delay between transitions
// Steps = number of steps
// R, G, B = Full-on RGB values


void breathe(int pause, int steps, byte R, byte G, byte B) {

  int tmpR, tmpG, tmpB;         // Temp values

  // Fade up
  for (int s = 1; s <= steps; s++) {
    tmpR = (R * s) / steps;     // Multiply first to avoid truncation errors
    tmpG = (G * s) / steps;
    tmpB = (B * s) / steps;

    for (int i = 0; i < numPix; i++) {
      myNeoPixels.setPixelColor(i, tmpR, tmpG, tmpB);
    }
    myNeoPixels.show();
    delay(pause);
  }

  // Fade down
  for (int s = steps; s > 0; s--) {
    tmpR = (R * s) / steps;     // Multiply first to avoid truncation errors
    tmpG = (G * s) / steps;
    tmpB = (B * s) / steps;

    for (int i = 0; i < numPix; i++) {
      myNeoPixels.setPixelColor(i, tmpR, tmpG, tmpB);
    }
    myNeoPixels.show();
    delay(pause);
  }

  delay(pause * 50);


}

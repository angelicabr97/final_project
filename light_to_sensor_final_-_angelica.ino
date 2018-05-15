
// setup the initial color that it chnges into
// have the four pixels go through a short light when touched
//create a shoe box to be put in
// structure of the buliding
#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN            6
#define NUMPIXELS      12

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4, 2);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4, 6);       // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4, 8);       // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
long threshold_a; // long store large numbers
long threshold_b;
long threshold_c;
long threshold_d;
int led = 3; //int stores smaller limited numbers
// char letter - stores 'a'
// String name = "name"
// max can pullout strings so when sending "String 42" using ""

int buttonState = 0; // global variable
int buttonPin = 7;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 50; // delay for half a second
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.

  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);

  threshold_a = 100;
  threshold_b = 100 ;
  threshold_c = 100;

  pinMode(led, OUTPUT);

  pinMode(buttonPin, INPUT);


}

void loop() {
  long start = millis();
  long total1 =  cs_4_2.capacitiveSensor(30);
  long total2 =  cs_4_6.capacitiveSensor(30);
  long total3 =  cs_4_8.capacitiveSensor(30);

  Serial.print(millis() - start);        // check on performance in milliseconds
  Serial.print("\t");                    // tab character for debug windown spacing

 Serial.println(total1);                  // print sensor output 1
  if (total1 > threshold_a) {
    //digitalWrite(led, HIGH);
    //Serial.println("4");
    sectionOneColorBlue();
  }
  if (total2 > threshold_b) {              //sesnor output 2
    // Serial.println("3");
    sectionTwoColorGreen();

  }
  else if  (total3 > threshold_c) { // sensor ouput 3
    //Serial.println("2");
    sectionThreeColorRed();

  }
  delay(500);                             // arbitrary delay to limit data to serial port

  } // this is the end of the loooooooop


  void sectionOneColorBlue(); {
    for (int a = (0, 1, 2, 3); a < NUMPIXELS; a++) {

      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(a, pixels.Color(0, 0, 150)); // Moderately bright green color.

      pixels.show(); // This sends the updated pixel color to the hardware.

      delay(delayval); // Delay for a period of time (in milliseconds).
    }
  }

  void sectionTwoColorGreen(); {
    for (int b = (4, 5, 6, 7); b < NUMPIXELS; b++) {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(b, pixels.Color(0, 150, 0)); // Moderately bright green color.

      pixels.show(); // This sends the updated pixel color to the hardware.

      delay(delayval); // Delay for a period of time (in milliseconds).
    }
  }

  void sectionThreeColorRed(); {
    for (int c = (8, 9, 10, 11); c < NUMPIXELS; c++) {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(c, pixels.Color(150, 0, 0)); // Moderately bright green color.

      pixels.show(); // This sends the updated pixel color to the hardware.

      delay(delayval); // Delay for a period of time (in milliseconds).
    }
  }
}


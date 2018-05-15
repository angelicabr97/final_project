#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN            6
#define NUMPIXELS      12

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4, 2);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
//CapacitiveSensor   cs_4_6 = CapacitiveSensor(4, 6);       // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
//CapacitiveSensor   cs_4_8 = CapacitiveSensor(4, 8);       // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
long threshold_a; // long store large numbers
long threshold_b;
long threshold_c;
long threshold_d;
int led = 3; //int stores smaller limited numbers
// char letter - stores 'a'
// String name = "name"
// max can pullout strings so when sending "String 42" using ""

int timer = 100;           // The higher the number, the slower the

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
  threshold_b = 5000 ;
  threshold_c = 2000;
  threshold_d = 60000;

  for (int thisPin = 2; thisPin < 8; thisPin++) {
    pinMode(thisPin, OUTPUT);

  }

}

void loop() {
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for (int thisPin = 2; thisPin < 8; thisPin++) {
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(thisPin, LOW);
  }
  for (int i = 0; i < NUMPIXELS; i++) {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 0, 150)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

    for (int i = 1; i < NUMPIXELS; i++) {

      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(0, 0, 150)); // Moderately bright green color.

      pixels.show(); // This sends the updated pixel color to the hardware.

      delay(delayval); // Delay for a period of time (in milliseconds).

      for (int i = 2; i < NUMPIXELS; i++) {

        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
        pixels.setPixelColor(i, pixels.Color(0, 0, 150)); // Moderately bright green color.

        pixels.show(); // This sends the updated pixel color to the hardware.

        delay(delayval); // Delay for a period of time (in milliseconds).
        for (int i = 3; i < NUMPIXELS; i++) {

          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(0, 0, 150)); // Moderately bright green color.

          pixels.show(); // This sends the updated pixel color to the hardware.

          delay(delayval); // Delay for a period of time (in milliseconds).
          for (int i = 4; i < NUMPIXELS; i++) {

            // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
            pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Moderately bright green color.

            pixels.show(); // This sends the updated pixel color to the hardware.

            delay(delayval); // Delay for a period of time (in milliseconds).
            for (int i = 5; i < NUMPIXELS; i++) {

              // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
              pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Moderately bright green color.

              pixels.show(); // This sends the updated pixel color to the hardware.

              delay(delayval); // Delay for a period of time (in milliseconds).
              for (int i = 6; i < NUMPIXELS; i++) {

                // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
                pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Moderately bright green color.

                pixels.show(); // This sends the updated pixel color to the hardware.

                delay(delayval); // Delay for a period of time (in milliseconds).
                for (int i = 7; i < NUMPIXELS; i++) {

                  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
                  pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Moderately bright green color.

                  pixels.show(); // This sends the updated pixel color to the hardware.

                  delay(delayval); // Delay for a period of time (in milliseconds).
                  for (int i = 8; i < NUMPIXELS; i++) {

                    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
                    pixels.setPixelColor(i, pixels.Color(150, 0, 0)); // Moderately bright green color.

                    pixels.show(); // This sends the updated pixel color to the hardware.

                    delay(delayval); // Delay for a period of time (in milliseconds).
                    for (int i = 9; i < NUMPIXELS; i++) {

                      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
                      pixels.setPixelColor(i, pixels.Color(150, 0, 0)); // Moderately bright green color.

                      pixels.show(); // This sends the updated pixel color to the hardware.

                      delay(delayval); // Delay for a period of time (in milliseconds).
                      for (int i = 10; i < NUMPIXELS; i++) {

                        // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
                        pixels.setPixelColor(i, pixels.Color(150, 0, 0)); // Moderately bright green color.

                        pixels.show(); // This sends the updated pixel color to the hardware.

                        delay(delayval); // Delay for a period of time (in milliseconds).
                        for (int i = 11; i < NUMPIXELS; i++) {

                          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
                          pixels.setPixelColor(i, pixels.Color(150, 0, 0)); // Moderately bright green color.

                          pixels.show(); // This sends the updated pixel color to the hardware.

                          delay(delayval); // Delay for a period of time (in milliseconds).

                          {
                            long start = millis();
                            long total1 =  cs_4_2.capacitiveSensor(30);

                            Serial.print(millis() - start);        // check on performance in milliseconds
                            Serial.print("\t");                    // tab character for debug windown spacing

                            Serial.println(total1);                  // print sensor output 1
                            if (total1 > threshold_a) {
                              //digitalWrite(led, HIGH);
                              Serial.println("4");
                            }
                            if (total1 > threshold_b) {
                              Serial.println("3");
                            }
                            else if  (total1 > threshold_c) { // the serial print must be changed if you want to add more serial prints
                              Serial.println("2");
                            }
                            else if  (total1 > threshold_d) {
                              Serial.println("1");
                            }
                            else {
                              //digitalWrite(led, LOW);
                              Serial.println("0");
                            }
                            delay(500);                             // arbitrary delay to limit data to serial port
                            /*
                                                        buttonState = digitalRead(buttonPin); // read the state of the button
                                                        // store in variable
                                                        if (buttonState == HIGH) {
                                                          Serial.println("42");
                                                        }
                            */
                            if (total1 > threshold_a) {
                              for (int i = 0; i < NUMPIXELS; i++) {

                                pixels.setPixelColor(i, pixels. Color(0, 150, 150)); // change color to blue if high interaction

                                pixels.show(); // sending info to the neopixel
                                for (int i = 1; i < NUMPIXELS; i++) {
                                  pixels.setPixelColor(i, pixels. Color(0, 150, 150)); // change color to blue if high interaction

                                  pixels.show(); // sending info to the neopixel
                                  for (int i = 2; i < NUMPIXELS; i++) {

                                    pixels.setPixelColor(i, pixels. Color(0, 150, 150)); // change color to blue if high interaction

                                    pixels.show(); // sending info to the neopixel
                                    for (int i = 3; i < NUMPIXELS; i++) {

                                      pixels.setPixelColor(i, pixels. Color(0, 150, 150)); // change color to blue if high interaction

                                      pixels.show(); // sending info to the neopixel
                                      for (int i = 4; i < NUMPIXELS; i++) {

                                        pixels.setPixelColor(i, pixels. Color(0, 150, 150)); // change color to blue if high interaction

                                        pixels.show(); // sending info to the neopixel
                                        for (int i = 5; i < NUMPIXELS; i++) {
                                          pixels.setPixelColor(i, pixels. Color(0, 150, 150)); // change color to blue if high interaction

                                          pixels.show(); // sending info to the neopixel
                                          for (int i = 6; i < NUMPIXELS; i++) {

                                            pixels.setPixelColor(i, pixels. Color(0, 150, 150)); // change color to blue if high interaction

                                            pixels.show(); // sending info to the neopixel
                                            for (int i = 7; i < NUMPIXELS; i++) {

                                              pixels.setPixelColor(i, pixels. Color(0, 150, 150)); // change color to blue if high interaction

                                              pixels.show(); // sending info to the neopixel
                                              for (int i = 8; i < NUMPIXELS; i++) {

                                                pixels.setPixelColor(i, pixels. Color(0, 150, 150)); // change color to blue if high interaction

                                                pixels.show(); // sending info to the neopixel
                                                for (int i = 9; i < NUMPIXELS; i++) {
                                                  pixels.setPixelColor(i, pixels. Color(0, 150, 150)); // change color to blue if high interaction

                                                  pixels.show(); // sending info to the neopixel
                                                  for (int i = 10; i < NUMPIXELS; i++) {

                                                    pixels.setPixelColor(i, pixels. Color(0, 150, 150)); // change color to blue if high interaction

                                                    pixels.show(); // sending info to the neopixel
                                                    for (int i = 11; i < NUMPIXELS; i++) {

                                                      pixels.setPixelColor(i, pixels. Color(0, 150, 150)); // change color to blue if high interaction

                                                      pixels.show(); // sending info to the neopixel
                                                      if (total1 > threshold_b) {
                                                        for (int i = 0; i < NUMPIXELS; i++) {

                                                          pixels.setPixelColor(i, pixels. Color(150, 150, 0)); // change color to blue if high interaction

                                                          pixels.show(); // sending info to the neopixel
                                                          for (int i = 1; i < NUMPIXELS; i++) {
                                                            pixels.setPixelColor(i, pixels. Color(150, 150, 0)); // change color to blue if high interaction

                                                            pixels.show(); // sending info to the neopixel
                                                            for (int i = 2; i < NUMPIXELS; i++) {

                                                              pixels.setPixelColor(i, pixels. Color(150, 150, 0)); // change color to blue if high interaction

                                                              pixels.show(); // sending info to the neopixel
                                                              for (int i = 3; i < NUMPIXELS; i++) {

                                                                pixels.setPixelColor(i, pixels. Color(150, 150, 0)); // change color to blue if high interaction

                                                                pixels.show(); // sending info to the neopixel
                                                                for (int i = 4; i < NUMPIXELS; i++) {

                                                                  pixels.setPixelColor(i, pixels. Color(150, 150, 0)); // change color to blue if high interaction

                                                                  pixels.show(); // sending info to the neopixel
                                                                  for (int i = 5; i < NUMPIXELS; i++) {
                                                                    pixels.setPixelColor(i, pixels. Color(150, 150, 0)); // change color to blue if high interaction

                                                                    pixels.show(); // sending info to the neopixel
                                                                    for (int i = 6; i < NUMPIXELS; i++) {

                                                                      pixels.setPixelColor(i, pixels. Color(150, 150, 0)); // change color to blue if high interaction

                                                                      pixels.show(); // sending info to the neopixel
                                                                      for (int i = 7; i < NUMPIXELS; i++) {

                                                                        pixels.setPixelColor(i, pixels. Color(150, 150, 0)); // change color to blue if high interaction

                                                                        pixels.show(); // sending info to the neopixel
                                                                        for (int i = 8; i < NUMPIXELS; i++) {

                                                                          pixels.setPixelColor(i, pixels. Color(150, 150, 0)); // change color to blue if high interaction

                                                                          pixels.show(); // sending info to the neopixel
                                                                          for (int i = 9; i < NUMPIXELS; i++) {
                                                                            pixels.setPixelColor(i, pixels. Color(150, 150, 0)); // change color to blue if high interaction

                                                                            pixels.show(); // sending info to the neopixel
                                                                            for (int i = 10; i < NUMPIXELS; i++) {

                                                                              pixels.setPixelColor(i, pixels. Color(150, 150, 0)); // change color to blue if high interaction

                                                                              pixels.show(); // sending info to the neopixel
                                                                              for (int i = 11; i < NUMPIXELS; i++) {

                                                                                pixels.setPixelColor(i, pixels. Color(150, 150, 0)); // change color to blue if high interaction

                                                                                pixels.show(); // sending info to the neopixel
                                                                                if (total1 > threshold_c) {
                                                                                  for (int i = 0; i < NUMPIXELS; i++) {

                                                                                    pixels.setPixelColor(i, pixels. Color(150, 0, 150)); // change color to blue if high interaction

                                                                                    pixels.show(); // sending info to the neopixel
                                                                                    for (int i = 1; i < NUMPIXELS; i++) {
                                                                                      pixels.setPixelColor(i, pixels. Color(150, 0, 150)); // change color to blue if high interaction

                                                                                      pixels.show(); // sending info to the neopixel
                                                                                      for (int i = 2; i < NUMPIXELS; i++) {

                                                                                        pixels.setPixelColor(i, pixels. Color(150, 0, 150)); // change color to blue if high interaction

                                                                                        pixels.show(); // sending info to the neopixel
                                                                                        for (int i = 3; i < NUMPIXELS; i++) {

                                                                                          pixels.setPixelColor(i, pixels. Color(150, 0, 150)); // change color to blue if high interaction

                                                                                          pixels.show(); // sending info to the neopixel
                                                                                          for (int i = 4; i < NUMPIXELS; i++) {

                                                                                            pixels.setPixelColor(i, pixels. Color(150, 0, 150)); // change color to blue if high interaction

                                                                                            pixels.show(); // sending info to the neopixel
                                                                                            for (int i = 5; i < NUMPIXELS; i++) {
                                                                                              pixels.setPixelColor(i, pixels. Color(150, 0, 150)); // change color to blue if high interaction

                                                                                              pixels.show(); // sending info to the neopixel
                                                                                              for (int i = 6; i < NUMPIXELS; i++) {

                                                                                                pixels.setPixelColor(i, pixels. Color(150, 0, 150)); // change color to blue if high interaction

                                                                                                pixels.show(); // sending info to the neopixel
                                                                                                for (int i = 7; i < NUMPIXELS; i++) {

                                                                                                  pixels.setPixelColor(i, pixels. Color(150, 0, 150)); // change color to blue if high interaction

                                                                                                  pixels.show(); // sending info to the neopixel
                                                                                                  for (int i = 8; i < NUMPIXELS; i++) {

                                                                                                    pixels.setPixelColor(i, pixels. Color(150, 0, 150)); // change color to blue if high interaction

                                                                                                    pixels.show(); // sending info to the neopixel
                                                                                                    for (int i = 9; i < NUMPIXELS; i++) {
                                                                                                      pixels.setPixelColor(i, pixels. Color(150, 0, 150)); // change color to blue if high interaction

                                                                                                      pixels.show(); // sending info to the neopixel
                                                                                                      for (int i = 10; i < NUMPIXELS; i++) {

                                                                                                        pixels.setPixelColor(i, pixels. Color(150, 0, 150)); // change color to blue if high interaction

                                                                                                        pixels.show(); // sending info to the neopixel
                                                                                                        for (int i = 11; i < NUMPIXELS; i++) {

                                                                                                          pixels.setPixelColor(i, pixels. Color(150, 0, 150)); // change color to blue if high interaction

                                                                                                          pixels.show(); // sending info to the neopixel
                                                                                                        }
                                                                                                      }
                                                                                                    }
                                                                                                  }
                                                                                                }
                                                                                              }
                                                                                            }
                                                                                          }
                                                                                        }
                                                                                      }
                                                                                    }
                                                                                  }
                                                                                }

                                                                              }
                                                                            }
                                                                          }
                                                                        }
                                                                      }
                                                                    }
                                                                  }
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}



/*                                 _   _                 _  _               _
                                 | \ | |               | |(_)             | |
  __      ____      ____      __ |  \| |  ___  _ __  __| | _  _   _     __| |  ___
  \ \ /\ / /\ \ /\ / /\ \ /\ / / | . ` | / _ \| '__|/ _` || || | | |   / _` | / _ \
   \ V  V /  \ V  V /  \ V  V /_ | |\  ||  __/| |  | (_| || || |_| | _| (_| ||  __/
    \_/\_/    \_/\_/    \_/\_/(_)|_| \_| \___||_|   \__,_||_| \__, |(_)\__,_| \___|
                                                               __/ |
                                                              |___/
     Fibonacci Clock by Fabian Steppat
     Infos on www.nerdiy.de/fibonacciClock

     This program is free software: you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation, either version 3 of the License, or
     (at your option) any later version.

     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.

     You should have received a copy of the GNU General Public License
     along with this program.  If not, see <http://www.gnu.org/licenses/>.

     Credits:
      1.Of course first to Philippe Chrétien for the idea for this clock and that he provides it as an open source project on https://github.com/pchretien/fibo.
        If you want to thank/support him buy one of his awesome clocks on http://basbrun.com/.
      2.To all the awesome guys at adafruit.com who made many awesome and important libraries and products.
        If you want to thank/support them buy one(or more) of their products on www.adafruit.com.
      3.To PaulStoffregen who also writes a lot of important libraries.
        He also offers interesting Hardware-Stuff like the Teensy's. if you want to thank/support him buy on of these thingys on https://www.pjrc.com/.
      4. To all other people on our little planet which contributed to the open source community and make many of these awesome open-source projects possible.
*/
// == Variable & Object Defintions ===========================================================================================================================


#ifndef PUSH_BUTTONS_INSTALLED
#include <CapacitiveSensor.h>
//Create capacitive sensor objects:
CapacitiveSensor   sensorAreaHour = CapacitiveSensor(HOUR_PIN_RES, HOUR_PIN);
CapacitiveSensor   sensorAreaMinute = CapacitiveSensor(MINUTE_PIN_RES, MINUTE_PIN);
CapacitiveSensor   sensorAreaBrightness = CapacitiveSensor(BRIGHTNESS_PIN_RES, BRIGHTNESS_PIN);
CapacitiveSensor   sensorAreaMode = CapacitiveSensor(MODE_PIN_RES, MODE_PIN);
CapacitiveSensor   sensorAreaPlus = CapacitiveSensor(PLUS_PIN_RES, PLUS_PIN);
CapacitiveSensor   sensorAreaMinus = CapacitiveSensor(MINUS_PIN_RES, MINUS_PIN);
#endif

//Create led-strip object
Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, STRIP_PIN, NEO_RGB + NEO_KHZ800);


#ifdef I2C_DISPLAY_INSTALLED
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Create i2c-display object
Adafruit_SSD1306 display(OLED_RESET);
#endif

byte bits[CLOCK_PIXELS];

uint32_t black = strip.Color(0, 0, 0);
const uint8_t colors[TOTAL_PALETTES][4][3] =
{
  {
    // #1 RGB
    255, 255, 255,  // off
    10, 255, 10, // minutes
    255, 10, 10, // hours
    10, 10, 255 // both;
  },
  {
    // #2 Mondrian
    255, 255, 255,  // off
    255, 10, 10, // minutes
    248, 222, 0, // hours
    10, 10, 255 // both;
  },
  {
    // #3 Basbrun
    255, 255, 255,  // off
    80, 40, 0, // minutes
    20, 200, 20, // hours
    255, 100, 10 // both;
  },
  {
    // #4 80's
    255, 255, 255,  // off
    245, 100, 201, // minutes
    114, 247, 54, // hours
    113, 235, 219 // both;
  }
  ,
  {
    // #5 Pastel
    255, 255, 255,  // off
    255, 123, 123, // minutes
    143, 255, 112, // hours
    120, 120, 255 // both;
  }
  ,
  {
    // #6 Modern
    255, 255, 255,  // off
    212, 49, 45, // minutes
    145, 210, 49, // hours
    141, 95, 224 // both;
  }
  ,
  {
    // #7 Cold
    255, 255, 255,  // off
    209, 62, 200, // minutes
    69, 232, 224, // hours
    80, 70, 202 // both;
  }
  ,
  {
    // #8 Warm
    255, 255, 255,  // off
    237, 20, 20, // minutes
    246, 243, 54, // hours
    255, 126, 21 // both;
  }
  ,
  {
    //#9 Earth
    255, 255, 255,  // off
    70, 35, 0, // minutes
    70, 122, 10, // hours
    200, 182, 0 // both;
  }
  ,
  {
    // #10 Dark
    255, 255, 255,  // off
    211, 34, 34, // minutes
    80, 151, 78, // hours
    16, 24, 149 // both;
  }
};

boolean on = true;

String serialBuffer;
String lastPrintedSectionGlobal = "";

uint8_t oldHours = 0;
uint8_t oldMinutes = 0;

uint8_t mode = 0;
uint8_t palette = 0;
float brightness = 1.0;
float brightnessDesired = 1.0;
uint16_t fadeDelayTime = 100;

uint8_t rainbowTransitionPositionGlobal = 0;
uint32_t rainbowTransitionLastExecutionGlobal = 0;

uint32_t timerInterval1Second = 0;
uint32_t lastCheckButtons = 0;

#ifdef LDR_INSTALLED
unsigned long lastBrightnessCheck = 0;
uint16_t movingAverageValues[MOVING_AVERAGE_VALUE_SAMPLES];
uint8_t movingAverageIndex = 0;
uint16_t movingAverage = 0;
uint16_t movingAverageSmallest = 1023;
uint16_t movingAverageBiggest = 0;
#endif

#ifdef I2C_DISPLAY_INSTALLED
uint32_t lastButtonPressedTimestamp = 0;
uint32_t lastDisplayUpdate = 0;
#endif

#ifdef TIME_CLOCK_ENABLED
uint8_t timeclockHourOn = 0;
uint8_t timeclockMinuteOn = 0;
uint8_t timeclockHourOff = 0;
uint8_t timeclockMinuteOff = 0;
boolean timeclockEnabled = false;
#endif

boolean touchAreaHourOld =  false;
boolean touchAreaMinuteOld =  false;
boolean touchAreaBrightnessOld =  false;
boolean touchAreaModeOld =  false;
boolean touchAreaPlusOld =  false;
boolean touchAreaMinusOld =  false;

boolean touchAreaHourReleased = false;
boolean touchAreaMinuteReleased = false;
boolean touchAreaBrightnessReleased = false;
boolean touchAreaModeReleased = false;
boolean touchAreaPlusReleased = false;
boolean touchAreaMinusReleased = false;

boolean touchAreaHourActualTouched = false;
boolean touchAreaMinuteActualTouched = false;
boolean touchAreaBrightnessActualTouched = false;
boolean touchAreaModeActualTouched = false;
boolean touchAreaPlusActualTouched = false;
boolean touchAreaMinusActualTouched = false;

boolean  touchAreaHourWasTouched = false;
boolean  touchAreaMinuteWasTouched = false;
boolean  touchAreaBrightnessWasTouched = false;
boolean  touchAreaModeWasTouched = false;
boolean  touchAreaPlusWasTouched = false;
boolean  touchAreaMinusWasTouched = false;

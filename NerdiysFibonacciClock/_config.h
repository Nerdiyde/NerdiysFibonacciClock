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
// == Configuration ======================================================================================================================================


// == Localization =============================================================================

//#define LANGUAGE          "language/en-GB.h"             // English. Enabled by Default
#define LANGUAGE            "language/de-DE.h"           // German

// == Fibonacci-Clock-Setup ====================================================================

#define VERSION 1.0
#define BAUDRATE 115200
#define MAX_MODES 3
#define TOTAL_PALETTES 10
#define CLOCK_PIXELS 5
#define COLOR_OFFSET_BETWEEN_TWO_LED_AREAS_IN_RAINBOW_MODE 50
#define TIMER_INTERVAL_1S_IN_MS 1000 //in ms
#define MAX_YEAR 2048
#define MIN_YEAR 2005

// == LDR-Setup ================================================================================

//#define LDR_INSTALLED
#define LDR_PIN A0
#define MOVING_AVERAGE_VALUE_SAMPLES 100
#define CHECK_BRIGHTNESS_INTERVAL 500 //in ms

// == I2C-Display-Setup ========================================================================
// Select between status messages via hardware i2c-display or via serial console.
// If I2C_DISPLAY_INSTALLED is disabled all status messages will be shown on serial console
// and (of course) i2c display will be disabled. Due to little memory it is not possible to
// activate serial console and i2c display at the same time.

#define I2C_DISPLAY_INSTALLED

#define DISPLAY_I2C_ADRESS 0x3C
#define DISPLAY_ROTATION 0

// This value specifies how long the i2c-display will stay on after the last
// action on any input(Push buton or capacitve sensor)
#define DISPLAY_ON_TIMER_DURATION 15000 //in ms

#define I2C_DISPLAY_UPDATE_DELAY 100 //in ms
#define OLED_RESET 4

// == Button-Setup =============================================================================
// Disable PUSH_BUTTONS_INSTALLED if you want to use the clock with capacitive sensors
// instead of push buttons. If you want to use the capacitive sensors you have to solder
// 2.7MOhm Resistors between sensor-(e.g. HOUR_PIN) and sensor_RES- (e.g. HOUR_PIN_RES) pins.
#define PUSH_BUTTONS_INSTALLED

#define BUTTON_DEBOUNCE_VALUE 50 //in ms

// Input-pins
#define HOUR_PIN 7
#define HOUR_PIN_RES 8
#define MINUTE_PIN 3
#define MINUTE_PIN_RES 4
#define BRIGHTNESS_PIN 9
#define BRIGHTNESS_PIN_RES 10
#define MODE_PIN 5
#define MODE_PIN_RES 6
#define PLUS_PIN 11
#define PLUS_PIN_RES 12
#define MINUS_PIN 15
#define MINUS_PIN_RES 16

// Touch thresold for capacitive sensors.
// These values should work in most cases.
#define RELEASE_THRESHOLD 500
#define TOUCH_THRESHOLD 500

// == Led-Strip-Setup ============================================================================

#define STRIP_PIN 13
//Alternativ:
//#define STRIP_PIN 2

// == Timeclock-Setup ============================================================================

//#define TIME_CLOCK_ENABLED
#define TIME_CLOCK_HOUR_ON_STANDARD_VALUE 7
#define TIME_CLOCK_MINUTE_ON_STANDARD_VALUE 30
#define TIME_CLOCK_HOUR_OFF_STANDARD_VALUE 23
#define TIME_CLOCK_MINUTE_OFF_STANDARD_VALUE 30

// == EEPROM-Setup ===============================================================================

#define MODE_EEPROM_ADRESS 10
#define BRIGHTNESS_EEPROM_ADRESS 20
#define PALETTE_EEPROM_ADRESS 30
#define FADE_DELAY_EEPROM_ADRESS 40
#define ZEITSCHALTUHR_STUNDE_EIN_EEPROM_ADRESSE 50
#define ZEITSCHALTUHR_MINUTE_EIN_EEPROM_ADRESSE 55
#define ZEITSCHALTUHR_STUNDE_AUS_EEPROM_ADRESSE 60
#define ZEITSCHALTUHR_MINUTE_AUS_EEPROM_ADRESSE 65
#define ZEITSCHALTUHR_AKTIVIERT_EEPROM_ADRESSE 70

// == "Sanitize Check" =============================================================================

#ifndef LANGUAGE
#include "language/en-GB.h"
#else
#include LANGUAGE
#endif

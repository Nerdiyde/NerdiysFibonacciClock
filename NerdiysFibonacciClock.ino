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
// == Setup & Main Loop ======================================================================================================================================


//ToDO:
//Tastensteuerung umbauen so, dass bei angeschlossenem i2c display die zeitschaltuhr über die tasten konfiguriert werden kann
//vllt. beim auswahl der paletten auch deren namen auf dem i2c display anzeigen?
//ausgabe auf i2c display welche farbe gerade die stunde/minute oder beides hat moeglich?

#include <Wire.h>
#include <TimeLib.h>
#include <DS3232RTC.h>
#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
#include "_config.h"
#include "_defs.h"


void setup()
{

  //initializes the uart to enable communication through the serial console
#ifndef I2C_DISPLAY_INSTALLED
  Serial.begin(BAUDRATE);
#endif

  //initalizes the led display
  init_led_strip();

  //initializes the i2c bus for communication with the real time clock and i2c-display(if installed)
  Wire.begin();

#ifdef I2C_DISPLAY_INSTALLED
  //initializes the i2c display
  init_i2c_display();
#endif

#ifdef PUSH_BUTTONS_INSTALLED
  //initializes the correct pin setup for the use of push buttons
  init_push_buttons();
#endif

#ifdef LDR_INSTALLED
  init_ldr();
#endif

  //sets the syncProvider to get the actual time from the real time clock
  setSyncProvider(RTC.get);

  //Make the random() function return unpredictable results
  randomSeed(now());

  //Make sure the time is always displayed the first time the clock is powered on.
  oldHours = 99;

  load_eeprom_data();

}

void loop()
{

#ifndef I2C_DISPLAY_INSTALLED
  //check if any serial commands received
  check_for_received_serial_commands();
#endif

#ifdef TIME_CLOCK_ENABLED
  //check if the timeclock has to switch the led display on or off
  check_timeclock();
#endif

#ifdef I2C_DISPLAY_INSTALLED
  //regular check if the i2c display have to be updated
  if (regular_execution(&lastDisplayUpdate, I2C_DISPLAY_UPDATE_DELAY))
    check_i2c_display();
#endif

  //check if any buttons where pressed
  if (regular_execution(&lastCheckButtons, BUTTON_DEBOUNCE_VALUE))
    check_hardware_inputs();

#ifndef I2C_DISPLAY_INSTALLED
  if (regular_execution(&timerInterval1Second, TIMER_INTERVAL_1S_IN_MS))
  {
    //regular print the actual clock state to the serial console
    print_time_to_serial_output();
  }
#endif

#ifdef LDR_INSTALLED
  if (regular_execution(&lastBrightnessCheck, CHECK_BRIGHTNESS_INTERVAL))
  {
    //read brightness from ldr and use it for led display brightness
    check_brightness();
  }
#else
  //just use brightness set up per hardware inputs
  check_brightness();
#endif

  //update the led display
  update_led_display();

}

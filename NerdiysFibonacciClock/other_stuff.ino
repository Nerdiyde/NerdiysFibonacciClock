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
// == Other (helpfull) stuff ================================================================================================================================


boolean regular_execution(unsigned long *lastExecution, unsigned long REPEATING_INTERVAL)
{
  //does help to regular execute a repeating task like checking for a display update
  if ((millis() - *lastExecution) >= REPEATING_INTERVAL)
  {
    *lastExecution = millis();
    return true;
  }
  return false;
}

void next_pallette(boolean selectNext)
{
  //switches to the next or prevoius color pallette
  if (selectNext)
  {
    if (palette == TOTAL_PALETTES)
      palette = 0;
    else
      palette = (palette + 1) % TOTAL_PALETTES;
  } else
  {
    if (palette == 0)
      palette = TOTAL_PALETTES;
    else
      palette = (palette - 1) % TOTAL_PALETTES;
  }
  save_values_in_eeprom();
#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_NEXT_PALLETTE_TITLE), F(LNG_NEXT_PALLETTE_TITLE), false);
  print_to_log(F(LNG_NEXT_PALLETTE_TITLE), String(palette + 1), false);
  print_to_log(F(LNG_NEXT_PALLETTE_TITLE), F(LNG_NEXT_PALLETTE_PALLETTE_SELECTED), true);
#endif
  oldHours = 99;
  update_led_display();
}

void next_mode()
{
  //switches the actual mode to the next mode
  mode = mode + 1;

  if (mode >= MAX_MODES)
    mode = 0;

  save_values_in_eeprom();

#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_NEXT_MODE_TITLE), F(LNG_NEXT_MODE_MODE_CHANGED_TO), false);
  print_to_log(F(LNG_NEXT_MODE_TITLE), String(mode), true);
#endif
  update_led_display();
}

void setup_brightness(boolean incr)
{
  //sets the brightness of the led display
  if (incr)
  {
    if (brightnessDesired < 0.90)
      brightnessDesired += 0.1;
    else
      brightnessDesired = 1.0;
  }
  else
  {
    if (brightnessDesired > 0.10)
      brightnessDesired -= 0.1;
    else
      brightnessDesired = 0.05;
  }
    
  save_values_in_eeprom();
#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_SETUP_BRIGHTNESS_TITLE), F(LNG_SETUP_BRIGHTNESS_TO), false);
  print_to_log(F(LNG_SETUP_BRIGHTNESS_TITLE), String(brightnessDesired), false);
  print_to_log(F(LNG_SETUP_BRIGHTNESS_TITLE), F(LNG_SETUP_BRIGHTNESS_SET_UP), true);
#endif
  oldHours = 99;
  update_led_display();
}

void setup_fade_time(boolean direction)
{
  //sets the fadeDelayTime. Tn rainbow_transistion_mode the fadeDelayTime defines how long a selected color will stay visible.
  //So ot defines how fast(or slow) the transistion between colors will happen.
  if (direction)
  {
    if (fadeDelayTime < 20000)
      fadeDelayTime += 100;
  } else
  {
    if (fadeDelayTime >= 110)
      fadeDelayTime -= 100;
  }

  save_values_in_eeprom();
#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_SETUP_FADE_TIME_TITLE), F(LNG_SETUP_FADE_TIME_SET_UP_TO), false);
  print_to_log(F(LNG_SETUP_FADE_TIME_TITLE), String(fadeDelayTime), false);
  print_to_log(F(LNG_SETUP_FADE_TIME_TITLE), F(LNG_SETUP_FADE_TIME_SET_UP_TO_UNIT), true);
#endif
  update_led_display();
}

void toggle_on_off()
{
  if (on)
  {
    led_display_off();
  } else
  {
    led_display_on();
  }
}

void led_display_on()
{
  //switches the led display on
  if (!on)
  {
    oldHours = 99;
    on = true;
    update_led_display();
  }
}

void led_display_off()
{
  //switches the led display off
  if (on)
  {
    set_all_fibonacci_pixel(black);
    on = false;
    update_led_display();
  }
}

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
// == Timeclock =============================================================================================================================================


#ifdef TIME_CLOCK_ENABLED
void setup_switch_on_time(uint8_t hourLocal, uint8_t minuteLocal)
{
  timeclockHourOn = hourLocal;
  timeclockMinuteOn = minuteLocal;
#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_SETUP_SWITCH_ON_TIME_TITLE), F(LNG_SETUP_SWITCH_ON_TIME_SETUP_TO_MESSAGE), false);
  print_to_log(F(LNG_SETUP_SWITCH_ON_TIME_TITLE), clock_time_formatted(timeclockHourOn, timeclockMinuteOn), true);
#endif //I2C_DISPLAY_INSTALLED
  save_values_in_eeprom();
}

void setup_switch_off_time(uint8_t hourLocal, uint8_t minuteLocal)
{
  timeclockHourOff = hourLocal;
  timeclockMinuteOff = minuteLocal;
#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_SETUP_SWITCH_OFF_TIME_TITLE), F(LNG_SETUP_SWITCH_OFF_TIME_SETUP_TO_MESSAGE), false);
  print_to_log(F(LNG_SETUP_SWITCH_ON_TIME_TITLE), clock_time_formatted(timeclockHourOff, timeclockMinuteOff), true);
#endif //I2C_DISPLAY_INSTALLED
  save_values_in_eeprom();
}

void switch_on_timeclock()
{
  timeclockEnabled = true;
#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_SWITCH_ON_TIMECLOCK_TITLE), F(LNG_SWITCH_ON_TIMECLOCK_SUCCESS_MESSAGE), true);
#endif //I2C_DISPLAY_INSTALLED
  save_values_in_eeprom();
}

void switch_off_timeclock()
{
  timeclockEnabled = false;
#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_SWITCH_OFF_TIMECLOCK_TITLE), F(LNG_SWITCH_OFF_TIMECLOCK_SUCCESS_MESSAGE), true);
#endif //I2C_DISPLAY_INSTALLED
  save_values_in_eeprom();
}

void check_timeclock()
{
  if (timeclockEnabled)
  {
    if (timeclockHourOn == hour() && timeclockMinuteOn == minute())
    {
      led_display_on();
    } else if (timeclockHourOff == hour() && timeclockMinuteOff == minute())
    {
      led_display_off();
    }
  }
}
#endif //TIME_CLOCK_ENABLED

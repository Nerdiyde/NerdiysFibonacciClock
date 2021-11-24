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
// == EEPROM Stuff ===========================================================================================================================================


void load_eeprom_data()
{
  //load all settings from eeprom in global variables
#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_LOAD_EEPROM_DATA_TITLE), F(LNG_LOAD_EEPROM_DATA_LOADED), true);
#endif //I2C_DISPLAY_INSTALLED

  brightnessDesired = (float)(((float)EEPROM.read(BRIGHTNESS_EEPROM_ADRESS)) / 100.0);
  mode = EEPROM.read(MODE_EEPROM_ADRESS);
  palette = EEPROM.read(PALETTE_EEPROM_ADRESS);
  fadeDelayTime = EEPROM.read(FADE_DELAY_EEPROM_ADRESS);

#ifdef TIME_CLOCK_ENABLED
  timeclockHourOn = EEPROM.read(ZEITSCHALTUHR_STUNDE_EIN_EEPROM_ADRESSE);
  timeclockMinuteOn = EEPROM.read(ZEITSCHALTUHR_MINUTE_EIN_EEPROM_ADRESSE);
  timeclockHourOff = EEPROM.read(ZEITSCHALTUHR_STUNDE_AUS_EEPROM_ADRESSE);
  timeclockMinuteOff = EEPROM.read(ZEITSCHALTUHR_MINUTE_AUS_EEPROM_ADRESSE);
  timeclockEnabled = EEPROM.read(ZEITSCHALTUHR_AKTIVIERT_EEPROM_ADRESSE);

  if (timeclockHourOn > 24)
    timeclockHourOn = TIME_CLOCK_HOUR_ON_STANDARD_VALUE;
  if (timeclockHourOff > 24)
    timeclockHourOff = TIME_CLOCK_HOUR_OFF_STANDARD_VALUE;
  if (timeclockMinuteOn > 60)
    timeclockMinuteOn = TIME_CLOCK_MINUTE_ON_STANDARD_VALUE;
  if (timeclockMinuteOff > 60)
    timeclockMinuteOff = TIME_CLOCK_MINUTE_OFF_STANDARD_VALUE;
#endif //TIME_CLOCK_ENABLED

  if (brightnessDesired >= 1.0)
    brightnessDesired = 1.0;
  if (brightnessDesired <= 0.0)
    brightnessDesired = 0.1;
    
  if (mode >= MAX_MODES)
    mode = 0;
  if (palette >= TOTAL_PALETTES)
    palette = 0;

  save_values_in_eeprom();

#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_LOAD_EEPROM_DATA_TITLE), F(LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_TITLE), true);
  String outputLocal = LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_BRIGHTNESS + String(brightnessDesired);
  print_to_log(F(LNG_LOAD_EEPROM_DATA_TITLE), outputLocal, true);
  outputLocal = LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_MODE + String(mode);
  print_to_log(F(LNG_LOAD_EEPROM_DATA_TITLE), outputLocal, true);
  outputLocal = LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_PALETTE + String(palette);
  print_to_log(F(LNG_LOAD_EEPROM_DATA_TITLE), outputLocal, true);
  outputLocal = LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_F_DELAY_TIME + String(fadeDelayTime);
  print_to_log(F(LNG_LOAD_EEPROM_DATA_TITLE), outputLocal, true);

#ifdef TIME_CLOCK_ENABLED
  outputLocal = LNG_LOAD_EEPROM_DATA_TIMECLOCK_HOUR_ON + clock_time_formatted(timeclockHourOn, timeclockMinuteOn);
  print_to_log(F(LNG_LOAD_EEPROM_DATA_TITLE), outputLocal, true);
  outputLocal = LNG_LOAD_EEPROM_DATA_TIMECLOCK_HOUR_OFF + clock_time_formatted(timeclockHourOff, timeclockMinuteOff);
  print_to_log(F(LNG_LOAD_EEPROM_DATA_TITLE), outputLocal, true);
  outputLocal = LNG_LOAD_EEPROM_DATA_TIMECLOCK_ACTIVATED + String(timeclockEnabled);
  print_to_log(F(LNG_LOAD_EEPROM_DATA_TITLE), outputLocal, true);
#endif //TIME_CLOCK_ENABLED

#endif //I2C_DISPLAY_INSTALLED
}

void save_values_in_eeprom()
{
  //save (or update) all settings in eeprom that should be savaed
  EEPROM.update(MODE_EEPROM_ADRESS, mode);
  EEPROM.update(BRIGHTNESS_EEPROM_ADRESS, (uint8_t)(brightnessDesired * 100));
  EEPROM.update(PALETTE_EEPROM_ADRESS, palette);
  EEPROM.update(FADE_DELAY_EEPROM_ADRESS, fadeDelayTime);

#ifdef TIME_CLOCK_ENABLED
  EEPROM.update(ZEITSCHALTUHR_STUNDE_EIN_EEPROM_ADRESSE, timeclockHourOn);
  EEPROM.update(ZEITSCHALTUHR_MINUTE_EIN_EEPROM_ADRESSE, timeclockMinuteOn);
  EEPROM.update(ZEITSCHALTUHR_STUNDE_AUS_EEPROM_ADRESSE, timeclockHourOff);
  EEPROM.update(ZEITSCHALTUHR_MINUTE_AUS_EEPROM_ADRESSE, timeclockMinuteOff);
  EEPROM.update(ZEITSCHALTUHR_AKTIVIERT_EEPROM_ADRESSE, timeclockEnabled);
#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_SAVE_EEPROM_DATA_TITLE), F(LNG_SAVE_EEPROM_DATA_MESSAGE), true);
#endif //I2C_DISPLAY_INSTALLED
#endif //TIME_CLOCK_ENABLED

}

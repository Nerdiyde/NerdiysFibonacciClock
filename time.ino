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
// == Time ==================================================================================================================================================


void show_time_on_led_display(byte hours, byte minutes)
{
  //updates the led display and shows the actual time on it
  if (oldHours == hours && oldMinutes / 5 == minutes / 5)
    return;

#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_SHOW_TIME_ON_LED_DISPLAY_TITLE), F(LNG_SHOW_TIME_ON_LED_DISPLAY_MESSAGE), true);
#endif

  oldHours = hours;
  oldMinutes = minutes;

  for (int i = 0; i < CLOCK_PIXELS; i++)
    bits[i] = 0;

  setBits(hours, 0x01);
  setBits(minutes / 5, 0x02);

  for (int i = 0; i < CLOCK_PIXELS; i++)
  {
    set_fibonacci_pixel(i, color_value_from_pallete(palette, bits[i]));
    strip.show();
  }
}

uint32_t color_value_from_pallete(uint8_t palettenNummer, uint8_t bitNummer)
{
  //converts the rgb values which are saved in colors-array to uint32_t-color value
  return strip.Color(brightness * colors[palettenNummer][bitNummer][0], brightness * colors[palettenNummer][bitNummer][1], brightness * colors[palettenNummer][bitNummer][2]);
}

String runtime_formatted()
{
  //calculates a formatted system-runtime and returns it as String
  unsigned long millisLocal = millis();
  uint8_t hours = millisLocal / 3600000;
  uint8_t minutes = (millisLocal % 3600000) / 60000;
  uint8_t seconds = ((millisLocal % 3600000) % 60000) / 1000;
  uint8_t ms = ((millisLocal % 3600000) % 60000) % 1000;
  uint8_t days = hours / 24;

  return String(days) + LNG_RUNTIME_FORMATTED_DAYS + String(hours) + LNG_RUNTIME_FORMATTED_HOUR_UNIT + String(minutes) + LNG_RUNTIME_FORMATTED_MINUTE_UNIT + String(seconds) + LNG_RUNTIME_FORMATTED_SECONDS_UNIT + String(ms) + LNG_RUNTIME_FORMATTED_MILLISECONDS_UNIT;
}

#ifndef I2C_DISPLAY_INSTALLED
void print_time_to_serial_output()
{
  //prints the actual time, runtime and mode to serial console
  String outputLocal = LNG_PRINT_TIME_TO_SERIAL_OUTPUT_ACTUAL_MODE + String(mode);
  print_to_log(F(LNG_PRINT_TIME_TO_SERIAL_OUTPUT_TITLE), outputLocal, true);
}
#endif

String clock_time_formatted(uint8_t hourLocal, uint8_t minuteLocal)
{
  //returns the passed time as formatted clock time as String
  String timeLocal;

  if (hourLocal < 10) {
    timeLocal = "0" + String(hourLocal);
  } else
  {
    timeLocal += String(hourLocal);
  }

  if (minuteLocal < 10) {
    timeLocal += ":0" + String(minuteLocal);
  } else
  {
    timeLocal += ":" + String(minuteLocal);
  }
  return timeLocal;
}

String clock_time_with_seconds_formatted()
{
  //returns the actual formatted clock time with seconds as String
  String time = clock_time_formatted(hour(), minute());

  if (second() >= 0 && second() < 10) {
    time += ":0" + String(second());
  } else
  {
    time += ":" + String(second());
  }
  return time ;
}

String timeofday_plus_seconds_and_date_formatted()
{
  //returns the actual formatted clock time with seconds and date as String
  String dateString = clock_time_with_seconds_formatted();

  if (day() >= 0 && day() < 10)
  {
    dateString += " 0" + String(day());
  } else
  {
    dateString += " " + String(day());
  }

  if (month() >= 0 && month() < 10)
  {
    dateString += ".0" + String(month());
  } else
  {
    dateString += "." + String(month());
  }

  return dateString +  "." + String(year());
}


String day_phase()
{
  //returns the actual day-phase
  String time;
  if (isAM())
  {
    time += "am";
  } else
  {
    time += "pm";
  }
  return time;
}


void setup_absolute_clock_time(uint8_t secondLocal, uint8_t minuteLocal, uint8_t hourLocal, uint8_t dayLocal, uint8_t monthLocal, uint16_t yearLocal)
{
  //this function writes the passed time variables to the real time clock and system clock
  tmElements_t timeElements;

  timeElements.Year = yearLocal - 1970;
  timeElements.Month = monthLocal;
  timeElements.Day = dayLocal;
  timeElements.Hour = hourLocal;
  timeElements.Minute = minuteLocal;
  timeElements.Second = secondLocal;
  RTC.write(timeElements);
  setSyncProvider(RTC.get);
#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_SETUP_ABSOLUTE_CLOCK_TIME_TITLE), F(LNG_SETUP_ABSOLUTE_CLOCK_TIME_SUCCESS_MESSAGE), false);
#endif

#ifndef I2C_DISPLAY_INSTALLED
  print_time_to_serial_output();
#endif
  update_led_display();
}

void setup_clock_time_hour(boolean increase)
{
  uint8_t hourLocal = 0;
  if (increase)
  {
    if (hour() + 1 <= 23)
      hourLocal = hour() + 1;
    else
      hourLocal = 0;
  }
  else
  {
    if (hour() - 1 >= 0)
      hourLocal = hour() - 1;
    else
      hourLocal = 23;
  }

  setup_absolute_clock_time(second(), minute(), hourLocal, day(), month(), year());

#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_SETUP_CLOCK_TIME_HOUR_TITLE), F(LNG_SETUP_CLOCK_TIME_HOUR_SUCCESS_MESSAGE), true);
#endif

#ifndef I2C_DISPLAY_INSTALLED
  print_time_to_serial_output();
#endif
  update_led_display();
}

void setup_clock_time_minute(boolean increase)
{
  uint8_t minuteLocal = 0;
#ifndef I2C_DISPLAY_INSTALLED
  if (increase)
  {
    if (((minute() - minute() % 5) + 5) < 60)
      minuteLocal = ((minute() - minute() % 5) + 5);
    else
      minuteLocal = 0;
  }
  else
  {
    if (((minute() - minute() % 5) - 5) >= 0)
      minuteLocal = ((minute() - minute() % 5) - 5);
    else
      minuteLocal = 55;
  }
#else
  if (increase)
  {
    if (minute() < 60)
      minuteLocal = minute() + 1;
    else
      minuteLocal = 0;
  }
  else
  {
    if (minute() > 0)
      minuteLocal = minute() - 1;
    else
      minuteLocal = 59;
  }
#endif

  setup_absolute_clock_time(second(), minuteLocal, hour(), day(), month(), year());

#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_SETUP_CLOCK_TIME_MINUTE_TITLE), F(LNG_SETUP_CLOCK_TIME_MINUTE_SUCCESS_MESSAGE), true);
#endif

#ifndef I2C_DISPLAY_INSTALLED
  print_time_to_serial_output();
#endif
  update_led_display();
}


void setup_clock_time_year(boolean increase)
{
  uint16_t yearLocal = 0;
  if (increase)
  {
    if (year() < MAX_YEAR)
      yearLocal = year() + 1;
    else
      yearLocal = MIN_YEAR;
  } else
  {
    if (year() > MIN_YEAR)
      yearLocal = year() - 1;
    else
      yearLocal = MAX_YEAR ;
  }

  if (yearLocal > MAX_YEAR)
    yearLocal = MAX_YEAR;

  if (yearLocal < MIN_YEAR)
    yearLocal = MIN_YEAR;

  setup_absolute_clock_time(second(), minute(), hour(), day(), month(), yearLocal);

#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_SETUP_CLOCK_TIME_YEAR_TITLE), F(LNG_SETUP_CLOCK_TIME_YEAR_SUCCESS_MESSAGE), true);
#endif

#ifndef I2C_DISPLAY_INSTALLED
  print_time_to_serial_output();
#endif
  update_led_display();
}

void setup_clock_time_month(boolean increase)
{
  uint8_t monthLocal = 0;
  if (increase)
  {
    if (month() < 12)
      monthLocal = month() + 1;
    else
      monthLocal = 1;
  }
  else
  {
    if (month() > 1)
      monthLocal = month() - 1;
    else
      monthLocal = 12;
  }

  setup_absolute_clock_time(second(), minute(), hour(), day(), monthLocal, year());

#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_SETUP_CLOCK_TIME_MONTH_TITLE), F(LNG_SETUP_CLOCK_TIME_MONTH_SUCCESS_MESSAGE), true);
#endif

#ifndef I2C_DISPLAY_INSTALLED
  print_time_to_serial_output();
#endif
  update_led_display();
}

void setup_clock_time_day(boolean increase)
{
  uint8_t dayLocal = 0;
  if (increase)
  {
    if (day() < 31)
      dayLocal = day() + 1;
    else
      dayLocal = 1;
  }
  else
  {
    if (day() > 1)
      dayLocal = day() - 1;
    else
      dayLocal = 31;
  }

  setup_absolute_clock_time(second(), minute(), hour(), dayLocal, month(), year());

#ifndef I2C_DISPLAY_INSTALLED
  print_to_log(F(LNG_SETUP_CLOCK_TIME_DAY), F(LNG_SETUP_CLOCK_TIME_DAY_SUCCESS_MESSAGE), true);
#endif

#ifndef I2C_DISPLAY_INSTALLED
  print_time_to_serial_output();
#endif
  update_led_display();
}

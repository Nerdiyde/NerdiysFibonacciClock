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
// == Hardware Inputs =======================================================================================================================================


void check_hardware_inputs()
{
  //check either hardware push buttons or capacitive sensors
#ifndef PUSH_BUTTONS_INSTALLED
  check_capacitive_sensors();
#else
  check_push_buttons();
#endif

  //save actual timestamp if any button is pressed to update the i2c display if installed.
#ifdef I2C_DISPLAY_INSTALLED
  if (touchAreaHourWasTouched
      || touchAreaPlusWasTouched
      || touchAreaMinusWasTouched
      || touchAreaMinuteWasTouched
      || touchAreaBrightnessWasTouched
      || touchAreaModeWasTouched)
  {
    button_pressed();
  }
#endif
      
  //check for combination of pressed buttons and act accordingly
  if (touchAreaMinuteActualTouched && touchAreaModeActualTouched && touchAreaPlusWasTouched)
  {
    //increase month
    setup_clock_time_month(true);
  } else   if (touchAreaMinuteActualTouched && touchAreaModeActualTouched && touchAreaMinusWasTouched)
  {
    //decrease month
    setup_clock_time_month(false);
  } else  if (touchAreaBrightnessActualTouched && touchAreaModeActualTouched && touchAreaPlusWasTouched)
  {
    //increase day
    setup_clock_time_day(true);
  } else  if (touchAreaBrightnessActualTouched && touchAreaModeActualTouched && touchAreaMinusWasTouched)
  {
    //decrease day
    setup_clock_time_day(false);
  } else  if (touchAreaBrightnessActualTouched && touchAreaHourActualTouched && touchAreaPlusWasTouched)
  {
    //increase year
    setup_clock_time_year(true);
  } else  if (touchAreaBrightnessActualTouched && touchAreaHourActualTouched && touchAreaMinusWasTouched)
  {
    //decrease year
    setup_clock_time_year(false);
  } else   if (touchAreaHourActualTouched && !touchAreaBrightnessActualTouched && touchAreaPlusWasTouched)
  {
    setup_clock_time_hour(true);
  } else  if (touchAreaHourActualTouched && !touchAreaBrightnessActualTouched && touchAreaMinusWasTouched)
  {
    setup_clock_time_hour(false);
  } else  if (!touchAreaModeWasTouched && touchAreaMinuteActualTouched && touchAreaPlusWasTouched)
  {
    setup_clock_time_minute(true);
  } else  if (!touchAreaModeWasTouched && touchAreaMinuteActualTouched && touchAreaMinusWasTouched)
  {
    setup_clock_time_minute(false);
  } else  if (touchAreaBrightnessActualTouched && !touchAreaHourActualTouched && !touchAreaModeWasTouched && touchAreaPlusWasTouched)
  {
    setup_brightness(true);
  } else  if (touchAreaBrightnessActualTouched && !touchAreaHourActualTouched && !touchAreaModeWasTouched && touchAreaMinusWasTouched)
  {
    setup_brightness(false);
  } else  if (touchAreaMinuteActualTouched && touchAreaHourWasTouched)
  {
    toggle_on_off();
  } else  if (touchAreaModeWasTouched && !touchAreaMinuteActualTouched && !touchAreaBrightnessActualTouched)
  {
    next_mode();
  } else  if (touchAreaPlusWasTouched && !touchAreaMinuteActualTouched)
  {
    if (mode == 0)
    {
      next_pallette(true);
    } else
    {
      setup_fade_time(true);
    }

  } else if (touchAreaMinusWasTouched)
  {
    if (mode == 0)
    {
      next_pallette(false);
    } else
    {
      setup_fade_time(false);
    }
  }
}

#ifndef PUSH_BUTTONS_INSTALLED

void check_capacitive_sensors()
{
  //checks if any capacitive sensors got touched, released or still touched
  long tasteWertHour =  sensorAreaHour.capacitiveSensor(30);
  long tasteWertMinute =  sensorAreaMinute.capacitiveSensor(30);
  long tasteWertBrightness =  sensorAreaBrightness.capacitiveSensor(30);
  long tasteWertMode =  sensorAreaMode.capacitiveSensor(30);
  long tasteWertPlus =  sensorAreaPlus.capacitiveSensor(30);
  long tasteWertMinus =  sensorAreaMinus.capacitiveSensor(30);

  touchAreaHourReleased = touchAreaHourActualTouched &&  (tasteWertHour <= RELEASE_THRESHOLD);
  touchAreaMinuteReleased = touchAreaMinuteActualTouched &&  (tasteWertMinute <= RELEASE_THRESHOLD);
  touchAreaBrightnessReleased = touchAreaBrightnessActualTouched &&  (tasteWertBrightness <= RELEASE_THRESHOLD);
  touchAreaModeReleased = touchAreaModeActualTouched &&  (tasteWertMode <= RELEASE_THRESHOLD);
  touchAreaPlusReleased = touchAreaPlusActualTouched &&  (tasteWertPlus <= RELEASE_THRESHOLD);
  touchAreaMinusReleased = touchAreaMinusActualTouched &&  (tasteWertMinus <= RELEASE_THRESHOLD);

  if (touchAreaHourReleased)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_CAPACITIVE_SENSORS_TITLE), F(LNG_CHECK_CAPACITIVE_SENSORS_HOUR_RELEASED), true);
#endif
    touchAreaHourActualTouched = false;
  }
  if (touchAreaMinuteReleased)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_CAPACITIVE_SENSORS_TITLE), F(LNG_CHECK_CAPACITIVE_SENSORS_MINUTE_RELEASED), true);
#endif
    touchAreaMinuteActualTouched = false;
  }
  if (touchAreaBrightnessReleased)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_CAPACITIVE_SENSORS_TITLE), F(LNG_CHECK_CAPACITIVE_SENSORS_BRIGHTNESS_RELEASED), true);
#endif
    touchAreaBrightnessActualTouched = false;
  }
  if (touchAreaModeReleased)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_CAPACITIVE_SENSORS_TITLE), F(LNG_CHECK_CAPACITIVE_SENSORS_MODE_RELEASED), true);
#endif
    touchAreaModeActualTouched = false;
  }
  if (touchAreaPlusReleased)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_CAPACITIVE_SENSORS_TITLE), F(LNG_CHECK_CAPACITIVE_SENSORS_PLUS_RELEASED), true);
#endif
    touchAreaPlusActualTouched = false;
  }
  if (touchAreaMinusReleased)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_CAPACITIVE_SENSORS_TITLE), F(LNG_CHECK_CAPACITIVE_SENSORS_MINUS_RELEASED), true);
#endif
    touchAreaMinusActualTouched = false;
  }

  touchAreaHourWasTouched = (!touchAreaHourWasTouched && !touchAreaHourActualTouched)  && tasteWertHour >= TOUCH_THRESHOLD;
  touchAreaMinuteWasTouched = (!touchAreaMinuteWasTouched && !touchAreaMinuteActualTouched)  && tasteWertMinute >= TOUCH_THRESHOLD;
  touchAreaBrightnessWasTouched = (!touchAreaBrightnessWasTouched && !touchAreaBrightnessActualTouched)  && tasteWertBrightness >= TOUCH_THRESHOLD;
  touchAreaModeWasTouched = (!touchAreaModeWasTouched && !touchAreaModeActualTouched)  && tasteWertMode >= TOUCH_THRESHOLD;
  touchAreaPlusWasTouched = (!touchAreaPlusWasTouched && !touchAreaPlusActualTouched)  && tasteWertPlus >= TOUCH_THRESHOLD;
  touchAreaMinusWasTouched = (!touchAreaMinusWasTouched && !touchAreaMinusActualTouched)  && tasteWertMinus >= TOUCH_THRESHOLD;

  if (touchAreaHourWasTouched)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_CAPACITIVE_SENSORS_TITLE), F(LNG_CHECK_CAPACITIVE_SENSORS_HOUR_TOUCHED), true);
#endif
    touchAreaHourActualTouched = true;
  }
  if (touchAreaMinuteWasTouched)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_CAPACITIVE_SENSORS_TITLE), F(LNG_CHECK_CAPACITIVE_SENSORS_MINUTE_TOUCHED), true);
#endif
    touchAreaMinuteActualTouched = true;
  }
  if (touchAreaBrightnessWasTouched)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_CAPACITIVE_SENSORS_TITLE), F(LNG_CHECK_CAPACITIVE_SENSORS_BRIGHTNESS_TOUCHED), true);
#endif
    touchAreaBrightnessActualTouched = true;
  }
  if (touchAreaModeWasTouched)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_CAPACITIVE_SENSORS_TITLE), F(LNG_CHECK_CAPACITIVE_SENSORS_MODE_TOUCHED), true);
#endif
    touchAreaModeActualTouched = true;
  }
  if (touchAreaPlusWasTouched)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_CAPACITIVE_SENSORS_TITLE), F(LNG_CHECK_CAPACITIVE_SENSORS_PLUS_TOUCHED), true);
#endif
    touchAreaPlusActualTouched = true;
  }
  if (touchAreaMinusWasTouched)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_CAPACITIVE_SENSORS_TITLE), F(LNG_CHECK_CAPACITIVE_SENSORS_MINUS_TOUCHED), true);
#endif
    touchAreaMinusActualTouched = true;
  }

  touchAreaHourOld =  tasteWertHour;
  touchAreaMinuteOld =  tasteWertMinute;
  touchAreaBrightnessOld =  tasteWertBrightness;
  touchAreaModeOld =  tasteWertMode;
  touchAreaPlusOld =  tasteWertPlus;
  touchAreaMinusOld =  tasteWertMinus;
}

#else

void init_push_buttons()
{
  //initializes the input-pins for the push buttons
  pinMode(HOUR_PIN, INPUT_PULLUP);
  pinMode(MINUTE_PIN, INPUT_PULLUP);
  pinMode(BRIGHTNESS_PIN, INPUT_PULLUP);
  pinMode(MODE_PIN, INPUT_PULLUP);
  pinMode(PLUS_PIN, INPUT_PULLUP);
  pinMode(MINUS_PIN, INPUT_PULLUP);
}

void check_push_buttons()
{
  //checks if any push button got touched, released or still touched
  boolean tasteWertHour =  digitalRead(HOUR_PIN);
  boolean tasteWertMinute =   digitalRead(MINUTE_PIN);
  boolean tasteWertBrightness =   digitalRead(BRIGHTNESS_PIN);
  boolean tasteWertMode =   digitalRead(MODE_PIN);
  boolean tasteWertPlus =  digitalRead(PLUS_PIN);
  boolean tasteWertMinus =   digitalRead(MINUS_PIN);

  /*  
    Serial.print("touchAreaModeActualTouched: ");
    Serial.println(touchAreaModeActualTouched);
    Serial.print("tasteWertMode: ");
    Serial.println(tasteWertMode);
*/
  touchAreaHourReleased = touchAreaHourActualTouched &&  tasteWertHour;
  touchAreaMinuteReleased = touchAreaMinuteActualTouched &&  tasteWertMinute;
  touchAreaBrightnessReleased = touchAreaBrightnessActualTouched &&  tasteWertBrightness;
  touchAreaModeReleased = touchAreaModeActualTouched &&  tasteWertMode;
  touchAreaPlusReleased = touchAreaPlusActualTouched &&  tasteWertPlus;
  touchAreaMinusReleased = touchAreaMinusActualTouched &&  tasteWertMinus;

  if (touchAreaHourReleased)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_PUSH_BUTTONS_TITLE), F(LNG_CHECK_PUSH_BUTTON_HOUR_RELEASED), true);
#endif
    touchAreaHourActualTouched = false;
  }
  
  if (touchAreaMinuteReleased)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_PUSH_BUTTONS_TITLE), F(LNG_CHECK_PUSH_BUTTON_MINUTE_RELEASED), true);
#endif
    touchAreaMinuteActualTouched = false;
  }
  
  if (touchAreaBrightnessReleased)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_PUSH_BUTTONS_TITLE), F(LNG_CHECK_PUSH_BUTTON_BRIGHTNESS_RELEASED), true);
#endif
    touchAreaBrightnessActualTouched = false;
  }
  
  if (touchAreaModeReleased)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_PUSH_BUTTONS_TITLE), F(LNG_CHECK_PUSH_BUTTON_MODE_RELEASED), true);
#endif
    touchAreaModeActualTouched = false;
  }
  
  if (touchAreaPlusReleased)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_PUSH_BUTTONS_TITLE), F(LNG_CHECK_PUSH_BUTTON_PLUS_RELEASED), true);
#endif
    touchAreaPlusActualTouched = false;
  }
  
  if (touchAreaMinusReleased)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_PUSH_BUTTONS_TITLE), F(LNG_CHECK_PUSH_BUTTON_MINUS_RELEASED), true);
#endif
    touchAreaMinusActualTouched = false;
  }

  touchAreaHourWasTouched = (!touchAreaHourWasTouched && !touchAreaHourActualTouched)  && !tasteWertHour;
  touchAreaMinuteWasTouched = (!touchAreaMinuteWasTouched && !touchAreaMinuteActualTouched)  && !tasteWertMinute;
  touchAreaBrightnessWasTouched = (!touchAreaBrightnessWasTouched && !touchAreaBrightnessActualTouched)  && !tasteWertBrightness;
  touchAreaModeWasTouched = (!touchAreaModeWasTouched && !touchAreaModeActualTouched)  && !tasteWertMode;
  touchAreaPlusWasTouched = (!touchAreaPlusWasTouched && !touchAreaPlusActualTouched)  && !tasteWertPlus;
  touchAreaMinusWasTouched = (!touchAreaMinusWasTouched && !touchAreaMinusActualTouched)  && !tasteWertMinus;

  if (touchAreaHourWasTouched)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_PUSH_BUTTONS_TITLE), F(LNG_CHECK_PUSH_BUTTON_HOUR_TOUCHED), true);
#endif
    touchAreaHourActualTouched = true;
  }
  if (touchAreaMinuteWasTouched)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_PUSH_BUTTONS_TITLE), F(LNG_CHECK_PUSH_BUTTON_MINUTE_TOUCHED), true);
#endif
    touchAreaMinuteActualTouched = true;
  }
  if (touchAreaBrightnessWasTouched)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_PUSH_BUTTONS_TITLE), F(LNG_CHECK_PUSH_BUTTON_BRIGHTNESS_TOUCHED), true);
#endif
    touchAreaBrightnessActualTouched = true;
  }
  if (touchAreaModeWasTouched)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_PUSH_BUTTONS_TITLE), F(LNG_CHECK_PUSH_BUTTON_MODE_TOUCHED), true);
#endif
    touchAreaModeActualTouched = true;
  }
  if (touchAreaPlusWasTouched)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_PUSH_BUTTONS_TITLE), F(LNG_CHECK_PUSH_BUTTON_PLUS_TOUCHED), true);
#endif
    touchAreaPlusActualTouched = true;
  }
  if (touchAreaMinusWasTouched)
  {
#ifndef I2C_DISPLAY_INSTALLED
    print_to_log(F(LNG_CHECK_PUSH_BUTTONS_TITLE), F(LNG_CHECK_PUSH_BUTTON_MINUS_TOUCHED), true);
#endif
    touchAreaMinusActualTouched = true;
  }

  touchAreaHourOld =  tasteWertHour;
  touchAreaMinuteOld =  tasteWertMinute;
  touchAreaBrightnessOld =  tasteWertBrightness;
  touchAreaModeOld =  tasteWertMode;
  touchAreaPlusOld =  tasteWertPlus;
  touchAreaMinusOld =  tasteWertMinus;

}
#endif

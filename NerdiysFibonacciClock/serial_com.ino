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
// == Serial Console & Communication =========================================================================================================================


#ifndef I2C_DISPLAY_INSTALLED
void check_for_received_serial_commands()
{
  //Checks if any serial commands are received. therefore it is important, that every comand is finalized by a new-line-charakter(ASCII:13).
  char Zeichen;
  while (Serial.available())
  {
    Zeichen = (char)Serial.read();
    if (Zeichen == 13)
    {
      evaluate_serial_inputs();
      break;
    } else
    {
      serialBuffer += Zeichen;
    }
  }
}

void evaluate_serial_inputs()
{
  //evaluates if a correct serial command is received and acts accordingly
  if (serialBuffer ==  LNG_EVALUATE_SERIAL_INPUTS_STATE)
  {
    print_actual_state();
  } else if (serialBuffer ==  LNG_EVALUATE_SERIAL_INPUTS_ON)
  {
    led_display_on();
  } else if (serialBuffer ==  LNG_EVALUATE_SERIAL_INPUTS_OFF)
  {
    led_display_off();
  }
#ifdef TIME_CLOCK_ENABLED
  else if (serialBuffer ==  LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_ON)
  {
    switch_on_timeclock();
  } else if (serialBuffer ==  LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_OFF)
  {
    switch_off_timeclock();
  }
#endif
  else if (serialBuffer ==  LNG_EVALUATE_SERIAL_INPUTS_COMMANDS)
  {
    print_command_list();
  } else if (serialBuffer.indexOf('=') != -1)
  {
    uint16_t empfangenerWert = serialBuffer.substring(serialBuffer.indexOf('=') + 1).toInt();
    String empfangenerParameter = serialBuffer.substring(0, serialBuffer.indexOf('='));
    if (empfangenerParameter == LNG_EVALUATE_SERIAL_INPUTS_MODE)
    {
      if (empfangenerWert < MAX_MODES)
      {
        mode = empfangenerWert;
      } else
      {
        print_value_out_of_bounds_message();
      }
    } else if (empfangenerParameter == LNG_EVALUATE_SERIAL_INPUTS_FADETIME)
    {
      if (empfangenerWert >= 10 && empfangenerWert <= 20000)
      {
        fadeDelayTime = empfangenerWert;
      } else
      {
        print_value_out_of_bounds_message();
      }
    } else if (empfangenerParameter == LNG_EVALUATE_SERIAL_INPUTS_COLOR_PALLETTE)
    {
      if (empfangenerWert <= 10)
      {
        palette = empfangenerWert;
        save_values_in_eeprom();

        String temp = String(LNG_EVALUATE_SERIAL_INPUTS_COLOR_PALLETTE_MESSAGE_NAME) + (palette + 1) + String(LNG_EVALUATE_SERIAL_INPUTS_COLOR_PALLETTE_MESSAGE_SELECTED);
        print_to_log(F(LNG_EVALUATE_SERIAL_INPUTS_TITLE), temp, true);

        oldHours = 99;
        update_led_display();
      } else
      {
        print_value_out_of_bounds_message();
      }
    } else if (empfangenerParameter == LNG_EVALUATE_SERIAL_INPUTS_HOUR)
    {
      if (empfangenerWert <= 23)
      {
        setup_absolute_clock_time(second(), minute(), empfangenerWert, day(), month(), year());
      } else
      {
        print_value_out_of_bounds_message();
      }
    } else if (empfangenerParameter == LNG_EVALUATE_SERIAL_INPUTS_MINUTE)
    {
      if (empfangenerWert <= 59)
      {
        setup_absolute_clock_time(second(), empfangenerWert, hour(), day(), month(), year());
      } else
      {
        print_value_out_of_bounds_message();
      }
    } else if (empfangenerParameter == LNG_EVALUATE_SERIAL_INPUTS_SECONDS)
    {
      if (empfangenerWert <= 59)
      {
        setup_absolute_clock_time(empfangenerWert, minute(), hour(), day(), month(), year());
      } else
      {
        print_value_out_of_bounds_message();
      }
    } else if (empfangenerParameter == LNG_EVALUATE_SERIAL_INPUTS_DAY)
    {
      if (empfangenerWert >= 1 && empfangenerWert <= 31)
      {
        setup_absolute_clock_time(second(), minute(), hour(), empfangenerWert, month(), year());
      } else
      {
        print_value_out_of_bounds_message();
      }
    } else if (empfangenerParameter == LNG_EVALUATE_SERIAL_INPUTS_MONTH)
    {
      if (empfangenerWert >= 1 && empfangenerWert <= 12)
      {
        setup_absolute_clock_time(second(), minute(), hour(), day(), empfangenerWert, year());
      } else
      {
        print_value_out_of_bounds_message();
      }
    } else if (empfangenerParameter == LNG_EVALUATE_SERIAL_INPUTS_YEAR)
    {
      if (empfangenerWert >= 2000 && empfangenerWert <= 2070)
      {
        setup_absolute_clock_time(second(), minute(), hour(), day(), month(), empfangenerWert);
      } else
      {
        print_value_out_of_bounds_message();
      }
    }

#ifdef TIME_CLOCK_ENABLED
    else if (empfangenerParameter == LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_HOUR_ON)
    {
      if (empfangenerWert <= 23)
      {
        setup_switch_on_time(empfangenerWert, timeclockMinuteOn);
      } else
      {
        print_value_out_of_bounds_message();
      }
    } else if (empfangenerParameter == LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_MINUTE_ON)
    {
      if (empfangenerWert <= 59)
      {
        setup_switch_on_time(timeclockHourOn, empfangenerWert);
      } else
      {
        print_value_out_of_bounds_message();
      }
    } else if (empfangenerParameter == LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_HOUR_OFF)
    {
      if (empfangenerWert <= 23)
      {
        setup_switch_off_time(empfangenerWert, timeclockMinuteOff);
      } else
      {
        print_value_out_of_bounds_message();
      }
    } else if (empfangenerParameter == LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_HOUR_OFF)
    {
      if (empfangenerWert <= 59)
      {
        setup_switch_off_time(timeclockHourOff, empfangenerWert);
      } else
      {
        print_value_out_of_bounds_message();
      }
    }
#endif
    else
    {
      print_serial_command_not_found_message();
    }
  } else
  {
    print_serial_command_not_found_message();
  }
  serialBuffer = "";
}

void print_actual_state()
{
  //prints the actual state to serial console
  Serial.println(F(LNG_PRINT_ACTUAL_STATE_HEADER));
  print_time_to_serial_output();
  Serial.print(F(LNG_PRINT_ACTUAL_STATE_BRIGHTNESS));
  Serial.println(brightness);
  Serial.print(F(LNG_PRINT_ACTUAL_STATE_MODE));
  Serial.println(mode);
  Serial.print(F(LNG_PRINT_ACTUAL_STATE_PALLETTE));
  Serial.println(palette + 1);
  Serial.print(F(LNG_PRINT_ACTUAL_STATE_FADEDELAYTIME));
  Serial.println(fadeDelayTime);

#ifdef TIME_CLOCK_ENABLED
  Serial.print(F(LNG_PRINT_ACTUAL_STATE_TIMECLOCK_HOUR_ON));
  Serial.println(timeclockHourOn);
  Serial.print(F(LNG_PRINT_ACTUAL_STATE_TIMECLOCK_MINUTE_ON));
  Serial.println(timeclockMinuteOn);
  Serial.print(F(LNG_PRINT_ACTUAL_STATE_TIMECLOCK_HOUR_OFF));
  Serial.println(timeclockHourOff);
  Serial.print(F(LNG_PRINT_ACTUAL_STATE_TIMECLOCK_MINUTE_OFF));
  Serial.println(timeclockMinuteOff);
  Serial.print(F(LNG_PRINT_ACTUAL_STATE_TIMECLOCK_ENABLED));
  Serial.println(timeclockEnabled);
#endif
  Serial.println(F(LNG_PRINT_ACTUAL_STATE_FOOTER));
}

//Mögliche Befehle ausgeben bei eingabe eines nicht bekannten Befehls über die SerielleSchnittstelle(Uhrzeit einstellen, Modus, Fadegeschw., Farbpalette, ein/Aus)
void print_command_list()
{
  //prints a list of all possible commands
  Serial.println(F(LNG_PRINT_COMMAND_LIST_FOLLOWING_COMMANDS_POSSIBLE));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_COMMANDS));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_STATE));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_ON));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_OFF));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_MODE));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_COLOR_PALLETTE));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_FADE_TIME));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_HOUR));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_MINUTE));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_SECONDS));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_DAY));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_MONTH));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_YEAR));
#ifdef TIME_CLOCK_ENABLED
  Serial.println(F(LNG_PRINT_COMMAND_LIST_TIMECLOCK_ON));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_TIMECLOCK_OFF));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_TIMECLOCK_HOUR_ON));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_TIMECLOCK_MINUTE_ON));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_TIMECLOCK_HOUR_OFF));
  Serial.println(F(LNG_PRINT_COMMAND_LIST_TIMECLOCK_MINUTE_OFF));
#endif
}

void print_to_log(String section, String textToPrint, boolean withLineBreak)
{
  //prints a formatted log message to serial console
  if (lastPrintedSectionGlobal != section)
  {
    Serial.print(section);
    Serial.println(":");
    lastPrintedSectionGlobal = section;
  }
  
  Serial.print("  (");
  Serial.print(F(LNG_PRINT_TO_LOG_RUNTIME));
  Serial.print(runtime_formatted());
  Serial.print(F("): "));

  if (withLineBreak)
  {
    Serial.println(textToPrint);
  } else
  {
    Serial.print(textToPrint);
  }
}

void print_value_out_of_bounds_message()
{
  //prints a error_message if send values are out of the allowed range
  Serial.println(LNG_PRINT_VALUE_OUT_OF_BOUNDS_MESSAGE_MESSAGE);
}

void print_serial_command_not_found_message()
{
  //prints error-message if a uknown command is entered
  Serial.print(F(LNG_PRINT_SERIAL_COMMAND_NOT_FOUND_MESSAGE_1));
  Serial.print(serialBuffer);
  Serial.print(F(LNG_PRINT_SERIAL_COMMAND_NOT_FOUND_MESSAGE_2));
  print_command_list();
}
#endif

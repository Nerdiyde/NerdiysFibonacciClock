// Fibonacci Clock by Fabian Steppat
// Infos on www.nerdiy.de/fibonacciClock
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License Version 2
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
// You will find the latest version of this code at the following address:
// https://github.com/pchretien/fibo
//
// Credits:
//  1.Of course first to Philippe Chrétien for the idea for this clock and that he provides it as an open source project on https://github.com/pchretien/fibo.
//    If you want to thank/support him buy one of his awesome clocks on http://basbrun.com/.
//  2.To all the awesome guys at adafruit.com who made many awesome and important libraries and products.
//    If you want to thank/support them buy one(or more) of their products on www.adafruit.com.
//  3.To PaulStoffregen who also writes a lot of important libraries.
//    He also offers interesting Hardware-Stuff like the Teensy's. if you want to thank/support him buy on of these thingys on https://www.pjrc.com/.
//  4. To all other people on our little planet which contributed to the open source community and make many of them possible.

// == Localization-file for FibonacciClock - English ===========================================================================================================


#ifndef _LANGUAGE_DE_
#define _LANGUAGE_DE_

/*************************** ATTENTION *******************************\
 *
 * To save code space keep text as short as possible.
 *
\*********************************************************************/

#define LNG_SETTINGS_TITLE "Settings"

//load_eeprom_data()
#define LNG_LOAD_EEPROM_DATA_TITLE LNG_SETTINGS_TITLE
#define LNG_LOAD_EEPROM_DATA_LOADED "Read values ​​stored in EEPROM..."
#define LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_TITLE "Following values are loaded:"
#define LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_BRIGHTNESS "Brightness: "
#define LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_MODE "Mode: "
#define LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_PALETTE "Color-Pallette: "
#define LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_F_DELAY_TIME "FadeDelayTime: "

#define LNG_LOAD_EEPROM_DATA_TIMECLOCK_HOUR_ON "Timeclock switches on at: "
#define LNG_LOAD_EEPROM_DATA_TIMECLOCK_HOUR_OFF "Timeclock switches off at: "
#define LNG_LOAD_EEPROM_DATA_TIMECLOCK_ACTIVATED "Timeclock activated: "

//save_values_in_eeprom()
#define LNG_SAVE_EEPROM_DATA_TITLE LNG_SETTINGS_TITLE
#define LNG_SAVE_EEPROM_DATA_MESSAGE "Any changed values ​​have been saved"

//check_capacitive_sensors()
#define LNG_CHECK_CAPACITIVE_SENSORS_TITLE "Buttons"
#define LNG_CHECK_CAPACITIVE_SENSORS_HOUR_RELEASED "Button \"Hour\" was released"
#define LNG_CHECK_CAPACITIVE_SENSORS_MINUTE_RELEASED "Button \"Minute\" was released"
#define LNG_CHECK_CAPACITIVE_SENSORS_BRIGHTNESS_RELEASED "Button \"Brightness\" was released"
#define LNG_CHECK_CAPACITIVE_SENSORS_MODE_RELEASED "Button \"Mode\" was released"
#define LNG_CHECK_CAPACITIVE_SENSORS_PLUS_RELEASED "Button \"Plus\" was released"
#define LNG_CHECK_CAPACITIVE_SENSORS_MINUS_RELEASED "Button \"Minus\" was released"
#define LNG_CHECK_CAPACITIVE_SENSORS_HOUR_TOUCHED "Button \"Hour\" was touched"
#define LNG_CHECK_CAPACITIVE_SENSORS_MINUTE_TOUCHED "Button \"Minute\" was touched"
#define LNG_CHECK_CAPACITIVE_SENSORS_BRIGHTNESS_TOUCHED "Button \"Brightness\" was touched"
#define LNG_CHECK_CAPACITIVE_SENSORS_MODE_TOUCHED "Button \"Mode\" was touched"
#define LNG_CHECK_CAPACITIVE_SENSORS_PLUS_TOUCHED "Button \"Plus\" was touched"
#define LNG_CHECK_CAPACITIVE_SENSORS_MINUS_TOUCHED "Button \"Minus\" was touched"



//check_push_buttons()
#define LNG_CHECK_PUSH_BUTTONS_TITLE LNG_CHECK_CAPACITIVE_SENSORS_TITLE
#define LNG_CHECK_PUSH_BUTTON_HOUR_RELEASED LNG_CHECK_CAPACITIVE_SENSORS_HOUR_RELEASED
#define LNG_CHECK_PUSH_BUTTON_MINUTE_RELEASED LNG_CHECK_CAPACITIVE_SENSORS_MINUTE_RELEASED
#define LNG_CHECK_PUSH_BUTTON_BRIGHTNESS_RELEASED LNG_CHECK_CAPACITIVE_SENSORS_BRIGHTNESS_RELEASED
#define LNG_CHECK_PUSH_BUTTON_MODE_RELEASED LNG_CHECK_CAPACITIVE_SENSORS_MODE_RELEASED
#define LNG_CHECK_PUSH_BUTTON_PLUS_RELEASED LNG_CHECK_CAPACITIVE_SENSORS_PLUS_RELEASED
#define LNG_CHECK_PUSH_BUTTON_MINUS_RELEASED LNG_CHECK_CAPACITIVE_SENSORS_MINUS_RELEASED
#define LNG_CHECK_PUSH_BUTTON_HOUR_TOUCHED LNG_CHECK_CAPACITIVE_SENSORS_HOUR_TOUCHED
#define LNG_CHECK_PUSH_BUTTON_MINUTE_TOUCHED LNG_CHECK_CAPACITIVE_SENSORS_MINUTE_TOUCHED
#define LNG_CHECK_PUSH_BUTTON_BRIGHTNESS_TOUCHED LNG_CHECK_CAPACITIVE_SENSORS_BRIGHTNESS_TOUCHED
#define LNG_CHECK_PUSH_BUTTON_MODE_TOUCHED LNG_CHECK_CAPACITIVE_SENSORS_MODE_TOUCHED
#define LNG_CHECK_PUSH_BUTTON_PLUS_TOUCHED LNG_CHECK_CAPACITIVE_SENSORS_PLUS_TOUCHED
#define LNG_CHECK_PUSH_BUTTON_MINUS_TOUCHED LNG_CHECK_CAPACITIVE_SENSORS_MINUS_TOUCHED

//check_i2c_display()
#define LNG_CHECK_I2C_DISPLAY_MODE "Mode:"
#define LNG_CHECK_I2C_DISPLAY_PALETTE " Palette:"
#define LNG_CHECK_I2C_DISPLAY_BRIGHTNESS "Bright.:"
#define LNG_CHECK_I2C_DISPLAY_FADEDELAY " Fd:"

//next_pallette()
#define LNG_NEXT_PALLETTE_TITLE LNG_SETTINGS_TITLE
#define LNG_NEXT_PALLETTE_PALLETTE "Color-Pallette "
#define LNG_NEXT_PALLETTE_PALLETTE_SELECTED " selected"

//next_mode()
#define LNG_NEXT_MODE_TITLE LNG_SETTINGS_TITLE
#define LNG_NEXT_MODE_MODE_CHANGED_TO "Mode changed to: "

//setup_brightness(boolean incr)
#define LNG_SETUP_BRIGHTNESS_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_BRIGHTNESS_TO "Brightness  "
#define LNG_SETUP_BRIGHTNESS_SET_UP " set up."

//setup_fade_time(boolean direction)
#define LNG_SETUP_FADE_TIME_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_FADE_TIME_SET_UP_TO "fadeDelayTime set to: "
#define LNG_SETUP_FADE_TIME_SET_UP_TO_UNIT "ms"

//evaluate_serial_inputs()
//the following variables represent the serial commands to edit the desired variables.
//therefore they need to be written in small letters
#define LNG_EVALUATE_SERIAL_INPUTS_STATE "status"
#define LNG_EVALUATE_SERIAL_INPUTS_ON "on"
#define LNG_EVALUATE_SERIAL_INPUTS_OFF "off"
#define LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_ON "timeclockon"
#define LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_OFF "timeclockoff"
#define LNG_EVALUATE_SERIAL_INPUTS_COMMANDS "commands"
#define LNG_EVALUATE_SERIAL_INPUTS_MODE "mode"
#define LNG_EVALUATE_SERIAL_INPUTS_FADETIME "fadetime"
#define LNG_EVALUATE_SERIAL_INPUTS_COLOR_PALLETTE "colorpallette"
#define LNG_EVALUATE_SERIAL_INPUTS_HOUR "hour"
#define LNG_EVALUATE_SERIAL_INPUTS_MINUTE "minute"
#define LNG_EVALUATE_SERIAL_INPUTS_SECONDS "second"
#define LNG_EVALUATE_SERIAL_INPUTS_DAY "day"
#define LNG_EVALUATE_SERIAL_INPUTS_MONTH "month"
#define LNG_EVALUATE_SERIAL_INPUTS_YEAR "year"
#define LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_HOUR_ON "timeclockhouron"
#define LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_MINUTE_ON "timeclockminuteon"
#define LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_HOUR_OFF "timeclockhouroff"
#define LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_HOUR_OFF "timeclockminuteoff"

#define LNG_EVALUATE_SERIAL_INPUTS_TITLE LNG_LOAD_EEPROM_DATA_TITLE
#define LNG_EVALUATE_SERIAL_INPUTS_COLOR_PALLETTE_MESSAGE_NAME "Color-Pallette "
#define LNG_EVALUATE_SERIAL_INPUTS_COLOR_PALLETTE_MESSAGE_SELECTED " selected"

//print_actual_state()
#define LNG_PRINT_ACTUAL_STATE_HEADER "===========================Status==========================="
#define LNG_PRINT_ACTUAL_STATE_BRIGHTNESS "Brightness: "
#define LNG_PRINT_ACTUAL_STATE_MODE "Mode: "
#define LNG_PRINT_ACTUAL_STATE_PALLETTE "Palette: "
#define LNG_PRINT_ACTUAL_STATE_FADEDELAYTIME "fadeDelayTime: "
#define LNG_PRINT_ACTUAL_STATE_TIMECLOCK_HOUR_ON "timeclockHourOn: "
#define LNG_PRINT_ACTUAL_STATE_TIMECLOCK_MINUTE_ON "timeclockMinuteOn: "
#define LNG_PRINT_ACTUAL_STATE_TIMECLOCK_HOUR_OFF "timeclockHourOff: "
#define LNG_PRINT_ACTUAL_STATE_TIMECLOCK_MINUTE_OFF "timeclockMinuteOff: "
#define LNG_PRINT_ACTUAL_STATE_TIMECLOCK_ENABLED "timeclockEnabled: "
#define LNG_PRINT_ACTUAL_STATE_FOOTER "============================================================"

//print_command_list()
#define LNG_PRINT_COMMAND_LIST_FOLLOWING_COMMANDS_POSSIBLE "Following Commands are possible:"
#define LNG_PRINT_COMMAND_LIST_COMMANDS "  \"commands\"=displays this command overview"
#define LNG_PRINT_COMMAND_LIST_STATE "  \"state\"=returns the current status"
#define LNG_PRINT_COMMAND_LIST_ON "  \"on\"=turns on the display"
#define LNG_PRINT_COMMAND_LIST_OFF "  \"off\"=turns off the display"
#define LNG_PRINT_COMMAND_LIST_MODE "  \"mode\"=sets the passed mode"
#define LNG_PRINT_COMMAND_LIST_COLOR_PALLETTE "  \"colorpallette\"=sets the color palette to be displayed"
#define LNG_PRINT_COMMAND_LIST_FADE_TIME "  \"fadetime\"=sets the time (in ms) to wait in color-changing mode before setting the next color"
#define LNG_PRINT_COMMAND_LIST_HOUR "  \"hour\"=sets the hour of the time"
#define LNG_PRINT_COMMAND_LIST_MINUTE "  \"minute\"=sets the minute of the time"
#define LNG_PRINT_COMMAND_LIST_SECONDS "  \"second\"=sets the second of the time"
#define LNG_PRINT_COMMAND_LIST_DAY "  \"day\"=sets the day of the date"
#define LNG_PRINT_COMMAND_LIST_MONTH "  \"month\"=sets the month of the date"
#define LNG_PRINT_COMMAND_LIST_YEAR "  \"year\"=sets the year of the date"
#define LNG_PRINT_COMMAND_LIST_TIMECLOCK_ON "  \"timeclockon\"=turns on the timeclock"
#define LNG_PRINT_COMMAND_LIST_TIMECLOCK_OFF "  \"timeclockoff\"=turns off the timeclock"
#define LNG_PRINT_COMMAND_LIST_TIMECLOCK_HOUR_ON "  \"timeclockhouron\"=sets the hour of the timeclock at which the display should switch on"
#define LNG_PRINT_COMMAND_LIST_TIMECLOCK_MINUTE_ON "  \"timeclockminuteon\"=sets the minute of the timeclock at which the display should switch on"
#define LNG_PRINT_COMMAND_LIST_TIMECLOCK_HOUR_OFF "  \"timeclockhouroff\"=sets the hour of the timeclock at which the display should switch off"
#define LNG_PRINT_COMMAND_LIST_TIMECLOCK_MINUTE_OFF "  \"timeclockminuteoff\"=sets the minute of the timeclock at which the display should switch off"

//print_to_log(String section, String textToPrint, boolean withLineBreak)
#define LNG_PRINT_TO_LOG_RUNTIME "Runtime: "

//print_value_out_of_bounds_message()
#define LNG_PRINT_VALUE_OUT_OF_BOUNDS_MESSAGE_MESSAGE "Value outside the permitted value-range"

//print_serial_command_not_found_message()
#define LNG_PRINT_SERIAL_COMMAND_NOT_FOUND_MESSAGE_1 "The command \""
#define LNG_PRINT_SERIAL_COMMAND_NOT_FOUND_MESSAGE_2 "\" was not recognized"

//show_time_on_led_display(byte hours, byte minutes)
#define LNG_SHOW_TIME_ON_LED_DISPLAY_TITLE "Time of day"
#define LNG_SHOW_TIME_ON_LED_DISPLAY_MESSAGE "Time display is updated."

//runtime_formatted()
#define LNG_RUNTIME_FORMATTED_DAYS " Days, "
#define LNG_RUNTIME_FORMATTED_HOUR_UNIT "h, "
#define LNG_RUNTIME_FORMATTED_MINUTE_UNIT "m, "
#define LNG_RUNTIME_FORMATTED_SECONDS_UNIT "s, "
#define LNG_RUNTIME_FORMATTED_MILLISECONDS_UNIT "ms"

//print_time_to_serial_output()
#define LNG_PRINT_TIME_TO_SERIAL_OUTPUT_TITLE LNG_SHOW_TIME_ON_LED_DISPLAY_TITLE
#define LNG_PRINT_TIME_TO_SERIAL_OUTPUT_ACTUAL_MODE "Actual Mode: "

//setup_absolute_clock_time(uint8_t secondLocal, uint8_t minuteLocal, uint8_t hourLocal, uint8_t dayLocal, uint8_t monthLocal, uint16_t yearLocal)
#define LNG_SETUP_ABSOLUTE_CLOCK_TIME_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_ABSOLUTE_CLOCK_TIME_SUCCESS_MESSAGE "Following time has been set: "

//setup_clock_time_hour(boolean increase)
#define LNG_SETUP_CLOCK_TIME_HOUR_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_CLOCK_TIME_HOUR_SUCCESS_MESSAGE "Hour has been set"

//setup_clock_time_minute(boolean increase)
#define LNG_SETUP_CLOCK_TIME_MINUTE_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_CLOCK_TIME_MINUTE_SUCCESS_MESSAGE "Minute has been set"

//setup_clock_time_year(boolean increase)
#define LNG_SETUP_CLOCK_TIME_YEAR_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_CLOCK_TIME_YEAR_SUCCESS_MESSAGE "Year has been set"

//setup_clock_time_month(boolean increase)
#define LNG_SETUP_CLOCK_TIME_MONTH_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_CLOCK_TIME_MONTH_SUCCESS_MESSAGE "Month has been set"

//setup_clock_time_day(boolean increase)
#define LNG_SETUP_CLOCK_TIME_DAY LNG_SETTINGS_TITLE
#define LNG_SETUP_CLOCK_TIME_DAY_SUCCESS_MESSAGE "Day has been set"

//setup_switch_on_time(uint8_t hourLocal, uint8_t minuteLocal)
#define LNG_SETUP_SWITCH_ON_TIME_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_SWITCH_ON_TIME_SETUP_TO_MESSAGE "The switch-on time of the timeclock has been set to: "

//setup_switch_off_time(uint8_t hourLocal, uint8_t minuteLocal)
#define LNG_SETUP_SWITCH_OFF_TIME_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_SWITCH_OFF_TIME_SETUP_TO_MESSAGE "The switch-off time of the timeclock has been set to: "

//switch_on_timeclock()
#define LNG_SWITCH_ON_TIMECLOCK_TITLE LNG_SETTINGS_TITLE
#define LNG_SWITCH_ON_TIMECLOCK_SUCCESS_MESSAGE "The timeclock has been activated"

//switch_off_timeclock()
#define LNG_SWITCH_OFF_TIMECLOCK_TITLE LNG_SETTINGS_TITLE
#define LNG_SWITCH_OFF_TIMECLOCK_SUCCESS_MESSAGE "The timeclock has been deactivated"

#endif  // _LANGUAGE_DE_DE_H_
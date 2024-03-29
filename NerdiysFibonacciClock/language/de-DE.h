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

// == Localization-file for FibonacciClock - German ===========================================================================================================


#ifndef _LANGUAGE_DE_
#define _LANGUAGE_DE_

/*************************** ATTENTION *******************************\
 *
 * To save code space keep text as short as possible.
 *
\*********************************************************************/

#define LNG_SETTINGS_TITLE "Einstellungen"

//load_eeprom_data()
#define LNG_LOAD_EEPROM_DATA_TITLE LNG_SETTINGS_TITLE
#define LNG_LOAD_EEPROM_DATA_LOADED "-im EEPROM gespeicherte Werte werden geladen..."
#define LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_TITLE "Folgende werte wurden geladen:"
#define LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_BRIGHTNESS "Helligkeit: "
#define LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_MODE "Modus: "
#define LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_PALETTE "Farbpalette: "
#define LNF_LOAD_EEPROM_DATA_FOLLOWING_DATA_LOADED_F_DELAY_TIME "FadeDelayZeit: "

#define LNG_LOAD_EEPROM_DATA_TIMECLOCK_HOUR_ON "Zeitschaltuhr schaltet ein um: "
#define LNG_LOAD_EEPROM_DATA_TIMECLOCK_HOUR_OFF "Zeitschaltuhr schaltet aus um: "
#define LNG_LOAD_EEPROM_DATA_TIMECLOCK_ACTIVATED "Zeitschaltuhr eingeschaltet: "

//save_values_in_eeprom()
#define LNG_SAVE_EEPROM_DATA_TITLE LNG_SETTINGS_TITLE
#define LNG_SAVE_EEPROM_DATA_MESSAGE "Eventuell geänderte Werte wurden gespeichert."

//check_capacitive_sensors()
#define LNG_CHECK_CAPACITIVE_SENSORS_TITLE "Tasten"
#define LNG_CHECK_CAPACITIVE_SENSORS_HOUR_RELEASED "Taste \"Stunde\" wurde losgelassen"
#define LNG_CHECK_CAPACITIVE_SENSORS_MINUTE_RELEASED "Taste \"Minute\" wurde losgelassen"
#define LNG_CHECK_CAPACITIVE_SENSORS_BRIGHTNESS_RELEASED "Taste \"Helligkeit\" wurde losgelassen"
#define LNG_CHECK_CAPACITIVE_SENSORS_MODE_RELEASED "Taste \"Mode\" wurde losgelassen"
#define LNG_CHECK_CAPACITIVE_SENSORS_PLUS_RELEASED "Taste \"Plus\" wurde losgelassen"
#define LNG_CHECK_CAPACITIVE_SENSORS_MINUS_RELEASED "Taste \"Minus\" wurde losgelassen"
#define LNG_CHECK_CAPACITIVE_SENSORS_HOUR_TOUCHED "Taste \"Stunde\" wurde berührt"
#define LNG_CHECK_CAPACITIVE_SENSORS_MINUTE_TOUCHED "Taste \"Minute\" wurde berührt"
#define LNG_CHECK_CAPACITIVE_SENSORS_BRIGHTNESS_TOUCHED "Taste \"Helligkeit\" wurde berührt"
#define LNG_CHECK_CAPACITIVE_SENSORS_MODE_TOUCHED "Taste \"Mode\" wurde berührt"
#define LNG_CHECK_CAPACITIVE_SENSORS_PLUS_TOUCHED "Taste \"Plus\" wurde berührt"
#define LNG_CHECK_CAPACITIVE_SENSORS_MINUS_TOUCHED "Taste \"Minus\" wurde berührt"



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
#define LNG_CHECK_I2C_DISPLAY_BRIGHTNESS "Hellig.:"
#define LNG_CHECK_I2C_DISPLAY_FADEDELAY " Fd:"

//next_pallette()
#define LNG_NEXT_PALLETTE_TITLE LNG_SETTINGS_TITLE
#define LNG_NEXT_PALLETTE_PALLETTE "Farbpalette "
#define LNG_NEXT_PALLETTE_PALLETTE_SELECTED " ausgewaehlt."

//next_mode()
#define LNG_NEXT_MODE_TITLE LNG_SETTINGS_TITLE
#define LNG_NEXT_MODE_MODE_CHANGED_TO "Mode gewechselt auf: "

//setup_brightness(boolean incr)
#define LNG_SETUP_BRIGHTNESS_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_BRIGHTNESS_TO "Helligkeit auf "
#define LNG_SETUP_BRIGHTNESS_SET_UP " eingestellt."

//setup_fade_time(boolean direction)
#define LNG_SETUP_FADE_TIME_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_FADE_TIME_SET_UP_TO "fadeDelayTime eingestellt auf: "
#define LNG_SETUP_FADE_TIME_SET_UP_TO_UNIT "ms"

//evaluate_serial_inputs()
//the following variables represent the serial commands to edit the desired variables.
//therefore they need to be written in small letters
#define LNG_EVALUATE_SERIAL_INPUTS_STATE "status"
#define LNG_EVALUATE_SERIAL_INPUTS_ON "ein"
#define LNG_EVALUATE_SERIAL_INPUTS_OFF "aus"
#define LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_ON "zeitschaltuhrein"
#define LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_OFF "zeitschaltuhraus"
#define LNG_EVALUATE_SERIAL_INPUTS_COMMANDS "befehle"
#define LNG_EVALUATE_SERIAL_INPUTS_MODE "modus"
#define LNG_EVALUATE_SERIAL_INPUTS_FADETIME "fadezeit"
#define LNG_EVALUATE_SERIAL_INPUTS_COLOR_PALLETTE "farbpalette"
#define LNG_EVALUATE_SERIAL_INPUTS_HOUR "stunde"
#define LNG_EVALUATE_SERIAL_INPUTS_MINUTE "minute"
#define LNG_EVALUATE_SERIAL_INPUTS_SECONDS "sekunde"
#define LNG_EVALUATE_SERIAL_INPUTS_DAY "tag"
#define LNG_EVALUATE_SERIAL_INPUTS_MONTH "monat"
#define LNG_EVALUATE_SERIAL_INPUTS_YEAR "jahr"
#define LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_HOUR_ON "stundezeitschaltuhrein"
#define LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_MINUTE_ON "minutezeitschaltuhrein"
#define LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_HOUR_OFF "stundezeitschaltuhraus"
#define LNG_EVALUATE_SERIAL_INPUTS_TIMECLOCK_HOUR_OFF "minutezeitschaltuhraus"

#define LNG_EVALUATE_SERIAL_INPUTS_TITLE LNG_LOAD_EEPROM_DATA_TITLE
#define LNG_EVALUATE_SERIAL_INPUTS_COLOR_PALLETTE_MESSAGE_NAME "FarbPalette "
#define LNG_EVALUATE_SERIAL_INPUTS_COLOR_PALLETTE_MESSAGE_SELECTED " ausgewaehlt."

//print_actual_state()
#define LNG_PRINT_ACTUAL_STATE_HEADER "===========================Status==========================="
#define LNG_PRINT_ACTUAL_STATE_BRIGHTNESS "Helligkeit: "
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
#define LNG_PRINT_COMMAND_LIST_FOLLOWING_COMMANDS_POSSIBLE "Folgende Befehle sind moeglich:"
#define LNG_PRINT_COMMAND_LIST_COMMANDS "  \"befehle\"=zeigt diese BefehlsUebersicht an."
#define LNG_PRINT_COMMAND_LIST_STATE "  \"status\"=gibt den aktuellen Status aus."
#define LNG_PRINT_COMMAND_LIST_ON "  \"ein\"=schaltet die Anzeige ein."
#define LNG_PRINT_COMMAND_LIST_OFF "  \"aus\"=schaltet die Anzeige aus."
#define LNG_PRINT_COMMAND_LIST_MODE "  \"modus\"=stellt den übergebenen Status ein. [0-2]. Beispiel: modus=0"
#define LNG_PRINT_COMMAND_LIST_COLOR_PALLETTE "  \"farbPalette\"=stellt die anzuzeigende Farbpalette ein. [0-10]. Beispiel: farbPalette=1"
#define LNG_PRINT_COMMAND_LIST_FADE_TIME "  \"fadeZeit\"=stellt die Zeit(in ms) ein die im Farbwechselmodus vorm einstellen der nächsten Farbe gewartet wird. [10-20000]. Beispiel fadeZeit=500"
#define LNG_PRINT_COMMAND_LIST_HOUR "  \"stunde\"=stellt die Stunde der Uhrzeit ein. [0-23]. Beispiel: stunde=1"
#define LNG_PRINT_COMMAND_LIST_MINUTE "  \"minute\"=stellt die Minute der Uhrzeit ein. [0-59]. Beispiel: minute=1"
#define LNG_PRINT_COMMAND_LIST_SECONDS "  \"sekunde\"=stellt die Sekunde der Uhrzeit ein. [0-59]. Beispiel: sekunde=1"
#define LNG_PRINT_COMMAND_LIST_DAY "  \"tag\"=stellt den Tag ein. [1-31]. Beispiel: tag=1"
#define LNG_PRINT_COMMAND_LIST_MONTH "  \"monat\"=stellt den Monatein. [1-12]. Beispiel: monat=1"
#define LNG_PRINT_COMMAND_LIST_YEAR "  \"jahr\"=stellt das Jahr ein. [2000-2070]. Beispiel: jahr=2017"
#define LNG_PRINT_COMMAND_LIST_TIMECLOCK_ON "  \"zeitschaltuhrEin\"=schaltet die Zeitschaltuhr ein."
#define LNG_PRINT_COMMAND_LIST_TIMECLOCK_OFF "  \"zeitschaltuhrAus\"=schaltet die Zeitschaltuhr aus."
#define LNG_PRINT_COMMAND_LIST_TIMECLOCK_HOUR_ON "  \"stundeZeitschaltuhrEin\"=stellt die Stunde der Uhrzeit ein zu der die Anzeige eingeschaltet werden soll. [0-23]. Beispiel: stundeZeitschaltuhrEin=1"
#define LNG_PRINT_COMMAND_LIST_TIMECLOCK_MINUTE_ON "  \"minuteZeitschaltuhrEin\"=stellt die Minute der Uhrzeit ein zu der die Anzeige eingeschaltet werden soll. [1-60]. Beispiel: minuteZeitschaltuhrEin=1"
#define LNG_PRINT_COMMAND_LIST_TIMECLOCK_HOUR_OFF "  \"stundeZeitschaltuhrAus\"=stellt die Stunde der Uhrzeit ein zu der die Anzeige ausgeschaltet werden soll. [0-23]. Beispiel: stundeZeitschaltuhrAus=1"
#define LNG_PRINT_COMMAND_LIST_TIMECLOCK_MINUTE_OFF "  \"minuteZeitschaltuhrAus\"=stellt die Minute der Uhrzeit ein zu der die Anzeige ausgeschaltet werden soll. [1-60]. Beispiel: minuteZeitschaltuhrAus=1"

//print_to_log(String section, String textToPrint, boolean withLineBreak)
#define LNG_PRINT_TO_LOG_RUNTIME "Laufzeit: "

//print_value_out_of_bounds_message()
#define LNG_PRINT_VALUE_OUT_OF_BOUNDS_MESSAGE_MESSAGE "Wert ausserhalb des erlaubten Wertebereichs."

//print_serial_command_not_found_message()
#define LNG_PRINT_SERIAL_COMMAND_NOT_FOUND_MESSAGE_1 "Der Befehl \""
#define LNG_PRINT_SERIAL_COMMAND_NOT_FOUND_MESSAGE_2 "\" wurde nicht erkannt."

//show_time_on_led_display(byte hours, byte minutes)
#define LNG_SHOW_TIME_ON_LED_DISPLAY_TITLE "Uhrzeit"
#define LNG_SHOW_TIME_ON_LED_DISPLAY_MESSAGE "Uhrzeitanzeige wird aktualisiert."

//runtime_formatted()
#define LNG_RUNTIME_FORMATTED_DAYS " Tage, "
#define LNG_RUNTIME_FORMATTED_HOUR_UNIT "h, "
#define LNG_RUNTIME_FORMATTED_MINUTE_UNIT "m, "
#define LNG_RUNTIME_FORMATTED_SECONDS_UNIT "s, "
#define LNG_RUNTIME_FORMATTED_MILLISECONDS_UNIT "ms"

//print_time_to_serial_output()
#define LNG_PRINT_TIME_TO_SERIAL_OUTPUT_TITLE LNG_SHOW_TIME_ON_LED_DISPLAY_TITLE
#define LNG_PRINT_TIME_TO_SERIAL_OUTPUT_ACTUAL_MODE "Aktueller Modus: "

//setup_absolute_clock_time(uint8_t secondLocal, uint8_t minuteLocal, uint8_t hourLocal, uint8_t dayLocal, uint8_t monthLocal, uint16_t yearLocal)
#define LNG_SETUP_ABSOLUTE_CLOCK_TIME_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_ABSOLUTE_CLOCK_TIME_SUCCESS_MESSAGE "Folgende Uhrzeit wurde eingestellt: "

//setup_clock_time_hour(boolean increase)
#define LNG_SETUP_CLOCK_TIME_HOUR_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_CLOCK_TIME_HOUR_SUCCESS_MESSAGE "Stunde wurde eingestellt."

//setup_clock_time_minute(boolean increase)
#define LNG_SETUP_CLOCK_TIME_MINUTE_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_CLOCK_TIME_MINUTE_SUCCESS_MESSAGE "Minute wurde eingestellt."

//setup_clock_time_year(boolean increase)
#define LNG_SETUP_CLOCK_TIME_YEAR_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_CLOCK_TIME_YEAR_SUCCESS_MESSAGE "Jahr wurde eingestellt."

//setup_clock_time_month(boolean increase)
#define LNG_SETUP_CLOCK_TIME_MONTH_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_CLOCK_TIME_MONTH_SUCCESS_MESSAGE "Monat wurde eingestellt."

//setup_clock_time_day(boolean increase)
#define LNG_SETUP_CLOCK_TIME_DAY LNG_SETTINGS_TITLE
#define LNG_SETUP_CLOCK_TIME_DAY_SUCCESS_MESSAGE "Tag wurde eingestellt."

//setup_switch_on_time(uint8_t hourLocal, uint8_t minuteLocal)
#define LNG_SETUP_SWITCH_ON_TIME_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_SWITCH_ON_TIME_SETUP_TO_MESSAGE "Die EinschaltZeit der Zeitschaltuhr wurde eingestellt auf: "

//setup_switch_off_time(uint8_t hourLocal, uint8_t minuteLocal)
#define LNG_SETUP_SWITCH_OFF_TIME_TITLE LNG_SETTINGS_TITLE
#define LNG_SETUP_SWITCH_OFF_TIME_SETUP_TO_MESSAGE "Die AusschaltZeit der Zeitschaltuhr wurde eingestellt auf: "

//switch_on_timeclock()
#define LNG_SWITCH_ON_TIMECLOCK_TITLE LNG_SETTINGS_TITLE
#define LNG_SWITCH_ON_TIMECLOCK_SUCCESS_MESSAGE "Die Zeitschaltuhr wurde eingeschaltet."

//switch_off_timeclock()
#define LNG_SWITCH_OFF_TIMECLOCK_TITLE LNG_SETTINGS_TITLE
#define LNG_SWITCH_OFF_TIMECLOCK_SUCCESS_MESSAGE "Die Zeitschaltuhr wurde ausgeschaltet."

#endif  // _LANGUAGE_DE_DE_H_
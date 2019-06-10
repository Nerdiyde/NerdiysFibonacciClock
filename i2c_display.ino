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
// == I2C Display ===========================================================================================================================================


#ifdef I2C_DISPLAY_INSTALLED
void init_i2c_display()
{
  //initializes the additional i2c-display with the desired settings
  display.begin(SSD1306_SWITCHCAPVCC, DISPLAY_I2C_ADRESS);  // initialize with the I2C addr 0x3C (for the 128x32)

  display.setRotation(DISPLAY_ROTATION);

  button_pressed(); //to make the display content visible for the duration defined in DISPLAY_ON_TIMER_DURATION
  check_i2c_display(); //update the display content
}


void check_i2c_display()
{
  //updates the display content if any button(or capacitive sensor got pressed) DISPLAY_ON_TIMER_DURATION ago
  lastDisplayUpdate = millis();
  if ((millis() - lastButtonPressedTimestamp) >= DISPLAY_ON_TIMER_DURATION)
  {
    display.clearDisplay();
    display.display();
  } else
  {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print("Fiboclock V");
    display.println(VERSION);
    display.println(timeofday_plus_seconds_and_date_formatted());
    display.print(LNG_CHECK_I2C_DISPLAY_MODE);
    display.print(mode);
    display.print(LNG_CHECK_I2C_DISPLAY_PALETTE);
    display.println(palette + 1);
    display.print(LNG_CHECK_I2C_DISPLAY_BRIGHTNESS);
    if (isnan(brightnessDesired))
    {
      display.print("error");
    } else
    {
      display.print(brightness);
    }
    display.print(LNG_CHECK_I2C_DISPLAY_FADEDELAY);
    display.println(fadeDelayTime);
    display.display();
  }
}

void button_pressed()
{
  //saves the actual timestamp when a button got pressed
  lastButtonPressedTimestamp = millis();
}

#endif

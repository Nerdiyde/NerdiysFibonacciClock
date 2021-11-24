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
// == Led Display ==========================================================================================================================================


void init_led_strip()
{
  // Initialize the strip and set all pixels to 'off'
  strip.begin();
  strip.show();
}

void setBits(byte value, byte offset)
{
  switch (value)
  {
    case 1:
      switch (random(2))
      {
        case 0:
          bits[0] |= offset;
          break;
        case 1:
          bits[1] |= offset;
          break;
      }
      break;
    case 2:
      switch (random(2))
      {
        case 0:
          bits[2] |= offset;
          break;
        case 1:
          bits[0] |= offset;
          bits[1] |= offset;
          break;
      }
      break;
    case 3:
      switch (random(3))
      {
        case 0:
          bits[3] |= offset;
          break;
        case 1:
          bits[0] |= offset;
          bits[2] |= offset;
          break;
        case 2:
          bits[1] |= offset;
          bits[2] |= offset;
          break;
      }
      break;
    case 4:
      switch (random(3))
      {
        case 0:
          bits[0] |= offset;
          bits[3] |= offset;
          break;
        case 1:
          bits[1] |= offset;
          bits[3] |= offset;
          break;
        case 2:
          bits[0] |= offset;
          bits[1] |= offset;
          bits[2] |= offset;
          break;
      }
      break;
    case 5:
      switch (random(3))
      {
        case 0:
          bits[4] |= offset;
          break;
        case 1:
          bits[2] |= offset;
          bits[3] |= offset;
          break;
        case 2:
          bits[0] |= offset;
          bits[1] |= offset;
          bits[3] |= offset;
          break;
      }
      break;
    case 6:
      switch (random(4))
      {
        case 0:
          bits[0] |= offset;
          bits[4] |= offset;
          break;
        case 1:
          bits[1] |= offset;
          bits[4] |= offset;
          break;
        case 2:
          bits[0] |= offset;
          bits[2] |= offset;
          bits[3] |= offset;
          break;
        case 3:
          bits[1] |= offset;
          bits[2] |= offset;
          bits[3] |= offset;
          break;
      }
      break;
    case 7:
      switch (random(3))
      {
        case 0:
          bits[2] |= offset;
          bits[4] |= offset;
          break;
        case 1:
          bits[0] |= offset;
          bits[1] |= offset;
          bits[4] |= offset;
          break;
        case 2:
          bits[0] |= offset;
          bits[1] |= offset;
          bits[2] |= offset;
          bits[3] |= offset;
          break;
      }
      break;
    case 8:
      switch (random(3))
      {
        case 0:
          bits[3] |= offset;
          bits[4] |= offset;
          break;
        case 1:
          bits[0] |= offset;
          bits[2] |= offset;
          bits[4] |= offset;
          break;
        case 2:
          bits[1] |= offset;
          bits[2] |= offset;
          bits[4] |= offset;
          break;
      }
      break;
    case 9:
      switch (random(2))
      {
        case 0:
          bits[0] |= offset;
          bits[3] |= offset;
          bits[4] |= offset;
          break;
        case 1:
          bits[1] |= offset;
          bits[3] |= offset;
          bits[4] |= offset;
          break;
      }
      break;
    case 10:
      switch (random(2))
      {
        case 0:
          bits[2] |= offset;
          bits[3] |= offset;
          bits[4] |= offset;
          break;
        case 1:
          bits[0] |= offset;
          bits[1] |= offset;
          bits[3] |= offset;
          bits[4] |= offset;
          break;
      }
      break;
    case 11:
      switch (random(2))
      {
        case 0:
          bits[0] |= offset;
          bits[2] |= offset;
          bits[3] |= offset;
          bits[4] |= offset;
          break;
        case 1:
          bits[1] |= offset;
          bits[2] |= offset;
          bits[3] |= offset;
          bits[4] |= offset;
          break;
      }

      break;
    case 12:
      bits[0] |= offset;
      bits[1] |= offset;
      bits[2] |= offset;
      bits[3] |= offset;
      bits[4] |= offset;

      break;
  }
}

void set_fibonacci_pixel(byte pixel, uint32_t color)
{
  //sets the desired led-area(that represents one of the fibonacci numbers) with the desired color
  if (!on)
    return;

  switch (pixel)
  {
    case 0:
      set_fibo_pixel_with_value_1_0(color);
      break;
    case 1:
      set_fibo_pixel_with_value_1_1(color);
      break;
    case 2:
      set_fibo_pixel_with_value_2(color);
      break;
    case 3:
      set_fibo_pixel_with_value_3(color);
      break;
    case 4:
      set_fibo_pixel_with_value_5(color);
      break;
  };
}

void set_fibo_pixel_with_value_1_0(uint32_t color)
{
  //sets the first led-area that represents the fibonacci number 1 to the desired color
  strip.setPixelColor(0, color);
  //Papas Uhr:
  //strip.setPixelColor(3,color);
}
void set_fibo_pixel_with_value_1_1(uint32_t color)
{
  //sets the second led-area that represents the fibonacci number 1 to the desired color
  strip.setPixelColor(1, color);
  //Papas Uhr:
  //strip.setPixelColor(4,color);
}

void set_fibo_pixel_with_value_2(uint32_t color)
{
  //sets the led-area that represents the fibonacci number 2 to the desired color
  strip.setPixelColor(2, color);
}

void set_fibo_pixel_with_value_3(uint32_t color)
{
  //sets the led-area that represents the fibonacci number 3 to the desired color
  strip.setPixelColor(3, color);
  strip.setPixelColor(4, color);
  //Papas Uhr:
  //strip.setPixelColor(0,color);
  //strip.setPixelColor(1,color);
}

void set_fibo_pixel_with_value_5(uint32_t color)
{
  //sets the led-area that represents the fibonacci number 5 to the desired color
  strip.setPixelColor(5, color);
  strip.setPixelColor(6, color);
  strip.setPixelColor(7, color);
  strip.setPixelColor(8, color);
}

uint32_t colorWheel(byte wheelPos)
{
  //Takes the input value whelPos and uses it as the degree on a colorWheel. Then uses the associated colors and returns them.
  if (wheelPos < 85)
  {
    return strip.Color(wheelPos * 3, 255 - wheelPos * 3, 0);
  }
  else if (wheelPos < 170)
  {
    wheelPos -= 85;
    return strip.Color(255 - wheelPos * 3, 0, wheelPos * 3);
  }
  else
  {
    wheelPos -= 170;
    return strip.Color(0, wheelPos * 3, 255 - wheelPos * 3);
  }
}

void rainbow_transistion_on_all_led_areas_shifted(uint8_t wait, uint8_t colorOffset)
{
  //calculates(and shows) a rainbow-color transition on the led-areas. The color of each led-area is different.(Shiftet on the color wheel by "colorOffset")
  //So: It is possible to manipulate the difference between two colors by manipulate the value of COLOR_OFFSET_BETWEEN_TWO_LED_AREAS_IN_RAINBOW_MODE
  if (regular_execution(&rainbowTransitionLastExecutionGlobal, wait))
  {
    if (rainbowTransitionPositionGlobal == 255)
    {
      rainbowTransitionPositionGlobal = 0;
    } else
      rainbowTransitionPositionGlobal++;
    set_fibonacci_pixel(0, colorWheel(rainbowTransitionPositionGlobal));
    set_fibonacci_pixel(1, colorWheel((uint8_t)(rainbowTransitionPositionGlobal + colorOffset)));
    set_fibonacci_pixel(2, colorWheel((uint8_t)(rainbowTransitionPositionGlobal + (colorOffset * 2))));
    set_fibonacci_pixel(3, colorWheel((uint8_t)(rainbowTransitionPositionGlobal + (colorOffset * 3))));
    set_fibonacci_pixel(4, colorWheel((uint8_t)(rainbowTransitionPositionGlobal + (colorOffset * 4))));
    strip.show();
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbow_transistion_on_all_led_areas_equally(uint8_t wait)
{
  //calculates(and shows) a rainbow-color transition on all led-areas at the same time.(All led-areas glow in the same color.)
  if (regular_execution(&rainbowTransitionLastExecutionGlobal, wait))
  {
    if (rainbowTransitionPositionGlobal == 255)
    {
      rainbowTransitionPositionGlobal = 0;
    } else
      rainbowTransitionPositionGlobal++;
    set_all_fibonacci_pixel(colorWheel(rainbowTransitionPositionGlobal));
  }
}

void update_led_display()
{
  //updates the led display in depence of the actual mode
  if (on)
    switch (mode)
    {
      case 0:
        show_time_on_led_display(hourFormat12(), minute());
        break;

      case 1:
        oldHours = 99;
        rainbow_transistion_on_all_led_areas_equally(fadeDelayTime);
        break;

      case 2:
        oldHours = 99;
        rainbow_transistion_on_all_led_areas_shifted(fadeDelayTime, COLOR_OFFSET_BETWEEN_TWO_LED_AREAS_IN_RAINBOW_MODE);
        break;
    }
}

void set_all_fibonacci_pixel(uint32_t color)
{
  //sets all led-areas to the same color defined in "color"
  for (uint16_t i = 0; i < CLOCK_PIXELS; i++)
  {
    set_fibonacci_pixel(i, color);
  }
  strip.show();
}

#ifdef LDR_INSTALLED
void init_ldr()
{
  //init ldr sensor
  analogReference(EXTERNAL);
  pinMode(LDR_PIN, INPUT);
}

void check_brightness()
{
  //read brightness from ldr and calculate brightness for led display
  
  uint16_t brightnessAdcLocal = analogRead(LDR_PIN);

  //actual value will be saved in the highest place of the movingAverageValues-Array
  movingAverageValues[movingAverageIndex] = brightnessAdcLocal;

  //following part will only be executed if all slots of movingAverageValues are filled
  if (movingAverageValues[MOVING_AVERAGE_VALUE_SAMPLES - 1] != 0 )
  {
    //add up all moving average values and calculate average
    uint16_t movingAverageTotalSum = 0;
    for (uint8_t i = 0; i < MOVING_AVERAGE_VALUE_SAMPLES; i++)
    {
      movingAverageTotalSum += movingAverageValues[i];
    }
    movingAverage = movingAverageTotalSum / MOVING_AVERAGE_VALUE_SAMPLES;
  }

  //increment or reset movingAverageIndex
  if (movingAverageIndex <= (MOVING_AVERAGE_VALUE_SAMPLES - 1))
  {
    movingAverageIndex++;
  } else
  {
    movingAverageIndex = 0;
  }

  //following part will only be executed if all slots of movingAverageValues are filled
  if (movingAverageValues[MOVING_AVERAGE_VALUE_SAMPLES - 1] != 0)
  {
    //save the actual movinAverage-Value if its bigger then movingAverageBiggest
    if (movingAverageBiggest < movingAverage)
      movingAverageBiggest = movingAverage;

    //save the actual movinAverage-Value if its smaller then movingAverageSmallest
    if (movingAverageSmallest > movingAverage)
      movingAverageSmallest = movingAverage;

    //map the actual brightness to the brightest and darkest brightness
    float brightnessCalculated = (float)((float)(movingAverage - movingAverageSmallest) / (float)(movingAverageBiggest - movingAverageSmallest));

    //limit the brightness to lower limit=the smallest brightness value is limited by desired brightness
    if (brightnessCalculated < brightnessDesired)
      brightnessCalculated = brightnessDesired;

    //output calculated brigthness to the brightness-variable that will be used for display brightness
    brightness = brightnessCalculated;
  }
}

#else
void check_brightness()
{
  brightness = brightnessDesired;
}
#endif

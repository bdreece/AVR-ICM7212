/**
 * main.cpp - Main demo application for the ICM7212(AM) driver
 *
 * @author Brian Reece
 * @date 09/15/2021
 */

#define F_CPU 1000000UL

#include <stdint.h>
#include <stdio.h>

#include <avr/io.h>
#include <util/delay.h>

#include "ICM7212AM.hpp"

int main()
{
  icm7212::ICM7212AM display(&PORTB, icm7212::DIGIT_HIGH);

  uint32_t val = 0;
  char buf[5];

  while (1)
  {
    if (val % 9999 == 0)
      val = 0;

    snprintf(buf, 4, "%4ld", val);
    display.write(buf);

    val++;

    _delay_ms(500);
  }

  return 0;
}

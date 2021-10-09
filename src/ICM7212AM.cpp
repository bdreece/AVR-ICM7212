/**
 * ICM7212AM.cpp - Implementation for the ICM7212AM driver.
 *
 * @author Brian Reece
 * @date 09/15/2021
 */

#ifndef ICM7212AM_H
#include "ICM7212AM.hpp"
#endif

#include <stddef.h>
#include <stdlib.h>
#include <math.h>

using namespace icm7212;

ICM7212AM::ICM7212AM(volatile uint8_t *port, enum ICM7212BitOrder bit_order)
{
  this->port = port;
  DATA_INPUT = bit_order ? 4 : 2;
  DIGIT_SEL = !bit_order ? 6 : 2;
  CHIP_SEL = 0;
}

ICM7212AM::~ICM7212AM()
{
  port = NULL;
}

int8_t ICM7212AM::write(const char *value)
{
  uint8_t i;
  enum ICM7212ACodeB digits[4];

  for (i = 0; i < 4; i++)
  {
    uint8_t d = atoi((const char *)&value[i]);

    if (d < 0 || d > 15)
      return -1;
    else
      digits[i] = (ICM7212ACodeB) d;
  }

  display(digits);
  return 0;
}

void ICM7212AM::clear()
{
  enum ICM7212ACodeB digits[4] = {
    BLANK,
    BLANK,
    BLANK,
    BLANK
  };

  display(digits);
}

void ICM7212AM::display(enum ICM7212ACodeB *digits)
{
  uint8_t i;

  for (i = 0; i < 4; i++)
  {
    *port &= ~(3 << CHIP_SEL);
    *port |= (uint8_t) pow(2, i) << DIGIT_SEL | (uint8_t) digits[i] << DATA_INPUT;
    *port ^= 3 << CHIP_SEL;
  }
}

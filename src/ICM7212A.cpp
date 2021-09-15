/**
 * ICM7212A.cpp - Implementation of the ICM7212A driver.
 *
 * @author Brian Reece
 * @date 09/15/2021
 */

#ifndef ICM7212A_H
#include "ICM7212A.hpp"
#endif

#include <stddef.h>
#include <stdlib.h>
#include <math.h>

using namespace icm7212;

ICM7212A::ICM7212A(volatile uint8_t *port, enum ICM7212BitOrder bit_order)
{
  this->port = port;
  DATA_INPUT = bit_order ? 4 : 0;
  DIGIT_SEL = !bit_order ? 4 : 0;
}

ICM7212A::~ICM7212A()
{
  port = NULL;
}

int8_t ICM7212A::write(const char *value)
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

void ICM7212A::clear()
{
  enum ICM7212ACodeB digits[4] = {
    BLANK,
    BLANK,
    BLANK,
    BLANK
  };

  display(digits);
}

void ICM7212A::display(enum ICM7212ACodeB *digits)
{
  uint8_t i;

  for (i = 0; i < 4; i++)
  {
    *port |= (uint8_t) pow(2, i) << DIGIT_SEL | (uint8_t) digits[i] << DATA_INPUT;
  }
}


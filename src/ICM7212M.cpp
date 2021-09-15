/**
 * ICM7212M.cpp - Implementation for the ICM7212M driver.
 *
 * @author Brian Reece
 * @date 09/15/2021
 */

#ifndef ICM7212M_H
#include "ICM7212M.hpp"
#endif

#include <stddef.h>
#include <math.h>

using namespace icm7212;

ICM7212M::ICM7212M(volatile uint8_t *port, enum ICM7212BitOrder bit_order)
{
  this->port = port;
  DATA_INPUT = bit_order ? 4 : 2;
  DIGIT_SEL = !bit_order ? 6 : 2;
  CHIP_SEL = 0;
}

ICM7212M::~ICM7212M()
{
  port = NULL;
}

void ICM7212M::write(uint16_t value)
{
  uint8_t i;

  for (i = 0; i < 4; i++)
  {
    *port &= ~(3 << CHIP_SEL);
    *port |= (uint8_t) pow(2, i) << DIGIT_SEL | (value % 10) << DATA_INPUT;
    *port ^= 3 << CHIP_SEL;

    value /= 10;
  }
}
/**
 * ICM7212.cpp - Implementation for the base ICM7212 driver
 *
 * @author Brian Reece
 * @date 09/15/2021
 */

#ifndef ICM7212_H
#include "ICM7212.hpp"
#endif

#include <stddef.h>
#include <math.h>

using namespace icm7212;

ICM7212::ICM7212(volatile uint8_t *port, enum ICM7212BitOrder bit_order)
{
  this->port = port;
  this->DATA_INPUT = bit_order ? 4 : 0;
  this->DIGIT_SEL = !bit_order ? 4 : 0; 
}

ICM7212::~ICM7212()
{
  this->port = NULL;
}

void ICM7212::write(uint16_t value)
{
  uint8_t digits[4], i;

  for (i = 0; i < 4; i++)
  {
    digits[i] = value % 10;
    *port |= (uint8_t) pow(2, i) << DIGIT_SEL | digits[i] << DATA_INPUT;
    value /= 10;
  }
}
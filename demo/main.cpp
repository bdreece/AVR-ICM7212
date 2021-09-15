/**
 * main.cpp - Main demo application for the ICM7212(AM) driver
 *
 * @author Brian Reece
 * @date 09/15/2021
 */

#ifndef ICM7212AM_H
#include "ICM7212AM.hpp"
#endif

#include <avr/io.h>

int main()
{
  icm7212::ICM7212AM display(&PORTB, icm7212::DATA_HIGH);

  display.write("0000");

  return 0;
}
/**
 * ICM7212AM.hpp - Header file for the ICM7212AM driver.
 *
 * @author Brian Reece
 * @date 09/15/2021
 */

#ifndef ICM7212AM_H
#define ICM7212AM_H

#ifndef ICM7212_H
#include "ICM7212.hpp"
#endif

#ifndef ICM7212A_H
#include "ICM7212A.hpp"
#endif

namespace icm7212
{
  class ICM7212AM
  {
    public:
      ICM7212AM(volatile uint8_t *, enum ICM7212BitOrder);
      ~ICM7212AM();
      int8_t write(const char *);
      void clear();

    private:
      volatile uint8_t *port;
      uint8_t DATA_INPUT;
      uint8_t DIGIT_SEL;
      uint8_t CHIP_SEL;
      void display(enum ICM7212ACodeB [4]);
  };
}

#endif // ICM7212AM_H
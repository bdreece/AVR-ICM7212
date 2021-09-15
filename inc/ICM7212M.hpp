/**
 * ICM7212M.hpp - Header file for the ICM7212M driver.
 *
 * @author Brian Reece
 * @date 09/15/2021
 */

#ifndef ICM7212M_H
#define ICM7212M_H

#ifndef ICM7212_H
#include "ICM7212.hpp"
#endif

namespace icm7212
{
  class ICM7212M
  {
    public:
      ICM7212M(uint8_t *, enum ICM7212BitOrder);
      ~ICM7212M();
      void write(uint16_t);

    private:
      uint8_t *port;
      uint8_t DATA_INPUT;
      uint8_t DIGIT_SEL;
      uint8_t CHIP_SEL;
  };
}

#endif // ICM7212M_H
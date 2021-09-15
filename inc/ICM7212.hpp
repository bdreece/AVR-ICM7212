/**
 * ICM7212.hpp - Header file for the base ICM7212 driver, as
 * well as macro definitions.
 *
 * @author Brian Reece
 * @date 09/15/2021
 */

#ifndef ICM7212_H
#define ICM7212_H

#include <stdint.h>

namespace icm7212
{
  enum ICM7212BitOrder
  {
    DATA_HIGH = 0,
    DIGIT_HIGH = 1
  };

  class ICM7212
  {
    public:
      ICM7212(uint8_t *port, enum ICM7212BitOrder bit_order);
      ~ICM7212();
      void write(uint16_t value);
    private:
      uint8_t *port;
      uint8_t DATA_INPUT;
      uint8_t DIGIT_SEL;
  };
}

#endif // ICM7212_H
/**
 * ICM7212A.hpp - Header file for the ICM7212A driver.
 *
 * @author Brian Reece
 * @date 09/15/2021
 */

#ifndef ICM7212A_H
#define ICM7212A_H

#ifndef ICM7212_H
#include "ICM7212.hpp"
#endif

namespace icm7212
{
  enum ICM7212ACodeB
  {
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    HYPHEN = 10,
    E = 11,
    H = 12,
    L = 13,
    P = 14,
    BLANK = 15
  };

  class ICM7212A
  {
    public:
      ICM7212A(volatile uint8_t *, enum ICM7212BitOrder);
      ~ICM7212A();
      int8_t write(const char *);
      void clear();

    private:
      volatile uint8_t *port;
      uint8_t DATA_INPUT;
      uint8_t DIGIT_SEL;
      void display(enum ICM7212ACodeB [4]);
  };
}
#endif // ICM7212A_H
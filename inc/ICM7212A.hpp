/*! \brief ICM7212A Driver
 *  Header file for the Maxim Integrated ICM7212A driver.
 *
 *  \author Brian Reece
 *  \date 09/15/2021
 */

#ifndef ICM7212A_H
#define ICM7212A_H

#ifndef ICM7212_H
#include "ICM7212.hpp"
#endif

namespace icm7212
{
  //! Code-B Decoding Enum
  enum ICM7212ACodeB
  {
    ZERO = 0,    //!< 0
    ONE = 1,     //!< 1
    TWO = 2,     //!< 2
    THREE = 3,   //!< 3
    FOUR = 4,    //!< 4
    FIVE = 5,    //!< 5
    SIX = 6,     //!< 6
    SEVEN = 7,   //!< 7
    EIGHT = 8,   //!< 8
    NINE = 9,    //!< 9
    HYPHEN = 10, //!< -
    E = 11,      //!< E
    H = 12,      //!< H
    L = 13,      //!< L
    P = 14,      //!< P
    BLANK = 15   //!< ' '
  };

  //! \brief Class definition for the ICM7212A driver
  class ICM7212A
  {
    public:
      /*! \brief Constructor
       *  \param port The port to use (i.e. PORTA, PORTB, etc.)
       *  \param bit_order The pin-to-pin connection between AVR and ICM7212A
       */
      ICM7212A(volatile uint8_t *port, enum ICM7212BitOrder bit_order);
      
      //! \brief Destructor
      ~ICM7212A();

      /*! \brief Write value to display
       *  \param value The value to write. Must be (0..9,-,E,H,L,P,' ')
       *  \return 0 if successful, -1 on failure
       */
      int8_t write(const char *value);
      
      //! \brief Clear display
      void clear();

    private:
      volatile uint8_t *port;
      uint8_t DATA_INPUT;
      uint8_t DIGIT_SEL;
      void display(enum ICM7212ACodeB [4]);
  };
}
#endif // ICM7212A_H

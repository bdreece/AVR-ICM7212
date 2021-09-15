/*! \brief ICM7212AM Driver
 *  Header file for the Maxim Integrated ICM7212AM driver.
 *
 *  \author Brian Reece
 *  \date 09/15/2021
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
  //! Class definition for the ICM7212AM driver
  class ICM7212AM
  {
    public:
      /*! \brief Constructor
       *  \param port The port to use (i.e. PORTA, PORTB, etc.)
       *  \param bit_order The pin-to-pin connection between AVR and ICM7212AM
       */
      ICM7212AM(volatile uint8_t *port, enum ICM7212BitOrder bit_order);
      
      //! Destructor
      ~ICM7212AM();

      /*! \brief Write value to display
       *  \param value The value to write. Must be (0..9,-,E,H,L,P,' ')
       *  \return 0 if successful, -1 on error
       */
      int8_t write(const char *value);

      //! \brief Clear the display
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
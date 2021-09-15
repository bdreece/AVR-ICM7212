/*! \brief ICM7212M Driver
 *  Header file for the Maxim Integrated ICM7212M driver.
 *
 *  \author Brian Reece
 *  \date 09/15/2021
 */

#ifndef ICM7212M_H
#define ICM7212M_H

#ifndef ICM7212_H
#include "ICM7212.hpp"
#endif

namespace icm7212
{
  //! \brief Class definition for the ICM7212M driver
  class ICM7212M
  {
    public:
      /*! \brief Constructor
       *  \param port The port to use (i.e. PORTA, PORTB, etc.)
       *  \param bit_order The pin-to-pin connection between AVR and ICM7212M
       */
      ICM7212M(volatile uint8_t *port, enum ICM7212BitOrder bit_order);
      
      //! \brief Destructor
      ~ICM7212M();

      /*! \brief Write value to display
       *  \param The value to write (ceiling at 9999)
       */
      void write(uint16_t value);

    private:
      volatile uint8_t *port;
      uint8_t DATA_INPUT;
      uint8_t DIGIT_SEL;
      uint8_t CHIP_SEL;
  };
}

#endif // ICM7212M_H
/*! \brief ICM7212 Driver
 *  Header file for the Maxim Integrated base ICM7212xx driver.
 *
 *  \author Brian Reece
 *  \date 09/15/2021
 */

#ifndef ICM7212_H
#define ICM7212_H

#include <stdint.h>

namespace icm7212
{ 
  //! Determines pin-to-pin connections between AVR and ICM7212xx
  enum ICM7212BitOrder
  {
    DATA_HIGH = 0, //!< In given port, data bits occupy [4:7], digit bits occupy [0:3].
    DIGIT_HIGH = 1 //!< In given port, data bits occupy [0:3], digit bits occupy [4:7].
  };

  //! Class definition for the ICM7217 driver
  class ICM7212
  {
    public:
      /*! \brief Constructor
       *  \param port The port to use (i.e. PORTA, PORTB, etc.)
       *  \param bit_order The pin-to-pin connections between AVR and ICM7212
       */
      ICM7212(volatile uint8_t *port, enum ICM7212BitOrder bit_order);

      //! \brief Destructor
      ~ICM7212();

      /*! \brief Write value to display
       *  \param value The value to write (ceiling at 9999)
       */
      void write(uint16_t value);

    private:
      volatile uint8_t *port;
      uint8_t DATA_INPUT;
      uint8_t DIGIT_SEL;
  };
}

#endif // ICM7212_H

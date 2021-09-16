# AVR-ICM7212

A simple AVR library for the Maxim Integrated ICM7212 family of 7-segment LED drivers

## Table of Contents
 - [Build Dependencies](#build-dependencies)
 - [Building](#building)
 - [Demo](#demo)
 - [Credits](#credits)

---

### Build Dependencies

In order to build this library, the following must be installed on your system:

 - make
 - avr-g++
 - avr-binutils
 - avr-libc

### Building

The library can be build by modifying the MMCU line of the Makefile to match your uC. Then, enter the following command in your terminal:

`make`

You will find that lib/libICM7212.a has been created, and can be linked against your AVR applications!

### Demo

The source for this library also ships with a demo application for the ATMega32u4. The demo can be built with the following command:

`make all`

You will find that bin/ICM7212AM_demo.hex has been created (this is the model I own). The demo can be flashed to the ATMega32u4 using avrdude.

### Credits

Everything was written by me (except avrlibc of course), and is licensed with the GPL-2 license. Note that, in accordance with the aforementioned license, I assume NO LIABILITY and there is NO WARRANTY associated with the included software. Use at your own risk.
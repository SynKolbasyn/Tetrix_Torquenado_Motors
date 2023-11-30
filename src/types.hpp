#pragma once

#ifndef _TYPES_HPP_
#define _TYPES_HPP_


#include <Arduino.h>


namespace sk {


typedef char i8;
typedef unsigned char u8;

typedef short i16;
typedef unsigned short u16;

typedef long i32;
typedef unsigned long u32;

typedef float f32;
typedef double f64;


enum Motors: u8 {
  MOTOR_1 = 0,
  MOTOR_2 = 1,
  ALL_MOTORS
};


enum Drivers: u8 {
  DRIVER_1 = 1,
  DRIVER_2 = 2,
  DRIVER_3 = 3,
  DRIVER_4 = 4
};


} // namespace sk



#endif

#pragma once

#ifndef _TETRIX_TORQ_HPP_
#define _TETRIX_TORQ_HPP_


#include <Arduino.h>
#include <Wire.h>

#include "driver.hpp"
#include "types.hpp"


namespace sk {


using namespace driver;
using namespace motor;


class Tetrix_torq {
public:
  Tetrix_torq();
  ~Tetrix_torq();

  bool is_initialized();
  bool set_driver(Drivers driver, u8 addrss, Motors motors);
  void get_i2c_addrss();
  bool set_speed(Drivers driver, Motors motors, i16 speed);

private:
  Driver _driver1;
  Driver _driver2;
  Driver _driver3;
  Driver _driver4;
};


} // namespace sk


#endif

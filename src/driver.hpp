#pragma once

#ifndef _DRIVER_HPP_
#define _DRIVER_HPP_


#include <Arduino.h>
#include <Wire.h>

#include "motor.hpp"
#include "types.hpp"


namespace sk {
namespace driver {


using namespace motor;


class Driver {
public:
  Driver();
  Driver(Motors motors, u8 id);
  ~Driver();

  bool is_initialized();
  bool set_speed(Motors motors, i16 speed);

private:
  u8 _id;
  Motor _motor1;
  Motor _motor2;

  bool send_command(u8 id, u16 command);
  bool send_command_4(u8 id, u16 command, u8 b1, u8 b2, u8 b3, u8 b4);
};


} // namespace driver
} // namespace sk


#endif

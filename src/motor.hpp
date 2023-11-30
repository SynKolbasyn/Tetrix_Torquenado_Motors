#pragma once

#ifndef _MOTOR_HPP_
#define _MOTOR_HPP_


#include <Arduino.h>
#include <Wire.h>

#include "types.hpp"


namespace sk {
namespace motor {


class Motor {
public:
  Motor();
  Motor(Motors motor_number, u8 parent_id);
  ~Motor();

  bool is_initialized();
  bool set_speed(i16 speed);

private:
  bool _is_initialized;
  Motors _id;
  u8 _parent_id;

  bool send_command(u8 id, u16 command);
  bool send_command_2(u8 id, u16 command, u8 b1, u8 b2);
  bool send_command_4(u8 id, u16 command, u8 b1, u8 b2, u8 b3, u8 b4);
};


} // namespace motor
} // namespace sk


#endif

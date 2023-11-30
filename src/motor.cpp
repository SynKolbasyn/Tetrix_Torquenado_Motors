#include "motor.hpp"


namespace sk {
namespace motor {


Motor::Motor() {
  _is_initialized = false;
}


Motor::Motor(Motors motor_number, u8 parent_id) {
  _id = motor_number;
  _is_initialized = true;
  _parent_id = parent_id;
  send_command(_parent_id, 0x4C + _id);
}


Motor::~Motor() {
  _is_initialized = false;
}


bool Motor::is_initialized() {
  return _is_initialized;
}


bool Motor::set_speed(i16 speed) {
  if (!_is_initialized) return false;
  return send_command_2(_parent_id, 0x43 + _id, speed >> 8, speed & 0b11111111);
}


bool Motor::send_command(u8 id, u16 command) {
  Wire.beginTransmission(id);
  Wire.write(command);
  return Wire.endTransmission() == 0;
}


bool Motor::send_command_2(u8 id, u16 command, u8 b1, u8 b2) {
  Wire.beginTransmission(id);
  Wire.write(command);
  Wire.write(b1);
  Wire.write(b2);
  return Wire.endTransmission() == 0;
}


bool Motor::send_command_4(u8 id, u16 command, u8 b1, u8 b2, u8 b3, u8 b4) {
  Wire.beginTransmission(id);
  Wire.write(command);
  Wire.write(b1);
  Wire.write(b2);
  Wire.write(b3);
  Wire.write(b4);
  return Wire.endTransmission() == 0;
}


} // namespace motor
} // namespace sk

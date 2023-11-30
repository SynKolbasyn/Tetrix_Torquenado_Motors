#include "driver.hpp"


namespace sk {
namespace driver {


using namespace motor;


Driver::Driver() {

}


Driver::Driver(Motors motors, u8 id) {
  switch (motors) {
  case Motors::MOTOR_1:
    _motor1 = Motor(Motors::MOTOR_1, id);
    break;
  
  case Motors::MOTOR_2:
    _motor2 = Motor(Motors::MOTOR_2, id);
    break;
  
  case Motors::ALL_MOTORS:
    _motor1 = Motor(Motors::MOTOR_1, id);
    _motor2 = Motor(Motors::MOTOR_2, id);
    break;
  
  default:
    break;
  }

  _id = id;

  send_command(_id, 0x25);
  send_command(_id, 0x27);
}


Driver::~Driver() {
  _motor1.~Motor();
  _motor2.~Motor();
}


bool Driver::is_initialized() {
  return _motor1.is_initialized() || _motor2.is_initialized();
}


bool Driver::set_speed(Motors motors, i16 speed) {
  switch (motors) {
  case Motors::MOTOR_1:
    return _motor1.set_speed(speed);
  
  case Motors::MOTOR_2:
    return _motor2.set_speed(speed);
  
  case Motors::ALL_MOTORS:
    return _motor1.set_speed(speed) && _motor2.set_speed(speed);
  
  default:
    return false;
  }
}


bool Driver::send_command(u8 id, u16 command) {
  Wire.beginTransmission(id);
  Wire.write(command);
  return Wire.endTransmission() == 0;
}


bool Driver::send_command_4(u8 id, u16 command, u8 b1, u8 b2, u8 b3, u8 b4) {
  Wire.beginTransmission(id);
  Wire.write(command);
  Wire.write(b1);
  Wire.write(b2);
  Wire.write(b3);
  Wire.write(b4);
  return Wire.endTransmission() == 0;
}


} // namespace driver
} // namespace sk

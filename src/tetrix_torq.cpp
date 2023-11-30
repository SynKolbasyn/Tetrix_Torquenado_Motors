#include "tetrix_torq.hpp"


namespace sk {


using namespace driver;
using namespace motor;


Tetrix_torq::Tetrix_torq() {
  Wire.begin();
}


Tetrix_torq::~Tetrix_torq() {
  _driver1.~Driver();
  _driver2.~Driver();
  _driver3.~Driver();
  _driver4.~Driver();
}


bool Tetrix_torq::is_initialized() {
  return _driver1.is_initialized() || _driver2.is_initialized() || _driver3.is_initialized() || _driver4.is_initialized();
}


bool Tetrix_torq::set_driver(Drivers driver, u8 addrss, Motors motors) {
  switch (driver) {
  case Drivers::DRIVER_1:
    _driver1 = Driver(motors, addrss);
    return true;
  
  case Drivers::DRIVER_2:
    _driver2 = Driver(motors, addrss);
    return true;
  
  case Drivers::DRIVER_3:
    _driver3 = Driver(motors, addrss);
    return true;
  
  case Drivers::DRIVER_4:
    _driver4 = Driver(motors, addrss);
    return true;
  
  default:
    return false;
  }
}


void Tetrix_torq::get_i2c_addrss() {
  Serial.begin(9600);
  Serial.print("ADDRSS:");
  for (u8 i = 1; i < 127; ++i) {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0) {
      Serial.print("\t");
      Serial.print(i);
    }
  }
  Serial.println("\n----------");
}


bool Tetrix_torq::set_speed(Drivers driver, Motors motors, i16 speed) {
  switch (driver) {
  case Drivers::DRIVER_1:
    return _driver1.set_speed(motors, speed);
  
  case Drivers::DRIVER_2:
    return _driver2.set_speed(motors, speed);
  
  case Drivers::DRIVER_3:
    return _driver3.set_speed(motors, speed);
  
  case Drivers::DRIVER_4:
    return _driver4.set_speed(motors, speed);
  
  default:
    return false;
  }
}


} // namespace sk

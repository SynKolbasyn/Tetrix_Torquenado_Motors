#include <tetrix_torq.hpp>


sk::Tetrix_torq torq;


void setup() {
  Serial.begin(9600);
  while (!torq.add_driver(sk::Drivers::DRIVER_1, sk::Motors::MOTOR_1)) Serial.println("Initialization error");
}


void loop() {
  if (torq.is_initialized()) {
    if (!torq.set_speed(sk::Drivers::DRIVER_1, sk::Motors::MOTOR_1, 100)) Serial.println("Speed setting error");
  }
}

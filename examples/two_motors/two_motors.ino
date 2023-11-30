#include <tetrix_torq.hpp>


using namespace sk;


Tetrix_torq torq;


void setup() {
  Serial.begin(9600);
  while (!torq.set_driver(Drivers::DRIVER_1, 1, Motors::ALL_MOTORS)) Serial.println("Initialization error");
}


void loop() {
  if (torq.is_initialized()) if (!torq.set_speed(Drivers::DRIVER_1, Motors::ALL_MOTORS, 100)) Serial.println("Speed setting error");
}

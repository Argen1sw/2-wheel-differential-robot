#ifndef DIFFDRIVE_ARDUINO_FAKE_ROBOT_H
#define DIFFDRIVE_ARDUINO_FAKE_ROBOT_H


#include "rclcpp/rclcpp.hpp"

// #include "hardware_interface/base_interface.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
// #include "hardware_interface/types/hardware_interface_status_values.hpp"


#include "config.h"
#include "wheel.h"

using hardware_interface::return_type;

// class FakeRobot : public hardware_interface::BaseInterface<hardware_interface::SystemInterface>
class FakeRobot : public hardware_interface::SystemInterface
{


public:
  FakeRobot();

  return_type configure(const hardware_interface::HardwareInfo & info);

  std::vector<hardware_interface::StateInterface> export_state_interfaces() override;

  std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;

  return_type start();

  return_type stop();

  // return_type read() override;

  // return_type write() override;

  return_type read(const rclcpp::Time & time, const rclcpp::Duration & period) override;

  return_type write(const rclcpp::Time & time, const rclcpp::Duration & period) override;



private:

  Config cfg_;

  Wheel l_wheel_;
  Wheel r_wheel_;

  rclcpp::Logger logger_;

  std::chrono::time_point<std::chrono::system_clock> time_;
  
};


#endif // DIFFDRIVE_ARDUINO_FAKE_ROBOT_H
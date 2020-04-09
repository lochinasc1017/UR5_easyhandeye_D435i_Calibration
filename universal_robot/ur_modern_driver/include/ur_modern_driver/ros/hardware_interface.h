/*
 * Copyright 2017, 2018 Simon Rasmussen (refactor)
 *
 * Copyright 2015, 2016 Thomas Timm Andersen (original version)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include <controller_manager/controller_manager.h>
#include <hardware_interface/force_torque_sensor_interface.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <algorithm>
#include "ur_modern_driver/ros/trajectory_follower.h"
#include "ur_modern_driver/ur/commander.h"
#include "ur_modern_driver/ur/rt_state.h"

class HardwareInterface
{
public:
  virtual bool write() = 0;
  virtual void start()
  {
  }
  virtual void stop()
  {
  }
  virtual void reset()
  {
  }
};

using hardware_interface::JointHandle;

class JointInterface : public hardware_interface::JointStateInterface
{
private:
  std::array<double, 6> velocities_, positions_, efforts_;

public:
  JointInterface(std::vector<std::string> &joint_names);
  void update(RTShared &packet);

  typedef hardware_interface::JointStateInterface parent_type;
  static const std::string INTERFACE_NAME;
};

class WrenchInterface : public hardware_interface::ForceTorqueSensorInterface
{
  std::array<double, 6> tcp_;

public:
  WrenchInterface(std::string wrench_frame);
  void update(RTShared &packet);
  typedef hardware_interface::ForceTorqueSensorInterface parent_type;
  static const std::string INTERFACE_NAME;
};

class VelocityInterface : public HardwareInterface, public hardware_interface::VelocityJointInterface
{
private:
  URCommander &commander_;
  std::array<double, 6> velocity_cmd_, prev_velocity_cmd_;
  double max_vel_change_;

public:
  VelocityInterface(URCommander &commander, hardware_interface::JointStateInterface &js_interface,
                    std::vector<std::string> &joint_names, double max_vel_change);
  virtual bool write();
  virtual void reset();
  typedef hardware_interface::VelocityJointInterface parent_type;
  static const std::string INTERFACE_NAME;
};

class PositionInterface : public HardwareInterface, public hardware_interface::PositionJointInterface
{
private:
  TrajectoryFollower &follower_;
  std::array<double, 6> position_cmd_;

public:
  PositionInterface(TrajectoryFollower &follower, hardware_interface::JointStateInterface &js_interface,
                    std::vector<std::string> &joint_names);
  virtual bool write();
  virtual void start();
  virtual void stop();

  typedef hardware_interface::PositionJointInterface parent_type;
  static const std::string INTERFACE_NAME;
};

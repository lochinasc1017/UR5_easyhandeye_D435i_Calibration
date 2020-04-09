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

#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/WrenchStamped.h>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <sensor_msgs/Temperature.h>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>
#include <cstdlib>
#include <vector>

#include "ur_modern_driver/ur/consumer.h"

using namespace ros;
using namespace tf;

const std::string JOINTS[] = { "shoulder_pan_joint", "shoulder_lift_joint", "elbow_joint",
                               "wrist_1_joint",      "wrist_2_joint",       "wrist_3_joint" };
// links with origin in the joints configured above.
const std::string LINKS[] = { "shoulder_link", "upper_arm_link", "forearm_link",
                              "wrist_1_link",  "wrist_2_link",   "wrist_3_link" };

class RTPublisher : public URRTPacketConsumer
{
private:
  NodeHandle nh_;
  Publisher joint_pub_;
  Publisher wrench_pub_;
  Publisher tool_vel_pub_;
  Publisher joint_temperature_pub_;
  TransformBroadcaster transform_broadcaster_;
  std::vector<std::string> joint_names_;
  std::vector<std::string> link_names_;
  std::string base_frame_;
  std::string tool_frame_;
  bool temp_only_;

  bool publishJoints(RTShared& packet, Time& t);
  bool publishWrench(RTShared& packet, Time& t);
  bool publishTool(RTShared& packet, Time& t);
  bool publishTransform(RTShared& packet, Time& t);
  bool publishTemperature(RTShared& packet, Time& t);

  bool publish(RTShared& packet);

public:
  RTPublisher(std::string& joint_prefix, std::string& base_frame, std::string& tool_frame, bool temp_only = false)
    : joint_pub_(nh_.advertise<sensor_msgs::JointState>("joint_states", 1))
    , wrench_pub_(nh_.advertise<geometry_msgs::WrenchStamped>("wrench", 1))
    , tool_vel_pub_(nh_.advertise<geometry_msgs::TwistStamped>("tool_velocity", 1))
    , joint_temperature_pub_(nh_.advertise<sensor_msgs::Temperature>("joint_temperature", 1))
    , base_frame_(base_frame)
    , tool_frame_(tool_frame)
    , temp_only_(temp_only)
  {
    for (auto const& j : JOINTS)
    {
      joint_names_.push_back(joint_prefix + j);
    }
    for (auto const& link : LINKS)
    {
      link_names_.push_back(joint_prefix + link);
    }
  }

  virtual bool consume(RTState_V1_6__7& state);
  virtual bool consume(RTState_V1_8& state);
  virtual bool consume(RTState_V3_0__1& state);
  virtual bool consume(RTState_V3_2__3& state);

  virtual void setupConsumer()
  {
  }
  virtual void teardownConsumer()
  {
  }
  virtual void stopConsumer()
  {
  }
};

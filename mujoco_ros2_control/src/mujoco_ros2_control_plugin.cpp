// Copyright (c) 2025 Ruixiang Du
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "mujoco_ros2_control/mujoco_ros2_control_plugin.hpp"

namespace mujoco_ros2_control
{
void MujocoRos2ControlPlugin::Configure(
  rclcpp::Node::SharedPtr &node, rclcpp::NodeOptions cm_node_option, mjModel *model, mjData *data)
{
  control_ =
    std::make_unique<mujoco_ros2_control::MujocoRos2Control>(node, cm_node_option, model, data);
  control_->init();
  RCLCPP_INFO_STREAM(
    node->get_logger(), "Mujoco ros2 controller has been successfully initialized !");
}

void MujocoRos2ControlPlugin::Reset(mjModel *model, mjData *data)
{
  // reset mujoco model and data
  (void)model;  // suppress unused parameter warning
  (void)data;   // suppress unused parameter warning
}

void MujocoRos2ControlPlugin::PreUpdate(mjModel *model, mjData *data)
{
  // pre-update logic
  control_->pre_update();
  (void)model;  // suppress unused parameter warning
  (void)data;   // suppress unused parameter warning
}

void MujocoRos2ControlPlugin::Update(mjModel *model, mjData *data)
{
  // update logic
  control_->update();
  (void)model;  // suppress unused parameter warning
  (void)data;   // suppress unused parameter warning
}

void MujocoRos2ControlPlugin::PostUpdate(mjModel *model, mjData *data)
{
  // post-update logic
  (void)model;  // suppress unused parameter warning
  (void)data;   // suppress unused parameter warning
}
}  // namespace mujoco_ros2_control

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(
  mujoco_ros2_control::MujocoRos2ControlPlugin, mujoco_sim_ros2::MujocoPhysicsPlugin)

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

#ifndef MUJOCO_ROS2_CONTROL__MUJOCO_ROS2_CONTROL_PLUGIN_HPP_
#define MUJOCO_ROS2_CONTROL__MUJOCO_ROS2_CONTROL_PLUGIN_HPP_

#include <memory>

#include "mujoco_ros2_control/mujoco_ros2_control.hpp"
#include "mujoco_sim_ros2/mujoco_physics_plugin.hpp"

namespace mujoco_ros2_control
{
class MujocoRos2ControlPlugin final : public mujoco_sim_ros2::MujocoPhysicsPlugin
{
public:
  MujocoRos2ControlPlugin() = default;
  virtual ~MujocoRos2ControlPlugin() = default;

  void Configure(
    rclcpp::Node::SharedPtr &node, rclcpp::NodeOptions cm_node_option, mjModel *model,
    mjData *data) override;
  void Reset(mjModel *model, mjData *data) override;
  void PreUpdate(mjModel *model, mjData *data) override;
  void Update(mjModel *model, mjData *data) override;
  void PostUpdate(mjModel *model, mjData *data) override;

private:
  std::unique_ptr<MujocoRos2Control> control_;
};
}  // namespace mujoco_ros2_control

#endif  // MUJOCO_ROS2_CONTROL__MUJOCO_ROS2_CONTROL_PLUGIN_HPP_

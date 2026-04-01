// Copyright 2024 Harun Teper
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include <chrono>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "reference_interfaces/msg/message4kb.hpp"

using namespace std::chrono_literals;

class BehaviorPlanner : public rclcpp::Node
{
public:
  BehaviorPlanner()
  : Node("BehaviorPlanner")
  {
    sub_0_ = this->create_subscription<reference_interfaces::msg::Message4kb>(
      "ObjectCollisionEstimator", 1,
      std::bind(&BehaviorPlanner::sub_callback_0, this, std::placeholders::_1));
    sub_1_ = this->create_subscription<reference_interfaces::msg::Message4kb>(
      "NDTLocalizer", 1,
      std::bind(&BehaviorPlanner::sub_callback_1, this, std::placeholders::_1));
    sub_2_ = this->create_subscription<reference_interfaces::msg::Message4kb>(
      "Lanelet2GlobalPlanner", 1,
      std::bind(&BehaviorPlanner::sub_callback_2, this, std::placeholders::_1));
    sub_3_ = this->create_subscription<reference_interfaces::msg::Message4kb>(
      "Lanelet2MapLoader", 1,
      std::bind(&BehaviorPlanner::sub_callback_3, this, std::placeholders::_1));
    sub_4_ = this->create_subscription<reference_interfaces::msg::Message4kb>(
      "ParkingPlanner", 1,
      std::bind(&BehaviorPlanner::sub_callback_4, this, std::placeholders::_1));
    sub_5_ = this->create_subscription<reference_interfaces::msg::Message4kb>(
      "LanePlanner", 1,
      std::bind(&BehaviorPlanner::sub_callback_5, this, std::placeholders::_1));
    publisher_ = this->create_publisher<reference_interfaces::msg::Message4kb>("BehaviorPlanner", 1);
    timer_ = this->create_wall_timer(
      100ms, std::bind(&BehaviorPlanner::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto msg = publisher_->borrow_loaned_message();
    publisher_->publish(std::move(msg));
  }

  void sub_callback_0(const reference_interfaces::msg::Message4kb::SharedPtr msg)
  {
    (void)msg;
  }

  void sub_callback_1(const reference_interfaces::msg::Message4kb::SharedPtr msg)
  {
    (void)msg;
  }

  void sub_callback_2(const reference_interfaces::msg::Message4kb::SharedPtr msg)
  {
    (void)msg;
  }

  void sub_callback_3(const reference_interfaces::msg::Message4kb::SharedPtr msg)
  {
    (void)msg;
  }

  void sub_callback_4(const reference_interfaces::msg::Message4kb::SharedPtr msg)
  {
    (void)msg;
  }

  void sub_callback_5(const reference_interfaces::msg::Message4kb::SharedPtr msg)
  {
    (void)msg;
  }

  rclcpp::Subscription<reference_interfaces::msg::Message4kb>::SharedPtr sub_0_;
  rclcpp::Subscription<reference_interfaces::msg::Message4kb>::SharedPtr sub_1_;
  rclcpp::Subscription<reference_interfaces::msg::Message4kb>::SharedPtr sub_2_;
  rclcpp::Subscription<reference_interfaces::msg::Message4kb>::SharedPtr sub_3_;
  rclcpp::Subscription<reference_interfaces::msg::Message4kb>::SharedPtr sub_4_;
  rclcpp::Subscription<reference_interfaces::msg::Message4kb>::SharedPtr sub_5_;
  rclcpp::Publisher<reference_interfaces::msg::Message4kb>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<BehaviorPlanner>());
  rclcpp::shutdown();
  return 0;
}

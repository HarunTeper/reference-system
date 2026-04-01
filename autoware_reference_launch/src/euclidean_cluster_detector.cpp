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
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "reference_interfaces/msg/message4kb.hpp"

class EuclideanClusterDetector : public rclcpp::Node
{
public:
  EuclideanClusterDetector()
  : Node("EuclideanClusterDetector")
  {
    pub_0_ = this->create_publisher<reference_interfaces::msg::Message4kb>("EuclideanClusterDetector", 1);
    pub_1_ = this->create_publisher<reference_interfaces::msg::Message4kb>("EuclideanIntersection", 1);
    sub_0_ = this->create_subscription<reference_interfaces::msg::Message4kb>(
      "RayGroundFilter", 1,
      std::bind(&EuclideanClusterDetector::sub_callback_0, this, std::placeholders::_1));
    sub_1_ = this->create_subscription<reference_interfaces::msg::Message4kb>(
      "EuclideanClusterSettings", 1,
      std::bind(&EuclideanClusterDetector::sub_callback_1, this, std::placeholders::_1));
  }

private:
  void sub_callback_0(const reference_interfaces::msg::Message4kb::SharedPtr msg)
  {
    (void)msg;
    auto out = pub_0_->borrow_loaned_message();
    pub_0_->publish(std::move(out));
  }

  void sub_callback_1(const reference_interfaces::msg::Message4kb::SharedPtr msg)
  {
    (void)msg;
    auto out = pub_1_->borrow_loaned_message();
    pub_1_->publish(std::move(out));
  }

  rclcpp::Subscription<reference_interfaces::msg::Message4kb>::SharedPtr sub_0_;
  rclcpp::Subscription<reference_interfaces::msg::Message4kb>::SharedPtr sub_1_;
  rclcpp::Publisher<reference_interfaces::msg::Message4kb>::SharedPtr pub_0_;
  rclcpp::Publisher<reference_interfaces::msg::Message4kb>::SharedPtr pub_1_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<EuclideanClusterDetector>());
  rclcpp::shutdown();
  return 0;
}

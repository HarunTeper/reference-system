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

class EuclideanClusterSettings : public rclcpp::Node
{
public:
  EuclideanClusterSettings()
  : Node("EuclideanClusterSettings")
  {
    publisher_ = this->create_publisher<reference_interfaces::msg::Message4kb>("EuclideanClusterSettings", 1);
    timer_ = this->create_wall_timer(
      25ms, std::bind(&EuclideanClusterSettings::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto msg = publisher_->borrow_loaned_message();
    publisher_->publish(std::move(msg));
  }

  rclcpp::Publisher<reference_interfaces::msg::Message4kb>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<EuclideanClusterSettings>());
  rclcpp::shutdown();
  return 0;
}

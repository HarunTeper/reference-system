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

using std::placeholders::_1;

class Lanelet2MapLoader : public rclcpp::Node
{
public:
  Lanelet2MapLoader()
  : Node("Lanelet2MapLoader")
  {
    sub_0_ = this->create_subscription<reference_interfaces::msg::Message4kb>(
      "Lanelet2Map", 1,
      std::bind(&Lanelet2MapLoader::input_callback_0, this, _1));
    sub_1_ = this->create_subscription<reference_interfaces::msg::Message4kb>(
      "Lanelet2GlobalPlanner", 1,
      std::bind(&Lanelet2MapLoader::input_callback_1, this, _1));
    publisher_ = this->create_publisher<reference_interfaces::msg::Message4kb>("Lanelet2MapLoader", 1);
  }

private:
  void input_callback_0(const reference_interfaces::msg::Message4kb::SharedPtr msg)
  {
    (void)msg;
    auto out = publisher_->borrow_loaned_message();
    publisher_->publish(std::move(out));
  }

  void input_callback_1(const reference_interfaces::msg::Message4kb::SharedPtr msg)
  {
    (void)msg;
    auto out = publisher_->borrow_loaned_message();
    publisher_->publish(std::move(out));
  }

  rclcpp::Subscription<reference_interfaces::msg::Message4kb>::SharedPtr sub_0_;
  rclcpp::Subscription<reference_interfaces::msg::Message4kb>::SharedPtr sub_1_;
  rclcpp::Publisher<reference_interfaces::msg::Message4kb>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Lanelet2MapLoader>());
  rclcpp::shutdown();
  return 0;
}

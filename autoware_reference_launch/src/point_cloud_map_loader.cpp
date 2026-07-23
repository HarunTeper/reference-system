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
#include <cstdint>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "reference_interfaces/msg/message4kb.hpp"

using std::placeholders::_1;

// Workload replicated from reference_system/number_cruncher.hpp (Apex.AI,
// Apache-2.0): count primes below maximum_number by trial division.
template<typename Tp>
inline void escape(Tp const & value)
{
  asm volatile ("" : : "g" (value) : "memory");
}

static inline int64_t number_cruncher(const uint64_t maximum_number)
{
  int64_t number_of_primes = 0;
  uint64_t initial_value = 2;
  if (maximum_number <= initial_value) {
    return 2;
  }
  for (uint64_t i = initial_value; i <= maximum_number; ++i) {
    bool is_prime = true;
    for (uint64_t n = initial_value; n < i; ++n) {
      if (i % n == 0) {
        is_prime = false;
        break;
      }
    }
    escape(is_prime);
    if (is_prime) {
      ++number_of_primes;
    }
  }
  return number_of_primes;
}

class PointCloudMapLoader : public rclcpp::Node
{
public:
  PointCloudMapLoader()
  : Node("PointCloudMapLoader")
  {
    subscription_ = this->create_subscription<reference_interfaces::msg::Message4kb>(
      "PointCloudMap", 1,
      std::bind(&PointCloudMapLoader::sub_callback, this, _1));
    publisher_ = this->create_publisher<reference_interfaces::msg::Message4kb>("PointCloudMapLoader", 1);
  }

private:
  void sub_callback(const reference_interfaces::msg::Message4kb::SharedPtr msg)
  {
    (void)msg;
    auto crunch_result = number_cruncher(4096);
    escape(crunch_result);
    auto out = publisher_->borrow_loaned_message();
    publisher_->publish(std::move(out));
  }

  rclcpp::Subscription<reference_interfaces::msg::Message4kb>::SharedPtr subscription_;
  rclcpp::Publisher<reference_interfaces::msg::Message4kb>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PointCloudMapLoader>());
  rclcpp::shutdown();
  return 0;
}

# Copyright 2024 Harun Teper
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
cmake_minimum_required(VERSION 3.8)
project(autoware_reference_launch)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(reference_interfaces REQUIRED)

add_executable(front_lidar_driver src/front_lidar_driver.cpp)
ament_target_dependencies(front_lidar_driver rclcpp reference_interfaces)

add_executable(rear_lidar_driver src/rear_lidar_driver.cpp)
ament_target_dependencies(rear_lidar_driver rclcpp reference_interfaces)

add_executable(point_cloud_map src/point_cloud_map.cpp)
ament_target_dependencies(point_cloud_map rclcpp reference_interfaces)

add_executable(visualizer src/visualizer.cpp)
ament_target_dependencies(visualizer rclcpp reference_interfaces)

add_executable(lanelet2_map src/lanelet2_map.cpp)
ament_target_dependencies(lanelet2_map rclcpp reference_interfaces)

add_executable(euclidean_cluster_settings src/euclidean_cluster_settings.cpp)
ament_target_dependencies(euclidean_cluster_settings rclcpp reference_interfaces)

add_executable(points_transformer_front src/points_transformer_front.cpp)
ament_target_dependencies(points_transformer_front rclcpp reference_interfaces)

add_executable(points_transformer_rear src/points_transformer_rear.cpp)
ament_target_dependencies(points_transformer_rear rclcpp reference_interfaces)

add_executable(voxel_grid_downsampler src/voxel_grid_downsampler.cpp)
ament_target_dependencies(voxel_grid_downsampler rclcpp reference_interfaces)

add_executable(point_cloud_map_loader src/point_cloud_map_loader.cpp)
ament_target_dependencies(point_cloud_map_loader rclcpp reference_interfaces)

add_executable(ray_ground_filter src/ray_ground_filter.cpp)
ament_target_dependencies(ray_ground_filter rclcpp reference_interfaces)

add_executable(object_collision_estimator src/object_collision_estimator.cpp)
ament_target_dependencies(object_collision_estimator rclcpp reference_interfaces)

add_executable(mpccontroller src/mpccontroller.cpp)
ament_target_dependencies(mpccontroller rclcpp reference_interfaces)

add_executable(parking_planner src/parking_planner.cpp)
ament_target_dependencies(parking_planner rclcpp reference_interfaces)

add_executable(lane_planner src/lane_planner.cpp)
ament_target_dependencies(lane_planner rclcpp reference_interfaces)

add_executable(point_cloud_fusion src/point_cloud_fusion.cpp)
ament_target_dependencies(point_cloud_fusion rclcpp reference_interfaces)

add_executable(ndtlocalizer src/ndtlocalizer.cpp)
ament_target_dependencies(ndtlocalizer rclcpp reference_interfaces)

add_executable(vehicle_interface src/vehicle_interface.cpp)
ament_target_dependencies(vehicle_interface rclcpp reference_interfaces)

add_executable(lanelet2_global_planner src/lanelet2_global_planner.cpp)
ament_target_dependencies(lanelet2_global_planner rclcpp reference_interfaces)

add_executable(lanelet2_map_loader src/lanelet2_map_loader.cpp)
ament_target_dependencies(lanelet2_map_loader rclcpp reference_interfaces)

add_executable(behavior_planner src/behavior_planner.cpp)
ament_target_dependencies(behavior_planner rclcpp reference_interfaces)

add_executable(euclidean_cluster_detector src/euclidean_cluster_detector.cpp)
ament_target_dependencies(euclidean_cluster_detector rclcpp reference_interfaces)

add_executable(vehicle_dbwsystem src/vehicle_dbwsystem.cpp)
ament_target_dependencies(vehicle_dbwsystem rclcpp reference_interfaces)

add_executable(intersection_output src/intersection_output.cpp)
ament_target_dependencies(intersection_output rclcpp reference_interfaces)

install(TARGETS front_lidar_driver rear_lidar_driver point_cloud_map visualizer lanelet2_map euclidean_cluster_settings points_transformer_front points_transformer_rear voxel_grid_downsampler point_cloud_map_loader ray_ground_filter object_collision_estimator mpccontroller parking_planner lane_planner point_cloud_fusion ndtlocalizer vehicle_interface lanelet2_global_planner lanelet2_map_loader behavior_planner euclidean_cluster_detector vehicle_dbwsystem intersection_output
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch)

ament_package()

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
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='autoware_reference_launch',
            executable='front_lidar_driver',
            name='FrontLidarDriver',
        ),
        Node(
            package='autoware_reference_launch',
            executable='rear_lidar_driver',
            name='RearLidarDriver',
        ),
        Node(
            package='autoware_reference_launch',
            executable='point_cloud_map',
            name='PointCloudMap',
        ),
        Node(
            package='autoware_reference_launch',
            executable='visualizer',
            name='Visualizer',
        ),
        Node(
            package='autoware_reference_launch',
            executable='lanelet2_map',
            name='Lanelet2Map',
        ),
        Node(
            package='autoware_reference_launch',
            executable='euclidean_cluster_settings',
            name='EuclideanClusterSettings',
        ),
        Node(
            package='autoware_reference_launch',
            executable='points_transformer_front',
            name='PointsTransformerFront',
        ),
        Node(
            package='autoware_reference_launch',
            executable='points_transformer_rear',
            name='PointsTransformerRear',
        ),
        Node(
            package='autoware_reference_launch',
            executable='voxel_grid_downsampler',
            name='VoxelGridDownsampler',
        ),
        Node(
            package='autoware_reference_launch',
            executable='point_cloud_map_loader',
            name='PointCloudMapLoader',
        ),
        Node(
            package='autoware_reference_launch',
            executable='ray_ground_filter',
            name='RayGroundFilter',
        ),
        Node(
            package='autoware_reference_launch',
            executable='object_collision_estimator',
            name='ObjectCollisionEstimator',
        ),
        Node(
            package='autoware_reference_launch',
            executable='mpccontroller',
            name='MPCController',
        ),
        Node(
            package='autoware_reference_launch',
            executable='parking_planner',
            name='ParkingPlanner',
        ),
        Node(
            package='autoware_reference_launch',
            executable='lane_planner',
            name='LanePlanner',
        ),
        Node(
            package='autoware_reference_launch',
            executable='point_cloud_fusion',
            name='PointCloudFusion',
        ),
        Node(
            package='autoware_reference_launch',
            executable='ndtlocalizer',
            name='NDTLocalizer',
        ),
        Node(
            package='autoware_reference_launch',
            executable='vehicle_interface',
            name='VehicleInterface',
        ),
        Node(
            package='autoware_reference_launch',
            executable='lanelet2_global_planner',
            name='Lanelet2GlobalPlanner',
        ),
        Node(
            package='autoware_reference_launch',
            executable='lanelet2_map_loader',
            name='Lanelet2MapLoader',
        ),
        Node(
            package='autoware_reference_launch',
            executable='behavior_planner',
            name='BehaviorPlanner',
        ),
        Node(
            package='autoware_reference_launch',
            executable='euclidean_cluster_detector',
            name='EuclideanClusterDetector',
        ),
        Node(
            package='autoware_reference_launch',
            executable='vehicle_dbwsystem',
            name='VehicleDBWSystem',
        ),
        Node(
            package='autoware_reference_launch',
            executable='intersection_output',
            name='IntersectionOutput',
        ),
    ])

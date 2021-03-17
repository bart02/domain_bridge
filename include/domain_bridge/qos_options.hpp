// Copyright 2021, Open Source Robotics Foundation, Inc.
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

#ifndef DOMAIN_BRIDGE__QOS_OPTIONS_HPP_
#define DOMAIN_BRIDGE__QOS_OPTIONS_HPP_

#include <optional>

#include "rclcpp/qos.hpp"

#include "domain_bridge/visibility_control.hpp"

namespace domain_bridge
{

/// Options for overriding QoS settings.
class QosOptions
{
public:
  /// Constructor.
  /**
   *  Default values:
   *
   *    - reliability = nullopt_t (detect automatically)
   *    - durability = nullopt_t (detect automatically)
   *    - history = rclcpp::HistoryPolicy::KeepLast
   *    - depth = 10
   */
  DOMAIN_BRIDGE_PUBLIC
  QosOptions() = default;

  /// Destructor.
  DOMAIN_BRIDGE_PUBLIC
  virtual
  ~QosOptions() = default;

  /// Copy constructor.
  DOMAIN_BRIDGE_PUBLIC
  QosOptions(const QosOptions & other) = default;

  /// Assignment operator.
  DOMAIN_BRIDGE_PUBLIC
  QosOptions &
  operator=(const QosOptions & other) = default;

  /// Get reliability.
  DOMAIN_BRIDGE_PUBLIC
  std::optional<rclcpp::ReliabilityPolicy>
  reliability() const;

  /// Set reliability.
  DOMAIN_BRIDGE_PUBLIC
  QosOptions &
  reliability(const rclcpp::ReliabilityPolicy & reliability);

  /// Get durability.
  DOMAIN_BRIDGE_PUBLIC
  std::optional<rclcpp::DurabilityPolicy>
  durability() const;

  /// Set durability.
  DOMAIN_BRIDGE_PUBLIC
  QosOptions &
  durability(const rclcpp::DurabilityPolicy & durability);

  /// Get history.
  DOMAIN_BRIDGE_PUBLIC
  rclcpp::HistoryPolicy
  history() const;

  /// Set history.
  DOMAIN_BRIDGE_PUBLIC
  QosOptions &
  history(const rclcpp::HistoryPolicy & history);

  /// Get history depth.
  DOMAIN_BRIDGE_PUBLIC
  std::size_t
  depth() const;

  /// Set history depth.
  DOMAIN_BRIDGE_PUBLIC
  QosOptions &
  depth(const std::size_t & depth);

private:
  std::optional<rclcpp::ReliabilityPolicy> reliability_;
  std::optional<rclcpp::DurabilityPolicy> durability_;
  rclcpp::HistoryPolicy history_{rclcpp::HistoryPolicy::KeepLast};
  std::size_t depth_{10};
};  // class QosOptions

}  // namespace domain_bridge

#endif  // DOMAIN_BRIDGE__QOS_OPTIONS_HPP_

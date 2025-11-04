/**
 * TODO: Add license
 */

#ifndef SUBSCRIBER_SUBSCRIBER_H
#define SUBSCRIBER_SUBSCRIBER_H

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>

namespace subscriber {

/**
 * @brief A node that illustrates efficient intra-process message publishing.
 */
class Subscriber: public rclcpp::Node {
  /** @brief Object responsible for publishing messages. */
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscriber_;

  /**
   * @brief Callback for timer events.
   */
  void callbackCount(std_msgs::msg::Int32::ConstSharedPtr msg);

public:
  /**
   * Create a new subscriber node.
   */
  Subscriber(rclcpp::NodeOptions options);
};

} // namespace subscriber

#endif

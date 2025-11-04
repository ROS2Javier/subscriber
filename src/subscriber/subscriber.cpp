/**
 * TODO: Add license
 */

#include <subscriber/subscriber.h>

#include <cinttypes>

namespace subscriber {

using namespace std::placeholders;

Subscriber::Subscriber(rclcpp::NodeOptions options):
  rclcpp::Node("subscriber", options.use_intra_process_comms(true))
{
  subscriber_ = create_subscription<std_msgs::msg::Int32>("topic", 1,
    std::bind(&Subscriber::callbackCount, this, _1)
  );
}

void Subscriber::callbackCount(std_msgs::msg::Int32::ConstSharedPtr msg) {
  RCLCPP_INFO(get_logger(),
    "Published message with value: %d, and address: 0x%" PRIXPTR, msg->data,
    reinterpret_cast<std::uintptr_t>(msg.get())
  );
}

} // namespace subscriber

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(subscriber::Subscriber)

cmake_minimum_required(VERSION 3.8)

project(subscriber)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Project dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(
  "include/"
)

# Define the component library
add_library(subscriber_component SHARED
  "src/subscriber/subscriber.cpp"
)

ament_target_dependencies(subscriber_component
  "rclcpp"
  "rclcpp_components"
  "std_msgs")

rclcpp_components_register_nodes(
  subscriber_component "subscriber::Subscriber"
)

ament_export_targets(export_subscriber_component)

install(TARGETS subscriber_component
        EXPORT export_subscriber_component
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

# Install launch files.
install(
  DIRECTORY
    "launch/"
  DESTINATION
    "share/${PROJECT_NAME}/launch/"
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

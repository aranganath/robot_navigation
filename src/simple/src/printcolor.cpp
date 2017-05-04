#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<stdlib.h>
#include<turtlesim/Color.h>
#include<std_msgs/String.h>

void chatterCallback(const turtlesim::Color& msg)
{
  ROS_ERROR("The color of the turtle is: %d %d %d",msg.r, msg.g, msg.b);
}

int main(int argc, char **argv){

	ros::init(argc, argv, "turtle_navigator");
        ros::NodeHandle nh;
        ros::Subscriber sub = nh.subscribe("/turtle1/color_sensor", 1000, chatterCallback);
        ros::spin();
}


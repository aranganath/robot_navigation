#include <ros/ros.h>
#include <geometry_msgs/Pose.h>
#include <stdlib.h>
#include <turtlesim/Color.h>

using namespace std;

void chatterCallback(geometry_msgs::Pose msg){
	ROS_INFO("Position:\n");
	ROS_INFO_STREAM("x:\t"<<msg.position.x<<endl);
	ROS_INFO_STREAM("y:\t"<<msg.position.y<<endl);
	ROS_INFO_STREAM("z:\t"<<msg.position.z<<endl);
	ROS_INFO("Orientation:\n");
	ROS_INFO_STREAM("x:\t"<<msg.orientation.x<<endl);
	ROS_INFO_STREAM("y:\t"<<msg.orientation.y<<endl);
	ROS_INFO_STREAM("z:\t"<<msg.orientation.z<<endl);
	ROS_INFO_STREAM("w:\t"<<msg.orientation.w<<endl);
}

int main(int argc, char **argv){

	ros::init(argc, argv, "turtle_navigator");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("averagepose", 1000, chatterCallback);
    ros::spin();
}
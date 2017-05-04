#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"

#include <sstream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "chatter");
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("string", 1000);
	ros::Publisher chatter_pub2 = n.advertise<std_msgs::Int32>("integer", 1000);
	ros::Rate loop_rate(10);
	std_msgs::Int32 num;
	while (ros::ok()){
		std_msgs:: String msg;
		std::stringstream ss;
    		ss << "Aditya";
    		msg.data = ss.str();
		ROS_INFO("%s", msg.data.c_str());
    		chatter_pub.publish(msg);
		ROS_INFO("%d", num.data);
		chatter_pub2.publish(num);
    		ros::spinOnce();
    		loop_rate.sleep();
		++num.data;
    	}
}

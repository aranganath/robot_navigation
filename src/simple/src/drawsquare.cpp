#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<stdlib.h>

int main(int argc, char **argv){

	ros::init(argc, argv, "drawsquare");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
	ros::Rate rate(1);
	while(ros::ok()){
		geometry_msgs::Twist msg, msg2;
		msg.linear.x = 2;
		msg.angular.z = 0;
		msg2.linear.x = 0;
		msg2.angular.z=3.14/2;
		pub.publish(msg);
		ROS_INFO_STREAM("Sending the velocity command for straight line"<<"linear"<<msg.linear.x<<"angular"<<msg.angular.z);
		rate.sleep();
		pub.publish(msg2);
		ROS_INFO_STREAM("Sending the velocity command for angular"<<"linear"<<msg2.linear.x<<"angular"<<msg2.angular.z);
		rate.sleep();
		}

}

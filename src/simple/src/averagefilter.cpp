#include <ros/ros.h>
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include <ros/console.h>
using namespace std;

// Global variable for publishing
geometry_msgs::Pose amclPose;
geometry_msgs::Pose odom_filtPose;

void AmclCallback(geometry_msgs::PoseWithCovarianceStamped msg){
	amclPose.position.x = msg.pose.pose.position.x;
	amclPose.position.y = msg.pose.pose.position.y;
	amclPose.position.z = msg.pose.pose.position.z;
	amclPose.orientation.x = msg.pose.pose.orientation.x;
	amclPose.orientation.y = msg.pose.pose.orientation.y;
	amclPose.orientation.z = msg.pose.pose.orientation.z;
	amclPose.orientation.w = msg.pose.pose.orientation.w;
}

void OdomCallback(nav_msgs::Odometry msg){
	odom_filtPose.position.x = msg.pose.pose.position.x;
	odom_filtPose.position.y = msg.pose.pose.position.y;
	odom_filtPose.position.z = msg.pose.pose.position.z;
	odom_filtPose.orientation.x = msg.pose.pose.orientation.x;
	odom_filtPose.orientation.y = msg.pose.pose.orientation.y;
	odom_filtPose.orientation.z = msg.pose.pose.orientation.z;
	odom_filtPose.orientation.w = msg.pose.pose.orientation.w;
}

int main(int argc, char **argv){
	ros::init(argc, argv, "averagefilter");
	ros::NodeHandle nh;
	ros::Subscriber amcl_scan = nh.subscribe("amcl_pose",1000,AmclCallback);
	ros::Subscriber  odom_scan= nh.subscribe("odometry/filtered",1000,OdomCallback);
	geometry_msgs::Pose avgPose;
	ros::Publisher averagepose = nh.advertise<geometry_msgs::Pose>("averagepose", 1000);
	while(ros::ok()){		
		ros::spinOnce();
		avgPose.position.x = (amclPose.position.x + odom_filtPose.position.x)/2;
		avgPose.position.y = (amclPose.position.y + odom_filtPose.position.y)/2;
		avgPose.position.z = (amclPose.position.y + odom_filtPose.position.y)/2;	
		avgPose.orientation.x = (amclPose.orientation.x + odom_filtPose.orientation.x)/2;
		avgPose.orientation.y = (amclPose.orientation.y + odom_filtPose.orientation.y)/2;
		avgPose.orientation.z = (amclPose.orientation.z + odom_filtPose.orientation.z)/2;
		avgPose.orientation.w = (amclPose.orientation.w + odom_filtPose.orientation.w)/2;
		averagepose.publish(avgPose);
	}
}
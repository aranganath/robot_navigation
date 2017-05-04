#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <iostream>
#include <ros/console.h>
#include <array>
#include <nav_msgs/OccupancyGrid.h>
#include <unordered_map>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include <map>
#include <tf/transform_listener.h>
#include <tf/tf.h>
#include <std_msgs/Header.h>
#include <occupancy_grid_utils/shortest_path.h>
#include <occupancy_grid_utils/coordinate_conversion.h>
#include <geometry_msgs/PoseStamped.h>
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
typedef geometry_msgs gm;
using namespace std;
gm::PoseWithCovarianceStamped position;
nav_msgs::OccupancyGrid Clearance;
sensor_msgs::LaserScan obstacles;

void Map_Callback(const nav_msgs::OccupancyGrid msg){
	Clearance = msg;
	ROS_INFO("Map initialized/globalized!");
}


void Scan_Callback(const sensor_msgs::LaserScan msg){
	// Variable globalized!
	obstacles = msg;
}

void Cost_map_Callback(const gm::PoseWithCovarianceStamped msg){
	// ROS_INFO_STREAM("Size:\t"<<msg.data.size()<<"\t");
	ROS_INFO_STREAM("The coordinates of the point with respect to the map is:");
	gm::PoseStamped position;
	gm::PoseStamped new_position;
	position.pose = msg.pose.pose;
	tf::TransformListener listener;	
	// ROS_INFO_STREAM("Range_max:\t"<<msg.range_max<<endl);
	// ROS_INFO_STREAM("The range size is:\t"<<msg.ranges.size());
}	


void position_callback(const gm::PoseWithCovarianceStamped msg){
	position = msg; 
}

int main(int argc, char **argv){
	ros::init(argc, argv, "map_data");
	ros::NodeHandle nh;
	// Subscribe to scan
	
	ros::Subscriber cost_map_scan = nh.subscribe("amcl_pose",1000,Cost_map_Callback);
	ros::Subscriber sub_scan = nh.subscribe("scan",1000,Scan_Callback);
	ros::spinOnce();
	moveToGoal(4,4);	
}

bool moveToGoal(double xGoal, double yGoal){

   //define a client for to send goal requests to the move_base server through a SimpleActionClient
   MoveBaseClient ac("move_base", true);

   //wait for the action server to come up
   while(!ac.waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the move_base action server to come up");
   }

   move_base_msgs::MoveBaseGoal goal;

   //set up the frame parameters
   goal.target_pose.header.frame_id = "map";
   goal.target_pose.header.stamp = ros::Time::now();

   /* moving towards the goal*/

   goal.target_pose.pose.position.x =  xGoal;
   goal.target_pose.pose.position.y =  yGoal;
   goal.target_pose.pose.position.z =  0.0;
   goal.target_pose.pose.orientation.x = 0.0;
   goal.target_pose.pose.orientation.y = 0.0;
   goal.target_pose.pose.orientation.z = 0.0;
   goal.target_pose.pose.orientation.w = 1.0;

   ROS_INFO("Sending goal location ...");
   ROS_INFO("Checking for obstacles around (I hate the navigation stack)...");
   ac.sendGoal(goal);

   ac.waitForResult();

   if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
      ROS_INFO("You have reached the destination");
      return true;
   }
   else{
      ROS_INFO("The robot failed to reach the destination");
      return false;
   }

}
	
#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<stdlib.h>
#include"nav_msgs/Odometry.h"
#include<ros/console.h>
#include<math.h>
#include"sensor_msgs/Imu.h"

void chatterCallback(const sensor_msgs::Imu& msg)
{ 
  ROS_INFO_STREAM("Printing sensor_msgs/Imu:\n");
  ROS_INFO_STREAM("Seq: ["<<msg.header.seq<<"]");
  // ROS_INFO_STREAM("Frame_ID: ["<<msg.frame_id<<"]");  
  ROS_INFO_STREAM("Orientation-> x: ["<<msg.orientation.x<<"], y: ["<<msg.orientation.y<<"], z: ["<<msg.orientation.z<<"], w: ["<<msg.orientation.w<<"]");
  ROS_INFO_STREAM("Angular Velocity-> x: ["<<msg.angular_velocity.x<<"], y: ["<<msg.angular_velocity.y<<"], z: ["<<msg.angular_velocity.z<<"]");
  ROS_INFO_STREAM("Linear Acceleration-> x: ["<<msg.linear_acceleration.x<<"], y: ["<<msg.linear_acceleration.y<<"], z: ["<<msg.linear_acceleration.z<<"]");

}

void chattercallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  ROS_ERROR("Printing nav_msgs/Odometry:\n");
  ROS_ERROR("Seq: [%d]", msg->header.seq);
  ROS_ERROR("Position-> x: [%f], y: [%f], z: [%f]", msg->pose.pose.position.x,msg->pose.pose.position.y, msg->pose.pose.position.z);
  ROS_ERROR("Orientation-> x: [%f], y: [%f], z: [%f], w: [%f]", msg->pose.pose.orientation.x, msg->pose.pose.orientation.y, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);
  ROS_ERROR("Vel-> Linear: [%f], Angular: [%f]", msg->twist.twist.linear.x,msg->twist.twist.angular.z);
}


int main(int argc, char **argv){

        ros::init(argc, argv, "move_around");
        ros::NodeHandle nh;
        ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity",1000);
        ros::Rate rate(1);
        ros::Subscriber sub = nh.subscribe("mobile_base/sensors/imu_data",1000,chatterCallback);
        ros::Subscriber sub1 = nh.subscribe("odom",1000, chattercallback);

        geometry_msgs::Twist msg, msg2;
        while(ros::ok()){
          msg.linear.x = 2;
          msg.angular.z = 0;
          ROS_INFO_STREAM("Sending the velocity command for straight line\n"<<"linear: "<<msg.linear.x<<"\nangular "<<msg.angular.z);
          pub.publish(msg);
          rate.sleep();

          msg2.linear.x = 0;
          msg2.angular.z=M_PI/2;
          ROS_INFO_STREAM("Sending the velocity command for angular\n"<<"linear:"<<msg2.linear.x<<"\nangular: "<<msg2.angular.z);
  	      pub.publish(msg2);
  	      rate.sleep();
          ros::spinOnce();
        }
}


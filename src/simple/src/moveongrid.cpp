#include "ros/ros.h"
#include <std_msgs/Char.h>
#include <geometry_msgs/Twist.h>
#include <math.h>
#include <turtlesim/Pose.h>

class SubscribeAndPublish
{
public:
  std_msgs::Char input;
  SubscribeAndPublish()
  {
    //Topic you want to publish
    pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    pubpose = n.advertise<geometry_msgs::Twist>("/turtle1/pose", 1000);
    //Topic you want to subscribe
    subpose = n.subscribe("/turtle1/pose", 1, &SubscribeAndPublish::callbackpose, this);
    sub = n.subscribe("commands", 1, &SubscribeAndPublish::callback, this);
  }

    
    

  void callback(const std_msgs::Char& input)
      {

        geometry_msgs::Twist msg;
        if (input.data == 66)
        {
                msg.linear.x =-1.0;
                pub.publish(msg);
                ROS_INFO("The value of the information is B");
        }
        else if(input.data == 70)
        {
                msg.linear.x = 1.0;
                pub.publish(msg);
                ROS_INFO("The value of the information is F");
        }

        else if(input.data == 82)
        {
                msg.angular.z = M_PI/2;
                pub.publish(msg);
                ROS_INFO("The value of the information is R");
        }
        else if(input.data == 76)
        {
                msg.angular.z = -M_PI/2;
                pub.publish(msg);
                ROS_INFO("The value of the information is L");
        }
	      // else if(input.data == 85)
       //  {       turtlesim::Pose pose;

       //          if (pose.theta == 0){
       //              pose.theta = M_PI/2;
       //              msg.linear.x = 1;
       //              pubpose.publish(pose);
       //              callbackpose(msg);
       //              ROS_INFO("The valiue of the message is U")
       //          }
       //          else if(pose.theta == M_PI){
       //              msg.theta = -M_PI/2;
       //              pubpose.publish(pose);
       //              pub.publish(msg);
       //          }
       //          else
       //          {
       //            msg.linear.x = 1;
       //            pub.publish(msg);
       //          }
                  
                  
       //  }
	      // // else if(input.data == 85)
       //  {       turtlesim::Pose pose;

       //          if (pose.theta == 0){
       //              msg.theta = M_PI/2;
       //              msg.linear.x = 1;
       //              pubpose.publish(pose);
       //              callbackpose(msg);
       //              ROS_INFO("The valiue of the message is U")
       //          }
       //          else if(pose.theta == M_PI){
       //              msg.theta = -M_PI/2;
       //              pubpose.publish(pose);
       //              pub.publish(msg);
       //          }
       //          else
       //          {
       //            msg.linear.x = 1;
       //            pub.publish(msg);
       //          }
                  
                  
       //  }



  }
  void callbackpose(const turtlesim::Pose Pose)
  {
    geometry_msgs::Twist msg;
    if(Pose.theta == 0)
    {
      std_msgs::Char input;
      input.data = 66;
      msg.theta = M_PI/2;
      pubpose.publish(msg);
      callback(input);
    }
    else if(Pose.theta == M_PI){
      std_msgs::Char input;
      input.data = 66
    }
  }

private:
  ros::NodeHandle n;
  ros::Publisher pub;
  ros::Subscriber sub;
  ros::Subscriber subpose;
  ros::Publisher pubpose;


};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "moveongrid");

  //Create an object of class SubscribeAndPublish that will take care of everything
  SubscribeAndPublish SAPObject;
  ros::spin();

  return 0;
}
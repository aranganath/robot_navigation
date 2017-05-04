#include "ros/ros.h"
#include <std_msgs/Char.h>
#include <geometry_msgs/Twist.h>
#include <math.h>


class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    //Topic you want to publish
    pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

    //Topic you want to subscribe
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

  }

private:
  ros::NodeHandle n;
  ros::Publisher pub;
  ros::Subscriber sub;

};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "followplan");

  //Create an object of class SubscribeAndPublish that will take care of everything
  SubscribeAndPublish SAPObject;
  ros::spin();

  return 0;
}

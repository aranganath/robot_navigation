#include <ros/ros.h> 
#include <nav_msgs/GetPlan.h>
#include <math.h>

int main(int argc,char **argv) {     
	ros::init(argc,argv,"serviceclient");     
	ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<nav_msgs::GetPlan>("/move_base/make_plan");     
    client.waitForExistence();         
    nav_msgs::GetPlan plannermsg;
    plannermsg.request.start.header.frame_id = "map";
    plannermsg.request.start.pose.position.x = 0;
    plannermsg.request.start.pose.position.y = 0;
    plannermsg.request.start.pose.orientation.w = 1;
    plannermsg.request.start.header.stamp = ros::Time::now();
    plannermsg.request.goal.header.frame_id = "map";
    plannermsg.request.start.pose.position.x = 0;
    plannermsg.request.start.pose.position.y = 0;
    plannermsg.request.start.pose.orientation.z = sin(M_PI/2);
    plannermsg.request.start.pose.orientation.w = cos(M_PI/2);
    plannermsg.request.goal.header.stamp = ros::Time::now();

    if (client.call(plannermsg)) {
		ROS_INFO_STREAM("Service successfully called");
		ROS_INFO("The value of the intermediate positions is given below:\n");
		for(int i=0;i<plannermsg.response.plan.poses.size();++i){
			ROS_INFO("Iteration->%d\n",i);
			ROS_INFO("Position:\n");
			ROS_INFO("x->%f\n", plannermsg.response.plan.poses[i].pose.position.x);
			ROS_INFO("y->%f\n", plannermsg.response.plan.poses[i].pose.position.y);
			ROS_INFO("z->%f\n", plannermsg.response.plan.poses[i].pose.position.z);
			ROS_INFO("Orientation (Quaternion):\n");
			ROS_INFO("x->%f\n", plannermsg.response.plan.poses[i].pose.orientation.x);
			ROS_INFO("y->%f\n", plannermsg.response.plan.poses[i].pose.orientation.y);
			ROS_INFO("z->%f\n", plannermsg.response.plan.poses[i].pose.orientation.z);
			ROS_INFO("w->%f\n", plannermsg.response.plan.poses[i].pose.orientation.w);
		} 
		}     
    else {
		ROS_ERROR_STREAM("Error while calling service"); 
		}
    return 0; 
}
#include <ros/ros.h> 
#include <actionlib/client/simple_action_client.h> 
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/terminal_state.h>
#include <math.h>
void serviceActivated() {     
	ROS_INFO_STREAM("Service received goal"); 
	}
void serviceDone(const actionlib::SimpleClientGoalState& state, const move_base_msgs::MoveBaseResultConstPtr& result) {     
    
    ROS_INFO_STREAM("Service completed");     
    ROS_INFO_STREAM("Final state " << state.toString().c_str());     
    
}
void serviceFeedback(const move_base_msgs::MoveBaseFeedbackConstPtr& fb) {     
    ROS_INFO_STREAM("Service still running");     
    ROS_INFO_STREAM("Current pose (x,y) " <<fb->base_position.pose.position.x << "," <<fb->base_position.pose.position.y);
    } 

int main(int argc,char **argv) {     

ros::init(argc,argv,"movearoundwithfeedback");

    ros::NodeHandle nh; 
    ros::Rate rate(10);

    actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base",true);
    ROS_INFO_STREAM("Waiting for server to be available...");     
    while (!ac.waitForServer()) {     
    }     
    ROS_INFO_STREAM("done!");
    
    move_base_msgs::MoveBaseGoal goal;
    goal.target_pose.header.frame_id = "map";     
    goal.target_pose.header.stamp = ros::Time::now();         
    goal.target_pose.pose.position.x = 1;     
    goal.target_pose.pose.position.y = 1;     
    goal.target_pose.pose.orientation.w = 1.0;
    ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
    bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));
    if (finished_before_timeout){
        actionlib::SimpleClientGoalState state = ac.getState();
        ROS_INFO("Action finished: %s", state.toString().c_str());
        }
    else 
        ROS_ERROR("Action did not finish before time out!");
    rate.sleep();
    goal.target_pose.pose.position.x = 1;
    goal.target_pose.pose.position.y = 2;
    goal.target_pose.pose.orientation.z = sin(M_PI/2);
    goal.target_pose.pose.orientation.w = cos(M_PI/2);
    ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
    finished_before_timeout = ac.waitForResult(ros::Duration(30.0));
    if (finished_before_timeout){
        actionlib::SimpleClientGoalState state = ac.getState();
        ROS_INFO("Action finished: %s", state.toString().c_str());
        }
    else 
        ROS_ERROR("Action did not finish before time out!");
    rate.sleep();
    goal.target_pose.pose.position.x = 0;
    goal.target_pose.pose.position.y = 0;
    goal.target_pose.pose.orientation.z =sin(-M_PI/2);
    goal.target_pose.pose.orientation.w = cos(-M_PI/2);
    ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
    finished_before_timeout = ac.waitForResult(ros::Duration(30.0));
    if (finished_before_timeout){
        actionlib::SimpleClientGoalState state = ac.getState();
        ROS_INFO("Action finished: %s", state.toString().c_str());
        }
    else 
        ROS_ERROR("Action did not finish before time out!");
        ros::shutdown();
    rate.sleep();   
    ros::shutdown();  
    return 0;    
    }
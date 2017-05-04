#include"amcl/pf/eig3.h"
#include"ros/ros.h"
#include"geometry_msgs/PoseWithCovarianceStamped.h"

using namespace std;

void callbackMatrix(const geometry_msgs::PoseWithCovarianceStamped& Covariance){
ROS_INFO("Computing the Covariance matrix for current position\n");
ROS_INFO("Current x position is -> %f \n", Covariance.pose.pose.position.x);
ROS_INFO("Current y position is -> %f \n", Covariance.pose.pose.position.y);
ROS_INFO("Current z position is -> %f \n", Covariance.pose.pose.position.z);
ROS_INFO("Current x Quaternion orientation is -> %f \n", Covariance.pose.pose.orientation.x);
ROS_INFO("Current y Quaternion orientation is -> %f \n", Covariance.pose.pose.orientation.y);
ROS_INFO("Current z Quaternion orientation is -> %f \n", Covariance.pose.pose.orientation.z);
ROS_INFO("Computing the eigen values for the covariance of the Covariance Matrix\n");

double Covariance_required[3][3];
Covariance_required[0][0] = static_cast<double>(Covariance.pose.covariance[0]);
Covariance_required[0][1] = static_cast<double>(Covariance.pose.covariance[1]);
Covariance_required[0][2] = static_cast<double>(Covariance.pose.covariance[5]);
Covariance_required[1][0] = static_cast<double>(Covariance.pose.covariance[6]);
Covariance_required[1][1] = static_cast<double>(Covariance.pose.covariance[7]);
Covariance_required[1][2] = static_cast<double>(Covariance.pose.covariance[11]);
Covariance_required[2][0] = static_cast<double>(Covariance.pose.covariance[30]);
Covariance_required[2][1] = static_cast<double>(Covariance.pose.covariance[31]);
Covariance_required[2][2] = static_cast<double>(Covariance.pose.covariance[35]);

ROS_INFO("THE Covariance matrix is: \n");
ROS_INFO("[%f %f %f] \n", Covariance_required[0][0],Covariance_required[0][1], Covariance_required[0][2]);
ROS_INFO("[%f %f %f] \n", Covariance_required[1][0],Covariance_required[1][1], Covariance_required[1][2]);
ROS_INFO("[%f %f %f] \n", Covariance_required[2][0],Covariance_required[2][1], Covariance_required[2][2]);

double Eigen_Vector[3][3];
double Eigen_values[3];
eigen_decomposition(Covariance_required, Eigen_Vector, Eigen_values);
ROS_INFO("The eigen Vector is :\n");
ROS_INFO("The Eigen Vector 1 is:-> [ %f %f %f ]\n", Eigen_Vector[0][0], Eigen_Vector[1][0], Eigen_Vector[2][0]);
ROS_INFO("The Eigen Vector 1 is:-> [ %f %f %f ]\n", Eigen_Vector[0][1], Eigen_Vector[1][1], Eigen_Vector[2][1]);
ROS_INFO("The Eigen Vector 1 is:-> [ %f %f %f ]\n", Eigen_Vector[0][1], Eigen_Vector[1][1], Eigen_Vector[2][1]);
ROS_INFO("The Eigen values are: -> [ %f %f %f ]\n", Eigen_values[0], Eigen_values[1], Eigen_values[2]);
}

int main(int argc, char **argv){

ros::init(argc, argv, "eigens");
ros::NodeHandle n;
ros::Subscriber sub = n.subscribe("amcl_pose", 1000, callbackMatrix);
ros::spin();
return 0;
}
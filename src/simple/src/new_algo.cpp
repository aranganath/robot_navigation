#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <nav_msgs/OccupancyGrid.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include "occupancy_grid_utils/shortest_path.h"
#include "occupancy_grid_utils/coordinate_conversions.h"
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <boost/optional.hpp>
#include <sensor_msgs/LaserScan.h>
#include <iostream>
#include <math.h>
#include <sensor_msgs/PointCloud.h>
// #include <navfn/navfn.h>
// using namespace std;
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
typedef boost::optional<occupancy_grid_utils::AStarResult> AStarResult;
typedef geometry_msgs::PoseWithCovarianceStamped gmPS;
typedef geometry_msgs::Point gm;
typedef geometry_msgs::Twist navigate;
typedef nav_msgs::OccupancyGrid Occupancy;
typedef sensor_msgs::LaserScan Scan;
bool isFirst;
// typedef navfn::NavfnROS Planner;

bool check_for_obstacles(Scan ranges);
gmPS amcl_pose;
Scan scan;
Occupancy map;
// Planner planner(map.info.width, map.info.height);
// Planner plan;

// void ekf_callback(const nav_msgs::Odometry &msg);
void map_callback(const nav_msgs::OccupancyGrid &msg);
void scan_callback(const sensor_msgs::LaserScan &msg);
void amcl_callback(const geometry_msgs::PoseWithCovarianceStamped &msg);
float identitify_obstacles(Scan msg);
void point_cloud_callback(const sensor_msgs::PointCloud msg);
navigate turn_to_maximum(Scan msg);

int main(int argc, char **argv) {
    ros::init(argc, argv, "map_data");
    ros::NodeHandle nh;
    ros::Rate r(10);
    ros::Subscriber ekf_sub = nh.subscribe("/amcl_pose", 1000, &amcl_callback);
    ros::Subscriber map_sub = nh.subscribe("/map", 1000, &map_callback);
    ros::Subscriber scan_sub = nh.subscribe("/scan", 1000, &scan_callback);
    ros::Subscriber point_sub = nh.subscribe("/my_cloud",1000, &point_cloud_callback);
    
    // ros::Subscriber map_metadata_sub = nh.subscribe("/",1000, &map_metadata_sub);

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
    while(ros::ok()){
        ros::spinOnce();
        ROS_INFO("Initializing starting point");
        // plan.setNavArr(map.info.width, map.info.height);
        
        r.sleep();
        if(check_for_obstacles(scan)){
            ROS_INFO("The coast is clear! Ready to move!");
            ROS_INFO("Moving:");
            navigate nav;
            nav.linear.x = 1;
            pub.publish(nav);
        }
        else{
            ROS_INFO_STREAM("There is something interesting around!");
            ROS_INFO_STREAM("Analysing ..");
            float size = identitify_obstacles(scan);
            ROS_INFO_STREAM("Hmmm.. The size of the object seems to be of size"<<size);
            ROS_INFO_STREAM("Now turning");
            // Turn to maximum range
            
            navigate turn = turn_to_maximum(scan);
            pub.publish(turn);
            
        }
        
    }
}


void amcl_callback(const geometry_msgs::PoseWithCovarianceStamped& msg) {
    // ROS_INFO("Position is set!");
    amcl_pose = msg;
}

void map_callback(const nav_msgs::OccupancyGrid& msg) {
    // ROS_INFO("Map set!");
    map=msg;
    ROS_INFO_STREAM("The size of the map is:\t"<<msg.info.width);
}	

void scan_callback(const sensor_msgs::LaserScan& msg){
    // ROS_INFO("Laser initialized!");
    scan = msg;
    
}

bool check_for_obstacles(Scan ranges){
    bool flag=false;
    for(int i=90;i<ranges.ranges.size();++i){
        if(ranges.ranges[i]>1.5){
            flag = true;
        }
        else{
            flag=false;
            break;
        }
    }
    if(flag) return true;
    else return false;
}

float identitify_obstacles(Scan msg){
    float max_angle;
    float min_angle;
    for(int i=0;i<msg.ranges.size()/2;++i){
        if(msg.ranges[i]<1){
            min_angle = msg.ranges[i];
            break;
        }
    }
    for(int j=msg.ranges.size();j>msg.ranges.size()/2;--j){
        if(msg.ranges[j]<1){
            max_angle = msg.ranges[j];
            break;
        }
    }

    float object_size=max_angle - min_angle;
    return object_size;

}
// Check the amount by which the 
navigate turn_to_maximum(Scan msg){
    bool isFirst=true;
    navigate turn;
    float max;
    int ind;
    for(int i=0; i<msg.ranges.size();++i){
        if(isFirst){
            max=msg.ranges[i];
            ind = i; 
        }
        else if(max<msg.ranges[i]){
            max = msg.ranges[i];
            
        }
        else if(max>msg.ranges[i]||isinf(msg.ranges[i])) continue;
    }
    int iter = ind - 360;
    navigate nav;
    if(iter<0)
        nav.angular.z = msg.angle_increment * iter-0.2;
    else nav.angular.z = msg.angle_increment * iter+0.2;
    return nav;
}

void point_cloud_callback(const sensor_msgs::PointCloud msg){
    ROS_INFO_STREAM("The points of the range scan are: x->"\
        <<msg.points[1].x<<"\t"<<"y->"\
        <<msg.points[1].y);
    ROS_INFO_STREAM("The points of the range scan are: x->"\
        <<msg.points.size()<<"\t"<<"y->"\
        <<msg.points.size());

}
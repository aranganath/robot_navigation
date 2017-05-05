#include <ros/ros.h>
#include <tf/transform_datatypes.h>
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
#include <boost/shared_ptr.hpp>
#include <sensor_msgs/LaserScan.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <sensor_msgs/PointCloud.h>
#include <map>
nav_msgs::OccupancyGrid l_occ;
nav_msgs::OccupancyGrid g_occ;
occupancy_grid_utils::Cell cell;
std::vector<std::pair<geometry_msgs::Point, int>> g_map;
std::vector<std::pair<geometry_msgs::Point, int>> l_map;
geometry_msgs::PoseWithCovarianceStamped Pose;
actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base",true);
bool map_initiliazed=false;
bool flag=true;

void local_map_callback(const nav_msgs::OccupancyGrid& msg);
void global_map_callback(const nav_msgs::OccupancyGrid& msg);
bool check_map_descrepancy(geometry_msgs::Point l_it, geometry_msgs::Point g_it, int l_data, int g_data);
void amcl_callback(const geometry_msgs::PoseWithCovarianceStamped& msg);

int main(int argc, char **argv) {
    ros::init(argc, argv, "map_data");
    ros::NodeHandle nh;
    
    // Global costmap subscriber
    ros::Subscriber g_sub = nh.subscribe("/map",1000,global_map_callback);
    // Local costmap subscriber
    ros::Subscriber l_sub = nh.subscribe("/move_base/local_costmap/costmap",1000,local_map_callback);
    // Position subscriber 
    ros::Subscriber pos = nh.subscribe("/amcl_pose",1000,amcl_callback);

    while(ros::ok()){
        // Collect all the values of the map in the vector
        while(!map_initiliazed){
            ros::spinOnce();
        }
        // take in all the values of the map in the vector
        // Building the map for global
        for(std::vector<std::pair<geometry_msgs::Point, int>>::iterator g_it=g_map.begin();g_it!=g_map.end();++g_it){
            for(std::vector<std::pair<geometry_msgs::Point, int>>::iterator l_it=l_map.begin();l_it!=l_map.end();++l_it){
        
                        
                if(!check_map_descrepancy(l_it->first, g_it->first, l_it->second, g_it->second)){
                    // Navigate to point P
                    ROS_INFO_STREAM("Local map and Global map do not meet same requirements at:"<<l_it->first.x<<","<<l_it->first.y<<","<<l_it->first.z);
                    ROS_INFO_STREAM("Generating points to destination");
                    boost::optional<occupancy_grid_utils::AStarResult> gen_path=\
                    occupancy_grid_utils::shortest_path(l_map,Pose.pose.pose.position, l_it->second); 
                    label:
                    if(gen_path.is_initialized()){
                        occupancy_grid_utils::AStarResult Path=*gen_path;  
                        for(int i=0; i<Path.first.size();++i){
                            Path.push_back(occupancy_grid_utils::cellCenter(gen_path[i],l_it.info))
                        }
                    }
                    else{
                        goto label;
                    }
                    
                    while (!ac.waitForServer()){
                        ROS_INFO_STREAM("Hmmm... I thought the server was up. Strange!");
                    }
                    // Extract path between current position and destination
                    move_base_msgs::MoveBaseGoal goal;
                    goal.target_pose.header.frame_id = "map";     
                    goal.target_pose.header.stamp = ros::Time::now();         
                    goal.target_pose.pose.position.x = l_it->first.x;     
                    goal.target_pose.pose.position.y = l_it->first.y;     
                    goal.target_pose.pose.orientation.w = 1.0;
                    ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
                }
                else
                    flag = true;
                        
            }

        }
    }

}
// Setting the pse for the position of the robot
void amcl_callback(const geometry_msgs::PoseWithCovarianceStamped& msg) {
    // Initailiazing current position
    Pose = msg;
}


// Occupancy grid of the navigation map
void global_map_callback(const nav_msgs::OccupancyGrid& msg) {
    g_occ = msg;
    for(int i=0; i<msg.data.size(); ++i){

        g_map.push_back(std::make_pair(occupancy_grid_utils::cellCenter\
            (msg.info, occupancy_grid_utils::indexCell(msg.info, i)), msg.data[i]))
    }
    ROS_INFO_STREAM("Global Map initialized!")
    
}	

void local_map_callback(const nav_msgs::OccupancyGrid& msg){
    l_occ=msg;
    for(int i=0; i<msg.data.size(); ++i){
        occupancy_grid_utils::indexCell cell = ;
        l_map.push_back(std::make_pair(occupancy_grid_utils::cellCenter\
            (msg.info, occupancy_grid_utils::indexCell(msg.info, i)), msg.data[i])) ;
    }
    ROS_INFO_STREAM("Local map initialized!");

}

bool check_map_descrepancy(geometry_msgs::Point l_it, geometry_msgs::Point g_it, int l_data, int g_data){
    if(l_it.x==g_it.x && l_it.y==g_it.y){
        if(l_data == g_data)
            return true;
        else
            return false;
    }
}

// Check for the obstacles on the map
bool check_for_obstacles(Scan ranges){
    bool flag=false;
    for(int i=240;i<120+ranges.ranges.size()/2;++i){
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

// Identifying the obstacle
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
    for(int i=0; i<msg.ranges.size()/2;++i){
        if(isFirst){
            max=msg.ranges[i];
            ind = i; 
            isFirst=false;
        }
        else if(max<msg.ranges[i]){
            max = msg.ranges[i];
            ind = i;
        }
        else if(max>msg.ranges[i]||isinf(msg.ranges[i])) continue;
    }
    int iter = ind - 360;
    navigate nav;
    nav.angular.z = -0.1;
    return nav;
}

// point cloud
void point_cloud_callback(const sensor_msgs::PointCloud msg){

    cloud = msg;
    for(int i=0; i<msg.points.size();++i){
        ROS_INFO_STREAM("The distance between the robot and the obstacle is:"\
            <<sqrt(pow(msg.points[i].x-amcl_pose.pose.pose.position.x,2)\
                +pow(msg.points[i].y-amcl_pose.pose.pose.position.x,2)));
    }

}
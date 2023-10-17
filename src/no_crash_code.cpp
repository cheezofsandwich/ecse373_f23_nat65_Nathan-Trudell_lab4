#include <sensor_msgs/LaserScan.h>
#include <ros/ros.h>
#include "geometry_msgs/Twist.h"


    geometry_msgs::Twist output_msg;
    geometry_msgs::Twist input_msg;
    sensor_msgs::LaserScan lidar_msg;

    int lidar_input=0;
    ros::Publisher cmd_vel;
    
    



void veloCallback(const geometry_msgs::Twist msg){

    if(lidar_input==1){
	    ROS_INFO("velocityCallback");
	    float x = msg.linear.x;

	    if(x>0){
		int i = lidar_msg.ranges.size()/2;
		float dist_away = lidar_msg.ranges[i];
		ROS_INFO("%f",dist_away);
		if(dist_away > 1){
		    cmd_vel.publish(msg);
		}
		else{
		    ROS_INFO("Wall Nearby");
		    output_msg = msg;
		    output_msg.linear.x=0;
		    cmd_vel.publish(output_msg);
		}
	    }
	    else{
	    cmd_vel.publish(msg);
	    }
    }
}
    
void lidarCallback(const sensor_msgs::LaserScan msg){
    lidar_input = 1;
    lidar_msg=msg;
}



int main(int argc, char* argv[]) {
    double wall_dist = 1.0;

    ROS_INFO("no_crash_node starting");
    

    ros::init(argc, argv, "robot_no_crash"); 
    ros::NodeHandle n;
    
    cmd_vel = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
    
    ros::Subscriber des_vel = n.subscribe<geometry_msgs::Twist>("des_vel", 1000, veloCallback);
    ros::Subscriber lidar_op = n.subscribe<sensor_msgs::LaserScan>("laser_1", 1000,lidarCallback);


    ROS_INFO_ONCE("wall_dist began with: [%2.2f]", wall_dist);
    

    if (n.getParamCached("wall_dist", wall_dist)) {
    	ROS_INFO("wall_dist was updated to: [%2.2f]", wall_dist);
    }
    
    ROS_INFO_ONCE("wall_dist is now: [%2.2f]", wall_dist);
    
    
    
    ros::spin();
}

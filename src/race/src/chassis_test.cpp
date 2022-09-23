#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <iostream>
#include <math.h>
#include <vector>


int main(int argc, char **argv)
{
    ros::init(argc, argv, "chassis_test");
    ros::NodeHandle nh;
    ros::Publisher vel_pub;
    vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
    
    float vx,vy,vw;
    geometry_msgs::Twist vel;
    while (ros::ok())
    { 
        std::cout<<"vx vy vw:\n";
        std::cin>>vx>>vy>>vw;
        vel.linear.x = vx;
        vel.linear.y = vy;
        vel.angular.z = vw;
        vel_pub.publish(vel);
    }
    ros::spinOnce();
}

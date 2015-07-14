#include <ros/ros.h>
#include <math.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Twist.h>
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"
#include <geometry_msgs/Quaternion.h>
#include "ardrone_autonomy/Navdata.h"

ros::Publisher cmdpub;
ros::Subscriber pointin;
ros::Subscriber pointnav;

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float linearx(float dist){
if(dist>=2000 && dist<=3500){
return(0);
}
else if(dist>3500){
return(-0.1);
}
else
{
return(0.1);
}
}

float angularz(float cain){
float c1=160-cain;
float c2=map(c1, 0, 160, 0, 5);
if(c2>=-0.3 && c2<=0.3)
{
float c3=c2;
return(c3);
}
else if(c2<-0.3)
{
return(-0.3);
}
else{
return(0.3);
}}

float linearz(int clin){
float c4=120-clin;
float c5=map(c4, 0, 120, 0, 5);
if(c5>=-0.3 && c5<=0.3){
float c6=c5;
return(c6);
}
else if(c5<-0.3){
return(-0.3);
}
else
{
return(0.3);
}
}



void pointvalue(const geometry_msgs::Quaternion::ConstPtr& msgA)
{
float m,n,o,p,x,z;

 m= msgA->x;
 n= msgA->y; 
 o= msgA->z;
 p= msgA->w;

float width=fabs(m-o), height=fabs(n-p);
float cx=(m+o)/2, cy=(n+p)/2;
float area=width*height;
ROS_INFO("area=%f", area);
float fc1=160, fc2=120;

if(area!=area){
ROS_INFO("Object Lost!! Panic Mode!!");
geometry_msgs::TwistPtr cmd(new geometry_msgs::Twist());
 cmd->linear.x = 0;    
 cmd->angular.z = 0;
 cmd->linear.z = 0;
 cmdpub.publish(cmd);
ROS_INFO("x=%f y=%f z=%f", cmd->linear.x, cmd->angular.z, cmd->linear.z);
}

else{
geometry_msgs::TwistPtr cmd(new geometry_msgs::Twist());
 cmd->linear.x = linearx(area);    
 cmd->angular.z = angularz(cx);     	
 cmd->linear.z = linearz(cy);
 cmdpub.publish(cmd); 
 ROS_INFO("x=%f y=%f z=%f", cmd->linear.x, cmd->angular.z, cmd->linear.z);
}
}



int main(int argc, char** argv)
{
ros::init(argc, argv, "listener");
ros::NodeHandle n;
cmdpub = n.advertise<geometry_msgs::Twist> ("/cmd_vel", 1);
pointin = n.subscribe("pointA", 1, pointvalue);
ros::spin();
return 0;
}

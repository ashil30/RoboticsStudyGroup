//These are the header files called in this function
//This piece of code is similar to the teleop_turtle in operating the simple_arm robot 
#include <ros/ros.h>
#include "std_msgs/Float64.h"
#include <signal.h>
#include <termios.h>
#include <stdio.h>

//Keys mapped with define and the turnvalue is also set 
#define KEYCODE_R 0x43 
#define KEYCODE_L 0x44
#define KEYCODE_U 0x41
#define KEYCODE_D 0x42
#define KEYCODE_Q 0x71
#define TURNVALUE 0.1

class KeyController
{
public:
  void keyLoop();

private:

  //Every node has a NodeHandle in ros
  ros::NodeHandle nh_;
  ros::Publisher link1_;
  ros::Publisher link2_;
  
};

//This is used to take commands from the terminal 
int kfd = 0;
struct termios cooked, raw;

void quit(int sig)
{
  (void)sig;
  tcsetattr(kfd, TCSANOW, &cooked);
  ros::shutdown();
  exit(0);
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "key_controller");
  KeyController key_controller;

  //Its an interrupt based service
  signal(SIGINT,quit);

  key_controller.keyLoop();
  
  return(0);
}


void KeyController::keyLoop()
{
  //character and dirty bit defined
  //if c has a value, dirty is true and the message is published to topic
  char c;
  bool dirty=false;

  //link1 and link2 are the two joints in the simple arm robot 
  //The topic are published to them by advertised
  ros::Publisher link1_ = nh_.advertise<std_msgs::Float64>("/simple_arm/joint_1_position_controller/command",10);
  ros::Publisher link2_ = nh_.advertise<std_msgs::Float64>("/simple_arm/joint_2_position_controller/command",10);



  // get the console in raw mode                                                              
  tcgetattr(kfd, &cooked);
  memcpy(&raw, &cooked, sizeof(struct termios));
  raw.c_lflag &=~ (ICANON | ECHO);
  // Setting a new line, then end of file                         
  raw.c_cc[VEOL] = 1;
  raw.c_cc[VEOF] = 2;
  tcsetattr(kfd, TCSANOW, &raw);

  puts("Reading from keyboard");
  puts("---------------------------");
  puts("Use arrow keys to move the simple arm robot.");

  std_msgs::Float64 msg;
  std_msgs::Float64 nmsg;
  nmsg.data=0;
  msg.data=0;


  for(;;)
  {
    // get the next event from the keyboard  
    if(read(kfd, &c, 1) < 0)
    {
      perror("read():");
      exit(-1);
    }

    ROS_DEBUG("value: 0x%02X\n", c);
  
    switch(c)
    {
      case KEYCODE_L:
        ROS_DEBUG("LEFT");
        msg.data = msg.data + TURNVALUE;
        dirty = true;
        break;
      case KEYCODE_R:
        ROS_DEBUG("RIGHT");
        msg.data = msg.data - TURNVALUE;
        dirty = true;
        break;
      case KEYCODE_U:
        ROS_DEBUG("UP");
        nmsg.data = nmsg.data + TURNVALUE;
        dirty = true;
        break;
      case KEYCODE_D:
        ROS_DEBUG("DOWN");
        nmsg.data = nmsg.data - TURNVALUE;
        dirty = true;
        break;
    }
   

    //condition checked for sending
    if(dirty ==true)
    {
      //publishing step happens over here
      //changes in the simple arm robots movements can be seen
      link1_.publish(msg);
      link2_.publish(nmsg);
      dirty=false;
    }
  }


  return;
}


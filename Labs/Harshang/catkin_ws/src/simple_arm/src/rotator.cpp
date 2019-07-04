#include "ros/ros.h"
#include "std_msgs/Float64.h"

//To control the script from command line
int main(int argc, char **argv)
{
    //initialize ros node, every node has a NodeHandle
    ros::init(argc, argv, "rotator");
    ros::NodeHandle n;

    //Publisher used to publish and advertised by NodeHandle
    ros::Publisher rotation_pub = n.advertise<std_msgs::Float64>("/simple_arm/joint_1_position_controller/command",1000);

    ros::Rate loop_rate(1);

    //The loop for the program to run indefinitely
    float count = 0;
    while(ros::ok())
    {
        //the message type defined, the same that the bot has subscribed to
        std_msgs::Float64 msg;

        msg.data = count;
        ROS_INFO("%f",count);

        //Actual message published with this line
        rotation_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();

        count = count + 0.25;
    }

    return 0;
}

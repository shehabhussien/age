#include <ros/ros.h>
#include <custom_msgs/DateMsg.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "date_publisher");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<custom_msgs::DateMsg>("date_topic", 10);
    ros::Rate rate(1);  // 1 Hz publishing rate

    while (ros::ok())
    {
        custom_msgs::DateMsg date_msg;
        date_msg.day = "28";
        date_msg.month = "may";
        date_msg.year = "2000";
        pub.publish(date_msg);
        ROS_INFO("Published date: %s %s, %s", date_msg.month.c_str(), date_msg.day.c_str(), date_msg.year.c_str());
        rate.sleep();
    }

    return 0;
}
```

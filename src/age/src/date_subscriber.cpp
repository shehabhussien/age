#include <ros/ros.h>
#include <custom_msgs/DateMsg.h>

void dateCallback(const custom_msgs::DateMsg::ConstPtr& msg)
{
    ROS_INFO("Received date: %s %s, %s", msg->month.c_str(), msg->day.c_str(), msg->year.c_str());
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "date_subscriber");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("date_topic", 10, dateCallback);

    ros::spin();

    return 0;
}
```

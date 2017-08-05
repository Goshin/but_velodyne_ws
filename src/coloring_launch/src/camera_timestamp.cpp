#include "ros/ros.h"
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/Image.h>
#include <string>

ros::Publisher image_pub;
ros::Publisher info_pub;

void onImageDataReceivedCallback(const sensor_msgs::Image::ConstPtr &msg) {
    if (ros::ok()) {
        sensor_msgs::Image newMsg(*msg);
        newMsg.header.stamp = ros::Time::now();
        image_pub.publish(newMsg);
    }
}

void onCameraInfoDataReceivedCallback(const sensor_msgs::CameraInfo::ConstPtr &msg) {
    if (ros::ok()) {
        sensor_msgs::CameraInfo newMsg(*msg);
        newMsg.header.stamp = ros::Time::now();
        info_pub.publish(newMsg);
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "camera_timestamp");

    ros::NodeHandle n;
    ros::Subscriber image_sub = n.subscribe("image_raw", 1000, onImageDataReceivedCallback);
    image_pub = n.advertise<sensor_msgs::Image>("/camera_timestamp/image_raw", 1000);

    ros::Subscriber info_sub = n.subscribe("camera_info", 1000, onCameraInfoDataReceivedCallback);
    info_pub = n.advertise<sensor_msgs::CameraInfo>("/camera_timestamp/camera_info", 1000);

    ros::spin();

    return 0;
}

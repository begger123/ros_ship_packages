#ifndef PCL_OBJECT_RECOGNITION_H_INCLUDED
#define PCL_OBJECT_RECOGNITION_H_INCLUDED

//headers in this package
#include <object_model.h>

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

//headers in pcl
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/impl/point_types.hpp>

class pcl_object_recognition
{
public:
  pcl_object_recognition();
  ~pcl_object_recognition();
private:
  ros::NodeHandle nh_;
  ros::Subscriber pointcloud_sub_;
  std::string stl_file_path_;
  pcl::PointCloud<pcl::PointXYZ>::Ptr object_pointcloud_;
  void pointcloud_callback(sensor_msgs::PointCloud2 input_cloud);
  inline bool check_file_existence(std::string& str);
  object_model* object_model_;
  object_model* scene_model_;
  bool use_hough_;
};

#endif
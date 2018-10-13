//
// Created by jalim on 29.08.18.
//

#ifndef TRAJECTORY_PUBLISHER_TRAJECTORY_H
#define TRAJECTORY_PUBLISHER_TRAJECTORY_H

#include <Eigen/Dense>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>

#define TRAJ_ZERO 0
#define TRAJ_POLYNOMIAL 1
#define TRAJ_CIRCLE 2
#define TRAJ_LAMNISCATE 3


class trajectory {
  private:
    int N; //Degree of polynomial
    double dt_; //Sampling time
    double T_;
    int type_;
    int target_trajectoryID_;
    Eigen::Vector4d c_x_, c_y_, c_z_; //Coefficients for polynomial representation
    Eigen::Vector3d traj_axis_;
    Eigen::Vector3d traj_origin_;
    double traj_radius_, traj_omega_;

  public:
    trajectory();
    ~trajectory();
    virtual void generatePrimitives(Eigen::Vector3d pos) = 0;
    virtual void generatePrimitives(Eigen::Vector3d pos, Eigen::Vector3d vel) = 0;
    virtual void generatePrimitives(Eigen::Vector3d pos, Eigen::Vector3d vel, Eigen::Vector3d jerk) = 0;
    virtual void generatePrimitives(Eigen::Vector3d pos, Eigen::Vector3d vel, Eigen::Vector3d acc, Eigen::Vector3d jerk) = 0;
    virtual Eigen::Vector3d getPosition(double time) = 0;
    virtual Eigen::Vector3d getVelocity(double time) = 0;
    double getsamplingTime(){return dt_;};
    double getDuration(){ return T_;};
    nav_msgs::Path getSegment();
    geometry_msgs::PoseStamped vector3d2PoseStampedMsg(Eigen::Vector3d position, Eigen::Vector4d orientation);

};


#endif //TRAJECTORY_PUBLISHER_TRAJECTORY_H

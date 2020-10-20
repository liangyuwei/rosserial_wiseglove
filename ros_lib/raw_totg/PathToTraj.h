#ifndef _ROS_SERVICE_PathToTraj_h
#define _ROS_SERVICE_PathToTraj_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectoryPoint.h"

namespace raw_totg
{

static const char PATHTOTRAJ[] = "raw_totg/PathToTraj";

  class PathToTrajRequest : public ros::Msg
  {
    public:
      uint32_t path_length;
      typedef trajectory_msgs::JointTrajectoryPoint _path_type;
      _path_type st_path;
      _path_type * path;
      uint32_t vel_limits_length;
      typedef double _vel_limits_type;
      _vel_limits_type st_vel_limits;
      _vel_limits_type * vel_limits;
      uint32_t acc_limits_length;
      typedef double _acc_limits_type;
      _acc_limits_type st_acc_limits;
      _acc_limits_type * acc_limits;
      typedef double _timestep_type;
      _timestep_type timestep;

    PathToTrajRequest():
      path_length(0), path(NULL),
      vel_limits_length(0), vel_limits(NULL),
      acc_limits_length(0), acc_limits(NULL),
      timestep(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->path_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->path_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->path_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->path_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->path_length);
      for( uint32_t i = 0; i < path_length; i++){
      offset += this->path[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->vel_limits_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vel_limits_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vel_limits_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vel_limits_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel_limits_length);
      for( uint32_t i = 0; i < vel_limits_length; i++){
      union {
        double real;
        uint64_t base;
      } u_vel_limitsi;
      u_vel_limitsi.real = this->vel_limits[i];
      *(outbuffer + offset + 0) = (u_vel_limitsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vel_limitsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vel_limitsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vel_limitsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vel_limitsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vel_limitsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vel_limitsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vel_limitsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vel_limits[i]);
      }
      *(outbuffer + offset + 0) = (this->acc_limits_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->acc_limits_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->acc_limits_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->acc_limits_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acc_limits_length);
      for( uint32_t i = 0; i < acc_limits_length; i++){
      union {
        double real;
        uint64_t base;
      } u_acc_limitsi;
      u_acc_limitsi.real = this->acc_limits[i];
      *(outbuffer + offset + 0) = (u_acc_limitsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_limitsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acc_limitsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acc_limitsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_acc_limitsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_acc_limitsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_acc_limitsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_acc_limitsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->acc_limits[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_timestep;
      u_timestep.real = this->timestep;
      *(outbuffer + offset + 0) = (u_timestep.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timestep.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timestep.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timestep.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_timestep.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_timestep.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_timestep.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_timestep.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->timestep);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t path_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      path_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->path_length);
      if(path_lengthT > path_length)
        this->path = (trajectory_msgs::JointTrajectoryPoint*)realloc(this->path, path_lengthT * sizeof(trajectory_msgs::JointTrajectoryPoint));
      path_length = path_lengthT;
      for( uint32_t i = 0; i < path_length; i++){
      offset += this->st_path.deserialize(inbuffer + offset);
        memcpy( &(this->path[i]), &(this->st_path), sizeof(trajectory_msgs::JointTrajectoryPoint));
      }
      uint32_t vel_limits_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vel_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vel_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vel_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vel_limits_length);
      if(vel_limits_lengthT > vel_limits_length)
        this->vel_limits = (double*)realloc(this->vel_limits, vel_limits_lengthT * sizeof(double));
      vel_limits_length = vel_limits_lengthT;
      for( uint32_t i = 0; i < vel_limits_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_vel_limits;
      u_st_vel_limits.base = 0;
      u_st_vel_limits.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_vel_limits.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_vel_limits.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_vel_limits.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_vel_limits.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_vel_limits.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_vel_limits.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_vel_limits.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_vel_limits = u_st_vel_limits.real;
      offset += sizeof(this->st_vel_limits);
        memcpy( &(this->vel_limits[i]), &(this->st_vel_limits), sizeof(double));
      }
      uint32_t acc_limits_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      acc_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      acc_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      acc_limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->acc_limits_length);
      if(acc_limits_lengthT > acc_limits_length)
        this->acc_limits = (double*)realloc(this->acc_limits, acc_limits_lengthT * sizeof(double));
      acc_limits_length = acc_limits_lengthT;
      for( uint32_t i = 0; i < acc_limits_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_acc_limits;
      u_st_acc_limits.base = 0;
      u_st_acc_limits.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_acc_limits.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_acc_limits.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_acc_limits.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_acc_limits.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_acc_limits.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_acc_limits.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_acc_limits.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_acc_limits = u_st_acc_limits.real;
      offset += sizeof(this->st_acc_limits);
        memcpy( &(this->acc_limits[i]), &(this->st_acc_limits), sizeof(double));
      }
      union {
        double real;
        uint64_t base;
      } u_timestep;
      u_timestep.base = 0;
      u_timestep.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timestep.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timestep.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timestep.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_timestep.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_timestep.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_timestep.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_timestep.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->timestep = u_timestep.real;
      offset += sizeof(this->timestep);
     return offset;
    }

    const char * getType(){ return PATHTOTRAJ; };
    const char * getMD5(){ return "116341b0d0f4e460f01ed35537b618e2"; };

  };

  class PathToTrajResponse : public ros::Msg
  {
    public:
      uint32_t traj_length;
      typedef trajectory_msgs::JointTrajectoryPoint _traj_type;
      _traj_type st_traj;
      _traj_type * traj;

    PathToTrajResponse():
      traj_length(0), traj(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->traj_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->traj_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->traj_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->traj_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->traj_length);
      for( uint32_t i = 0; i < traj_length; i++){
      offset += this->traj[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t traj_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      traj_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      traj_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      traj_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->traj_length);
      if(traj_lengthT > traj_length)
        this->traj = (trajectory_msgs::JointTrajectoryPoint*)realloc(this->traj, traj_lengthT * sizeof(trajectory_msgs::JointTrajectoryPoint));
      traj_length = traj_lengthT;
      for( uint32_t i = 0; i < traj_length; i++){
      offset += this->st_traj.deserialize(inbuffer + offset);
        memcpy( &(this->traj[i]), &(this->st_traj), sizeof(trajectory_msgs::JointTrajectoryPoint));
      }
     return offset;
    }

    const char * getType(){ return PATHTOTRAJ; };
    const char * getMD5(){ return "ef5c3cd15ddaa2a59a50610b9a2a484e"; };

  };

  class PathToTraj {
    public:
    typedef PathToTrajRequest Request;
    typedef PathToTrajResponse Response;
  };

}
#endif

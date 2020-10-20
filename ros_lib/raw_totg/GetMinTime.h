#ifndef _ROS_SERVICE_GetMinTime_h
#define _ROS_SERVICE_GetMinTime_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectoryPoint.h"

namespace raw_totg
{

static const char GETMINTIME[] = "raw_totg/GetMinTime";

  class GetMinTimeRequest : public ros::Msg
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

    GetMinTimeRequest():
      path_length(0), path(NULL),
      vel_limits_length(0), vel_limits(NULL),
      acc_limits_length(0), acc_limits(NULL)
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
     return offset;
    }

    const char * getType(){ return GETMINTIME; };
    const char * getMD5(){ return "1c41becb793b04d72f4e8f74c95dd373"; };

  };

  class GetMinTimeResponse : public ros::Msg
  {
    public:
      typedef double _min_time_type;
      _min_time_type min_time;

    GetMinTimeResponse():
      min_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_min_time;
      u_min_time.real = this->min_time;
      *(outbuffer + offset + 0) = (u_min_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_min_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_min_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_min_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_min_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->min_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_min_time;
      u_min_time.base = 0;
      u_min_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_min_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_min_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_min_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_min_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->min_time = u_min_time.real;
      offset += sizeof(this->min_time);
     return offset;
    }

    const char * getType(){ return GETMINTIME; };
    const char * getMD5(){ return "6dce3946548ff93d5b598d258daca856"; };

  };

  class GetMinTime {
    public:
    typedef GetMinTimeRequest Request;
    typedef GetMinTimeResponse Response;
  };

}
#endif

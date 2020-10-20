#ifndef _ROS_SERVICE_JntToCart_h
#define _ROS_SERVICE_JntToCart_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectoryPoint.h"
#include "geometry_msgs/Pose.h"

namespace dual_ur5_control
{

static const char JNTTOCART[] = "dual_ur5_control/JntToCart";

  class JntToCartRequest : public ros::Msg
  {
    public:
      typedef bool _left_or_right_type;
      _left_or_right_type left_or_right;
      uint32_t joint_trajectory_length;
      typedef trajectory_msgs::JointTrajectoryPoint _joint_trajectory_type;
      _joint_trajectory_type st_joint_trajectory;
      _joint_trajectory_type * joint_trajectory;

    JntToCartRequest():
      left_or_right(0),
      joint_trajectory_length(0), joint_trajectory(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_left_or_right;
      u_left_or_right.real = this->left_or_right;
      *(outbuffer + offset + 0) = (u_left_or_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_or_right);
      *(outbuffer + offset + 0) = (this->joint_trajectory_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_trajectory_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_trajectory_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_trajectory_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joint_trajectory_length);
      for( uint32_t i = 0; i < joint_trajectory_length; i++){
      offset += this->joint_trajectory[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_left_or_right;
      u_left_or_right.base = 0;
      u_left_or_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->left_or_right = u_left_or_right.real;
      offset += sizeof(this->left_or_right);
      uint32_t joint_trajectory_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->joint_trajectory_length);
      if(joint_trajectory_lengthT > joint_trajectory_length)
        this->joint_trajectory = (trajectory_msgs::JointTrajectoryPoint*)realloc(this->joint_trajectory, joint_trajectory_lengthT * sizeof(trajectory_msgs::JointTrajectoryPoint));
      joint_trajectory_length = joint_trajectory_lengthT;
      for( uint32_t i = 0; i < joint_trajectory_length; i++){
      offset += this->st_joint_trajectory.deserialize(inbuffer + offset);
        memcpy( &(this->joint_trajectory[i]), &(this->st_joint_trajectory), sizeof(trajectory_msgs::JointTrajectoryPoint));
      }
     return offset;
    }

    const char * getType(){ return JNTTOCART; };
    const char * getMD5(){ return "f59c45063e72d21ceb5b7cecba560816"; };

  };

  class JntToCartResponse : public ros::Msg
  {
    public:
      uint32_t cart_trajectory_length;
      typedef geometry_msgs::Pose _cart_trajectory_type;
      _cart_trajectory_type st_cart_trajectory;
      _cart_trajectory_type * cart_trajectory;

    JntToCartResponse():
      cart_trajectory_length(0), cart_trajectory(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->cart_trajectory_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cart_trajectory_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cart_trajectory_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cart_trajectory_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cart_trajectory_length);
      for( uint32_t i = 0; i < cart_trajectory_length; i++){
      offset += this->cart_trajectory[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t cart_trajectory_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cart_trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cart_trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cart_trajectory_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cart_trajectory_length);
      if(cart_trajectory_lengthT > cart_trajectory_length)
        this->cart_trajectory = (geometry_msgs::Pose*)realloc(this->cart_trajectory, cart_trajectory_lengthT * sizeof(geometry_msgs::Pose));
      cart_trajectory_length = cart_trajectory_lengthT;
      for( uint32_t i = 0; i < cart_trajectory_length; i++){
      offset += this->st_cart_trajectory.deserialize(inbuffer + offset);
        memcpy( &(this->cart_trajectory[i]), &(this->st_cart_trajectory), sizeof(geometry_msgs::Pose));
      }
     return offset;
    }

    const char * getType(){ return JNTTOCART; };
    const char * getMD5(){ return "08cef56f1abdd7b4afb20686ed7f193d"; };

  };

  class JntToCart {
    public:
    typedef JntToCartRequest Request;
    typedef JntToCartResponse Response;
  };

}
#endif

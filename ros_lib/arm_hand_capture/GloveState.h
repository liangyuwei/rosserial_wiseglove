#ifndef _ROS_arm_hand_capture_GloveState_h
#define _ROS_arm_hand_capture_GloveState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace arm_hand_capture
{

  class GloveState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t left_glove_state_length;
      typedef double _left_glove_state_type;
      _left_glove_state_type st_left_glove_state;
      _left_glove_state_type * left_glove_state;
      uint32_t right_glove_state_length;
      typedef double _right_glove_state_type;
      _right_glove_state_type st_right_glove_state;
      _right_glove_state_type * right_glove_state;
      uint32_t l_glove_elec_length;
      typedef uint64_t _l_glove_elec_type;
      _l_glove_elec_type st_l_glove_elec;
      _l_glove_elec_type * l_glove_elec;
      uint32_t r_glove_elec_length;
      typedef uint64_t _r_glove_elec_type;
      _r_glove_elec_type st_r_glove_elec;
      _r_glove_elec_type * r_glove_elec;

    GloveState():
      header(),
      left_glove_state_length(0), left_glove_state(NULL),
      right_glove_state_length(0), right_glove_state(NULL),
      l_glove_elec_length(0), l_glove_elec(NULL),
      r_glove_elec_length(0), r_glove_elec(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->left_glove_state_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->left_glove_state_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->left_glove_state_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->left_glove_state_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_glove_state_length);
      for( uint32_t i = 0; i < left_glove_state_length; i++){
      union {
        double real;
        uint64_t base;
      } u_left_glove_statei;
      u_left_glove_statei.real = this->left_glove_state[i];
      *(outbuffer + offset + 0) = (u_left_glove_statei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_glove_statei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_glove_statei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_glove_statei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_left_glove_statei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_left_glove_statei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_left_glove_statei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_left_glove_statei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->left_glove_state[i]);
      }
      *(outbuffer + offset + 0) = (this->right_glove_state_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->right_glove_state_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->right_glove_state_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->right_glove_state_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_glove_state_length);
      for( uint32_t i = 0; i < right_glove_state_length; i++){
      union {
        double real;
        uint64_t base;
      } u_right_glove_statei;
      u_right_glove_statei.real = this->right_glove_state[i];
      *(outbuffer + offset + 0) = (u_right_glove_statei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_glove_statei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_glove_statei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_glove_statei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_right_glove_statei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_right_glove_statei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_right_glove_statei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_right_glove_statei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->right_glove_state[i]);
      }
      *(outbuffer + offset + 0) = (this->l_glove_elec_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->l_glove_elec_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->l_glove_elec_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->l_glove_elec_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->l_glove_elec_length);
      for( uint32_t i = 0; i < l_glove_elec_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_l_glove_eleci;
      u_l_glove_eleci.real = this->l_glove_elec[i];
      *(outbuffer + offset + 0) = (u_l_glove_eleci.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_l_glove_eleci.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_l_glove_eleci.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_l_glove_eleci.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->l_glove_elec[i]);
      }
      *(outbuffer + offset + 0) = (this->r_glove_elec_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->r_glove_elec_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->r_glove_elec_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->r_glove_elec_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->r_glove_elec_length);
      for( uint32_t i = 0; i < r_glove_elec_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_r_glove_eleci;
      u_r_glove_eleci.real = this->r_glove_elec[i];
      *(outbuffer + offset + 0) = (u_r_glove_eleci.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_r_glove_eleci.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_r_glove_eleci.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_r_glove_eleci.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->r_glove_elec[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t left_glove_state_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      left_glove_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      left_glove_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      left_glove_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->left_glove_state_length);
      if(left_glove_state_lengthT > left_glove_state_length)
        this->left_glove_state = (double*)realloc(this->left_glove_state, left_glove_state_lengthT * sizeof(double));
      left_glove_state_length = left_glove_state_lengthT;
      for( uint32_t i = 0; i < left_glove_state_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_left_glove_state;
      u_st_left_glove_state.base = 0;
      u_st_left_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_left_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_left_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_left_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_left_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_left_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_left_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_left_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_left_glove_state = u_st_left_glove_state.real;
      offset += sizeof(this->st_left_glove_state);
        memcpy( &(this->left_glove_state[i]), &(this->st_left_glove_state), sizeof(double));
      }
      uint32_t right_glove_state_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      right_glove_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      right_glove_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      right_glove_state_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->right_glove_state_length);
      if(right_glove_state_lengthT > right_glove_state_length)
        this->right_glove_state = (double*)realloc(this->right_glove_state, right_glove_state_lengthT * sizeof(double));
      right_glove_state_length = right_glove_state_lengthT;
      for( uint32_t i = 0; i < right_glove_state_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_right_glove_state;
      u_st_right_glove_state.base = 0;
      u_st_right_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_right_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_right_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_right_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_right_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_right_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_right_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_right_glove_state.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_right_glove_state = u_st_right_glove_state.real;
      offset += sizeof(this->st_right_glove_state);
        memcpy( &(this->right_glove_state[i]), &(this->st_right_glove_state), sizeof(double));
      }
      uint32_t l_glove_elec_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      l_glove_elec_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      l_glove_elec_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      l_glove_elec_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->l_glove_elec_length);
      if(l_glove_elec_lengthT > l_glove_elec_length)
        this->l_glove_elec = (uint64_t*)realloc(this->l_glove_elec, l_glove_elec_lengthT * sizeof(uint64_t));
      l_glove_elec_length = l_glove_elec_lengthT;
      for( uint32_t i = 0; i < l_glove_elec_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_st_l_glove_elec;
      u_st_l_glove_elec.base = 0;
      u_st_l_glove_elec.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_l_glove_elec.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_l_glove_elec.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_l_glove_elec.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_l_glove_elec = u_st_l_glove_elec.real;
      offset += sizeof(this->st_l_glove_elec);
        memcpy( &(this->l_glove_elec[i]), &(this->st_l_glove_elec), sizeof(uint64_t));
      }
      uint32_t r_glove_elec_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      r_glove_elec_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      r_glove_elec_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      r_glove_elec_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->r_glove_elec_length);
      if(r_glove_elec_lengthT > r_glove_elec_length)
        this->r_glove_elec = (uint64_t*)realloc(this->r_glove_elec, r_glove_elec_lengthT * sizeof(uint64_t));
      r_glove_elec_length = r_glove_elec_lengthT;
      for( uint32_t i = 0; i < r_glove_elec_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_st_r_glove_elec;
      u_st_r_glove_elec.base = 0;
      u_st_r_glove_elec.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_r_glove_elec.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_r_glove_elec.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_r_glove_elec.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_r_glove_elec = u_st_r_glove_elec.real;
      offset += sizeof(this->st_r_glove_elec);
        memcpy( &(this->r_glove_elec[i]), &(this->st_r_glove_elec), sizeof(uint64_t));
      }
     return offset;
    }

    const char * getType(){ return "arm_hand_capture/GloveState"; };
    const char * getMD5(){ return "621feaac88150c52f12018aa8ce8e617"; };

  };

}
#endif
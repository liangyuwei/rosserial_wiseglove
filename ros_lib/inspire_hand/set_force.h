#ifndef _ROS_SERVICE_set_force_h
#define _ROS_SERVICE_set_force_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char SET_FORCE[] = "inspire_hand/set_force";

  class set_forceRequest : public ros::Msg
  {
    public:
      typedef int32_t _force0_type;
      _force0_type force0;
      typedef int32_t _force1_type;
      _force1_type force1;
      typedef int32_t _force2_type;
      _force2_type force2;
      typedef int32_t _force3_type;
      _force3_type force3;
      typedef int32_t _force4_type;
      _force4_type force4;
      typedef int32_t _force5_type;
      _force5_type force5;

    set_forceRequest():
      force0(0),
      force1(0),
      force2(0),
      force3(0),
      force4(0),
      force5(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_force0;
      u_force0.real = this->force0;
      *(outbuffer + offset + 0) = (u_force0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_force0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_force0.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force0);
      union {
        int32_t real;
        uint32_t base;
      } u_force1;
      u_force1.real = this->force1;
      *(outbuffer + offset + 0) = (u_force1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_force1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_force1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force1);
      union {
        int32_t real;
        uint32_t base;
      } u_force2;
      u_force2.real = this->force2;
      *(outbuffer + offset + 0) = (u_force2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_force2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_force2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force2);
      union {
        int32_t real;
        uint32_t base;
      } u_force3;
      u_force3.real = this->force3;
      *(outbuffer + offset + 0) = (u_force3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_force3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_force3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force3);
      union {
        int32_t real;
        uint32_t base;
      } u_force4;
      u_force4.real = this->force4;
      *(outbuffer + offset + 0) = (u_force4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_force4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_force4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force4);
      union {
        int32_t real;
        uint32_t base;
      } u_force5;
      u_force5.real = this->force5;
      *(outbuffer + offset + 0) = (u_force5.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force5.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_force5.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_force5.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force5);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_force0;
      u_force0.base = 0;
      u_force0.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force0.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_force0.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_force0.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->force0 = u_force0.real;
      offset += sizeof(this->force0);
      union {
        int32_t real;
        uint32_t base;
      } u_force1;
      u_force1.base = 0;
      u_force1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_force1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_force1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->force1 = u_force1.real;
      offset += sizeof(this->force1);
      union {
        int32_t real;
        uint32_t base;
      } u_force2;
      u_force2.base = 0;
      u_force2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_force2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_force2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->force2 = u_force2.real;
      offset += sizeof(this->force2);
      union {
        int32_t real;
        uint32_t base;
      } u_force3;
      u_force3.base = 0;
      u_force3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_force3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_force3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->force3 = u_force3.real;
      offset += sizeof(this->force3);
      union {
        int32_t real;
        uint32_t base;
      } u_force4;
      u_force4.base = 0;
      u_force4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_force4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_force4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->force4 = u_force4.real;
      offset += sizeof(this->force4);
      union {
        int32_t real;
        uint32_t base;
      } u_force5;
      u_force5.base = 0;
      u_force5.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force5.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_force5.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_force5.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->force5 = u_force5.real;
      offset += sizeof(this->force5);
     return offset;
    }

    const char * getType(){ return SET_FORCE; };
    const char * getMD5(){ return "3c8721b68bc7d5e3d85bff9ad38312ed"; };

  };

  class set_forceResponse : public ros::Msg
  {
    public:
      typedef bool _force_accepted_type;
      _force_accepted_type force_accepted;

    set_forceResponse():
      force_accepted(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_force_accepted;
      u_force_accepted.real = this->force_accepted;
      *(outbuffer + offset + 0) = (u_force_accepted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->force_accepted);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_force_accepted;
      u_force_accepted.base = 0;
      u_force_accepted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->force_accepted = u_force_accepted.real;
      offset += sizeof(this->force_accepted);
     return offset;
    }

    const char * getType(){ return SET_FORCE; };
    const char * getMD5(){ return "6133e5998441599a96899c74dc63d85d"; };

  };

  class set_force {
    public:
    typedef set_forceRequest Request;
    typedef set_forceResponse Response;
  };

}
#endif

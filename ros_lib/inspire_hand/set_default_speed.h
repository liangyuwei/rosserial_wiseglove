#ifndef _ROS_SERVICE_set_default_speed_h
#define _ROS_SERVICE_set_default_speed_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char SET_DEFAULT_SPEED[] = "inspire_hand/set_default_speed";

  class set_default_speedRequest : public ros::Msg
  {
    public:
      typedef int32_t _speed0_type;
      _speed0_type speed0;
      typedef int32_t _speed1_type;
      _speed1_type speed1;
      typedef int32_t _speed2_type;
      _speed2_type speed2;
      typedef int32_t _speed3_type;
      _speed3_type speed3;
      typedef int32_t _speed4_type;
      _speed4_type speed4;
      typedef int32_t _speed5_type;
      _speed5_type speed5;

    set_default_speedRequest():
      speed0(0),
      speed1(0),
      speed2(0),
      speed3(0),
      speed4(0),
      speed5(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_speed0;
      u_speed0.real = this->speed0;
      *(outbuffer + offset + 0) = (u_speed0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed0.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed0);
      union {
        int32_t real;
        uint32_t base;
      } u_speed1;
      u_speed1.real = this->speed1;
      *(outbuffer + offset + 0) = (u_speed1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed1);
      union {
        int32_t real;
        uint32_t base;
      } u_speed2;
      u_speed2.real = this->speed2;
      *(outbuffer + offset + 0) = (u_speed2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed2);
      union {
        int32_t real;
        uint32_t base;
      } u_speed3;
      u_speed3.real = this->speed3;
      *(outbuffer + offset + 0) = (u_speed3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed3);
      union {
        int32_t real;
        uint32_t base;
      } u_speed4;
      u_speed4.real = this->speed4;
      *(outbuffer + offset + 0) = (u_speed4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed4);
      union {
        int32_t real;
        uint32_t base;
      } u_speed5;
      u_speed5.real = this->speed5;
      *(outbuffer + offset + 0) = (u_speed5.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed5.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed5.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed5.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed5);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_speed0;
      u_speed0.base = 0;
      u_speed0.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed0.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed0.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed0.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed0 = u_speed0.real;
      offset += sizeof(this->speed0);
      union {
        int32_t real;
        uint32_t base;
      } u_speed1;
      u_speed1.base = 0;
      u_speed1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed1 = u_speed1.real;
      offset += sizeof(this->speed1);
      union {
        int32_t real;
        uint32_t base;
      } u_speed2;
      u_speed2.base = 0;
      u_speed2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed2 = u_speed2.real;
      offset += sizeof(this->speed2);
      union {
        int32_t real;
        uint32_t base;
      } u_speed3;
      u_speed3.base = 0;
      u_speed3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed3 = u_speed3.real;
      offset += sizeof(this->speed3);
      union {
        int32_t real;
        uint32_t base;
      } u_speed4;
      u_speed4.base = 0;
      u_speed4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed4 = u_speed4.real;
      offset += sizeof(this->speed4);
      union {
        int32_t real;
        uint32_t base;
      } u_speed5;
      u_speed5.base = 0;
      u_speed5.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed5.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed5.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed5.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed5 = u_speed5.real;
      offset += sizeof(this->speed5);
     return offset;
    }

    const char * getType(){ return SET_DEFAULT_SPEED; };
    const char * getMD5(){ return "9b81c1887290eb799831f63509865cac"; };

  };

  class set_default_speedResponse : public ros::Msg
  {
    public:
      typedef bool _default_speed_accepted_type;
      _default_speed_accepted_type default_speed_accepted;

    set_default_speedResponse():
      default_speed_accepted(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_default_speed_accepted;
      u_default_speed_accepted.real = this->default_speed_accepted;
      *(outbuffer + offset + 0) = (u_default_speed_accepted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->default_speed_accepted);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_default_speed_accepted;
      u_default_speed_accepted.base = 0;
      u_default_speed_accepted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->default_speed_accepted = u_default_speed_accepted.real;
      offset += sizeof(this->default_speed_accepted);
     return offset;
    }

    const char * getType(){ return SET_DEFAULT_SPEED; };
    const char * getMD5(){ return "684dc1449df61cac44f84430b5f7b04c"; };

  };

  class set_default_speed {
    public:
    typedef set_default_speedRequest Request;
    typedef set_default_speedResponse Response;
  };

}
#endif

#ifndef _ROS_SERVICE_set_angle_h
#define _ROS_SERVICE_set_angle_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char SET_ANGLE[] = "inspire_hand/set_angle";

  class set_angleRequest : public ros::Msg
  {
    public:
      typedef int32_t _angle0_type;
      _angle0_type angle0;
      typedef int32_t _angle1_type;
      _angle1_type angle1;
      typedef int32_t _angle2_type;
      _angle2_type angle2;
      typedef int32_t _angle3_type;
      _angle3_type angle3;
      typedef int32_t _angle4_type;
      _angle4_type angle4;
      typedef int32_t _angle5_type;
      _angle5_type angle5;

    set_angleRequest():
      angle0(0),
      angle1(0),
      angle2(0),
      angle3(0),
      angle4(0),
      angle5(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_angle0;
      u_angle0.real = this->angle0;
      *(outbuffer + offset + 0) = (u_angle0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle0.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle0);
      union {
        int32_t real;
        uint32_t base;
      } u_angle1;
      u_angle1.real = this->angle1;
      *(outbuffer + offset + 0) = (u_angle1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle1);
      union {
        int32_t real;
        uint32_t base;
      } u_angle2;
      u_angle2.real = this->angle2;
      *(outbuffer + offset + 0) = (u_angle2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle2);
      union {
        int32_t real;
        uint32_t base;
      } u_angle3;
      u_angle3.real = this->angle3;
      *(outbuffer + offset + 0) = (u_angle3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle3);
      union {
        int32_t real;
        uint32_t base;
      } u_angle4;
      u_angle4.real = this->angle4;
      *(outbuffer + offset + 0) = (u_angle4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle4);
      union {
        int32_t real;
        uint32_t base;
      } u_angle5;
      u_angle5.real = this->angle5;
      *(outbuffer + offset + 0) = (u_angle5.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle5.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle5.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle5.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle5);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_angle0;
      u_angle0.base = 0;
      u_angle0.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle0.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle0.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle0.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle0 = u_angle0.real;
      offset += sizeof(this->angle0);
      union {
        int32_t real;
        uint32_t base;
      } u_angle1;
      u_angle1.base = 0;
      u_angle1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle1 = u_angle1.real;
      offset += sizeof(this->angle1);
      union {
        int32_t real;
        uint32_t base;
      } u_angle2;
      u_angle2.base = 0;
      u_angle2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle2 = u_angle2.real;
      offset += sizeof(this->angle2);
      union {
        int32_t real;
        uint32_t base;
      } u_angle3;
      u_angle3.base = 0;
      u_angle3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle3 = u_angle3.real;
      offset += sizeof(this->angle3);
      union {
        int32_t real;
        uint32_t base;
      } u_angle4;
      u_angle4.base = 0;
      u_angle4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle4 = u_angle4.real;
      offset += sizeof(this->angle4);
      union {
        int32_t real;
        uint32_t base;
      } u_angle5;
      u_angle5.base = 0;
      u_angle5.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle5.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle5.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle5.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle5 = u_angle5.real;
      offset += sizeof(this->angle5);
     return offset;
    }

    const char * getType(){ return SET_ANGLE; };
    const char * getMD5(){ return "5857a59881cd283e6c5a491fae619822"; };

  };

  class set_angleResponse : public ros::Msg
  {
    public:
      typedef bool _angle_accepted_type;
      _angle_accepted_type angle_accepted;

    set_angleResponse():
      angle_accepted(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_angle_accepted;
      u_angle_accepted.real = this->angle_accepted;
      *(outbuffer + offset + 0) = (u_angle_accepted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->angle_accepted);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_angle_accepted;
      u_angle_accepted.base = 0;
      u_angle_accepted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->angle_accepted = u_angle_accepted.real;
      offset += sizeof(this->angle_accepted);
     return offset;
    }

    const char * getType(){ return SET_ANGLE; };
    const char * getMD5(){ return "c1508b076c4c46f43d5103fcfc81271e"; };

  };

  class set_angle {
    public:
    typedef set_angleRequest Request;
    typedef set_angleResponse Response;
  };

}
#endif

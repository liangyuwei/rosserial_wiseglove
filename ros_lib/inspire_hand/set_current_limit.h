#ifndef _ROS_SERVICE_set_current_limit_h
#define _ROS_SERVICE_set_current_limit_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char SET_CURRENT_LIMIT[] = "inspire_hand/set_current_limit";

  class set_current_limitRequest : public ros::Msg
  {
    public:
      typedef int32_t _current0_type;
      _current0_type current0;
      typedef int32_t _current1_type;
      _current1_type current1;
      typedef int32_t _current2_type;
      _current2_type current2;
      typedef int32_t _current3_type;
      _current3_type current3;
      typedef int32_t _current4_type;
      _current4_type current4;
      typedef int32_t _current5_type;
      _current5_type current5;

    set_current_limitRequest():
      current0(0),
      current1(0),
      current2(0),
      current3(0),
      current4(0),
      current5(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_current0;
      u_current0.real = this->current0;
      *(outbuffer + offset + 0) = (u_current0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current0.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current0);
      union {
        int32_t real;
        uint32_t base;
      } u_current1;
      u_current1.real = this->current1;
      *(outbuffer + offset + 0) = (u_current1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current1);
      union {
        int32_t real;
        uint32_t base;
      } u_current2;
      u_current2.real = this->current2;
      *(outbuffer + offset + 0) = (u_current2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current2);
      union {
        int32_t real;
        uint32_t base;
      } u_current3;
      u_current3.real = this->current3;
      *(outbuffer + offset + 0) = (u_current3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current3);
      union {
        int32_t real;
        uint32_t base;
      } u_current4;
      u_current4.real = this->current4;
      *(outbuffer + offset + 0) = (u_current4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current4);
      union {
        int32_t real;
        uint32_t base;
      } u_current5;
      u_current5.real = this->current5;
      *(outbuffer + offset + 0) = (u_current5.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current5.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current5.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current5.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current5);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_current0;
      u_current0.base = 0;
      u_current0.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current0.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current0.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current0.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current0 = u_current0.real;
      offset += sizeof(this->current0);
      union {
        int32_t real;
        uint32_t base;
      } u_current1;
      u_current1.base = 0;
      u_current1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current1 = u_current1.real;
      offset += sizeof(this->current1);
      union {
        int32_t real;
        uint32_t base;
      } u_current2;
      u_current2.base = 0;
      u_current2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current2 = u_current2.real;
      offset += sizeof(this->current2);
      union {
        int32_t real;
        uint32_t base;
      } u_current3;
      u_current3.base = 0;
      u_current3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current3 = u_current3.real;
      offset += sizeof(this->current3);
      union {
        int32_t real;
        uint32_t base;
      } u_current4;
      u_current4.base = 0;
      u_current4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current4 = u_current4.real;
      offset += sizeof(this->current4);
      union {
        int32_t real;
        uint32_t base;
      } u_current5;
      u_current5.base = 0;
      u_current5.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current5.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current5.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current5.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current5 = u_current5.real;
      offset += sizeof(this->current5);
     return offset;
    }

    const char * getType(){ return SET_CURRENT_LIMIT; };
    const char * getMD5(){ return "9a9062b22d95e0929b8d48bafef48d49"; };

  };

  class set_current_limitResponse : public ros::Msg
  {
    public:
      typedef bool _current_limit_accepted_type;
      _current_limit_accepted_type current_limit_accepted;

    set_current_limitResponse():
      current_limit_accepted(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_current_limit_accepted;
      u_current_limit_accepted.real = this->current_limit_accepted;
      *(outbuffer + offset + 0) = (u_current_limit_accepted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->current_limit_accepted);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_current_limit_accepted;
      u_current_limit_accepted.base = 0;
      u_current_limit_accepted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->current_limit_accepted = u_current_limit_accepted.real;
      offset += sizeof(this->current_limit_accepted);
     return offset;
    }

    const char * getType(){ return SET_CURRENT_LIMIT; };
    const char * getMD5(){ return "91307348c21336c78336107026a1dcce"; };

  };

  class set_current_limit {
    public:
    typedef set_current_limitRequest Request;
    typedef set_current_limitResponse Response;
  };

}
#endif

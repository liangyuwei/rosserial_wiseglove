#ifndef _ROS_SERVICE_set_clear_error_h
#define _ROS_SERVICE_set_clear_error_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char SET_CLEAR_ERROR[] = "inspire_hand/set_clear_error";

  class set_clear_errorRequest : public ros::Msg
  {
    public:

    set_clear_errorRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SET_CLEAR_ERROR; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class set_clear_errorResponse : public ros::Msg
  {
    public:
      typedef bool _setclear_error_accepted_type;
      _setclear_error_accepted_type setclear_error_accepted;

    set_clear_errorResponse():
      setclear_error_accepted(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_setclear_error_accepted;
      u_setclear_error_accepted.real = this->setclear_error_accepted;
      *(outbuffer + offset + 0) = (u_setclear_error_accepted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->setclear_error_accepted);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_setclear_error_accepted;
      u_setclear_error_accepted.base = 0;
      u_setclear_error_accepted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->setclear_error_accepted = u_setclear_error_accepted.real;
      offset += sizeof(this->setclear_error_accepted);
     return offset;
    }

    const char * getType(){ return SET_CLEAR_ERROR; };
    const char * getMD5(){ return "a7e6099bc802656c2632bf2a50f44b2b"; };

  };

  class set_clear_error {
    public:
    typedef set_clear_errorRequest Request;
    typedef set_clear_errorResponse Response;
  };

}
#endif

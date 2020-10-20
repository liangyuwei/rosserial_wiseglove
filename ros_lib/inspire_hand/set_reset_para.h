#ifndef _ROS_SERVICE_set_reset_para_h
#define _ROS_SERVICE_set_reset_para_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char SET_RESET_PARA[] = "inspire_hand/set_reset_para";

  class set_reset_paraRequest : public ros::Msg
  {
    public:

    set_reset_paraRequest()
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

    const char * getType(){ return SET_RESET_PARA; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class set_reset_paraResponse : public ros::Msg
  {
    public:
      typedef bool _setreset_para_accepted_type;
      _setreset_para_accepted_type setreset_para_accepted;

    set_reset_paraResponse():
      setreset_para_accepted(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_setreset_para_accepted;
      u_setreset_para_accepted.real = this->setreset_para_accepted;
      *(outbuffer + offset + 0) = (u_setreset_para_accepted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->setreset_para_accepted);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_setreset_para_accepted;
      u_setreset_para_accepted.base = 0;
      u_setreset_para_accepted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->setreset_para_accepted = u_setreset_para_accepted.real;
      offset += sizeof(this->setreset_para_accepted);
     return offset;
    }

    const char * getType(){ return SET_RESET_PARA; };
    const char * getMD5(){ return "09c8a3c1c50f7ff06e4871280095d7ee"; };

  };

  class set_reset_para {
    public:
    typedef set_reset_paraRequest Request;
    typedef set_reset_paraResponse Response;
  };

}
#endif

#ifndef _ROS_SERVICE_set_force_clb_h
#define _ROS_SERVICE_set_force_clb_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char SET_FORCE_CLB[] = "inspire_hand/set_force_clb";

  class set_force_clbRequest : public ros::Msg
  {
    public:

    set_force_clbRequest()
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

    const char * getType(){ return SET_FORCE_CLB; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class set_force_clbResponse : public ros::Msg
  {
    public:
      typedef bool _setforce_clb_accepted_type;
      _setforce_clb_accepted_type setforce_clb_accepted;

    set_force_clbResponse():
      setforce_clb_accepted(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_setforce_clb_accepted;
      u_setforce_clb_accepted.real = this->setforce_clb_accepted;
      *(outbuffer + offset + 0) = (u_setforce_clb_accepted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->setforce_clb_accepted);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_setforce_clb_accepted;
      u_setforce_clb_accepted.base = 0;
      u_setforce_clb_accepted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->setforce_clb_accepted = u_setforce_clb_accepted.real;
      offset += sizeof(this->setforce_clb_accepted);
     return offset;
    }

    const char * getType(){ return SET_FORCE_CLB; };
    const char * getMD5(){ return "1ed618c9431c8faa2d80a957bf7da809"; };

  };

  class set_force_clb {
    public:
    typedef set_force_clbRequest Request;
    typedef set_force_clbResponse Response;
  };

}
#endif

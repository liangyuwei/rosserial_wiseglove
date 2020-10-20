#ifndef _ROS_SERVICE_get_force_set_h
#define _ROS_SERVICE_get_force_set_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char GET_FORCE_SET[] = "inspire_hand/get_force_set";

  class get_force_setRequest : public ros::Msg
  {
    public:

    get_force_setRequest()
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

    const char * getType(){ return GET_FORCE_SET; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class get_force_setResponse : public ros::Msg
  {
    public:
      float setforce[6];

    get_force_setResponse():
      setforce()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_setforcei;
      u_setforcei.real = this->setforce[i];
      *(outbuffer + offset + 0) = (u_setforcei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_setforcei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_setforcei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_setforcei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->setforce[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_setforcei;
      u_setforcei.base = 0;
      u_setforcei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_setforcei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_setforcei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_setforcei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->setforce[i] = u_setforcei.real;
      offset += sizeof(this->setforce[i]);
      }
     return offset;
    }

    const char * getType(){ return GET_FORCE_SET; };
    const char * getMD5(){ return "36dc498fde31a7d3735606fe581fda5c"; };

  };

  class get_force_set {
    public:
    typedef get_force_setRequest Request;
    typedef get_force_setResponse Response;
  };

}
#endif

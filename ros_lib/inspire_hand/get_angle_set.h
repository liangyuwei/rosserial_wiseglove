#ifndef _ROS_SERVICE_get_angle_set_h
#define _ROS_SERVICE_get_angle_set_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char GET_ANGLE_SET[] = "inspire_hand/get_angle_set";

  class get_angle_setRequest : public ros::Msg
  {
    public:

    get_angle_setRequest()
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

    const char * getType(){ return GET_ANGLE_SET; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class get_angle_setResponse : public ros::Msg
  {
    public:
      float setangle[6];

    get_angle_setResponse():
      setangle()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_setanglei;
      u_setanglei.real = this->setangle[i];
      *(outbuffer + offset + 0) = (u_setanglei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_setanglei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_setanglei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_setanglei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->setangle[i]);
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
      } u_setanglei;
      u_setanglei.base = 0;
      u_setanglei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_setanglei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_setanglei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_setanglei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->setangle[i] = u_setanglei.real;
      offset += sizeof(this->setangle[i]);
      }
     return offset;
    }

    const char * getType(){ return GET_ANGLE_SET; };
    const char * getMD5(){ return "9345778c384982b35dad72748c701694"; };

  };

  class get_angle_set {
    public:
    typedef get_angle_setRequest Request;
    typedef get_angle_setResponse Response;
  };

}
#endif

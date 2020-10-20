#ifndef _ROS_SERVICE_get_pos_set_h
#define _ROS_SERVICE_get_pos_set_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char GET_POS_SET[] = "inspire_hand/get_pos_set";

  class get_pos_setRequest : public ros::Msg
  {
    public:

    get_pos_setRequest()
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

    const char * getType(){ return GET_POS_SET; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class get_pos_setResponse : public ros::Msg
  {
    public:
      float setpos[6];

    get_pos_setResponse():
      setpos()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_setposi;
      u_setposi.real = this->setpos[i];
      *(outbuffer + offset + 0) = (u_setposi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_setposi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_setposi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_setposi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->setpos[i]);
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
      } u_setposi;
      u_setposi.base = 0;
      u_setposi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_setposi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_setposi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_setposi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->setpos[i] = u_setposi.real;
      offset += sizeof(this->setpos[i]);
      }
     return offset;
    }

    const char * getType(){ return GET_POS_SET; };
    const char * getMD5(){ return "cffb9069f96661e23c6011a89561b5a1"; };

  };

  class get_pos_set {
    public:
    typedef get_pos_setRequest Request;
    typedef get_pos_setResponse Response;
  };

}
#endif

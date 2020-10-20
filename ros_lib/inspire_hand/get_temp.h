#ifndef _ROS_SERVICE_get_temp_h
#define _ROS_SERVICE_get_temp_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char GET_TEMP[] = "inspire_hand/get_temp";

  class get_tempRequest : public ros::Msg
  {
    public:

    get_tempRequest()
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

    const char * getType(){ return GET_TEMP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class get_tempResponse : public ros::Msg
  {
    public:
      float tempvalue[6];

    get_tempResponse():
      tempvalue()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_tempvaluei;
      u_tempvaluei.real = this->tempvalue[i];
      *(outbuffer + offset + 0) = (u_tempvaluei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tempvaluei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tempvaluei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tempvaluei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tempvalue[i]);
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
      } u_tempvaluei;
      u_tempvaluei.base = 0;
      u_tempvaluei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tempvaluei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tempvaluei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tempvaluei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tempvalue[i] = u_tempvaluei.real;
      offset += sizeof(this->tempvalue[i]);
      }
     return offset;
    }

    const char * getType(){ return GET_TEMP; };
    const char * getMD5(){ return "faddf0cc102ec4c0d38aeffe0b8b6296"; };

  };

  class get_temp {
    public:
    typedef get_tempRequest Request;
    typedef get_tempResponse Response;
  };

}
#endif

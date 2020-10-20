#ifndef _ROS_SERVICE_get_status_h
#define _ROS_SERVICE_get_status_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char GET_STATUS[] = "inspire_hand/get_status";

  class get_statusRequest : public ros::Msg
  {
    public:

    get_statusRequest()
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

    const char * getType(){ return GET_STATUS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class get_statusResponse : public ros::Msg
  {
    public:
      float statusvalue[6];

    get_statusResponse():
      statusvalue()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_statusvaluei;
      u_statusvaluei.real = this->statusvalue[i];
      *(outbuffer + offset + 0) = (u_statusvaluei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_statusvaluei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_statusvaluei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_statusvaluei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->statusvalue[i]);
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
      } u_statusvaluei;
      u_statusvaluei.base = 0;
      u_statusvaluei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_statusvaluei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_statusvaluei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_statusvaluei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->statusvalue[i] = u_statusvaluei.real;
      offset += sizeof(this->statusvalue[i]);
      }
     return offset;
    }

    const char * getType(){ return GET_STATUS; };
    const char * getMD5(){ return "e2adc8174938c5ee3fd3a4e108c6b64f"; };

  };

  class get_status {
    public:
    typedef get_statusRequest Request;
    typedef get_statusResponse Response;
  };

}
#endif

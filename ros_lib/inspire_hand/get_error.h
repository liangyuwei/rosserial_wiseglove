#ifndef _ROS_SERVICE_get_error_h
#define _ROS_SERVICE_get_error_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char GET_ERROR[] = "inspire_hand/get_error";

  class get_errorRequest : public ros::Msg
  {
    public:

    get_errorRequest()
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

    const char * getType(){ return GET_ERROR; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class get_errorResponse : public ros::Msg
  {
    public:
      float errorvalue[6];

    get_errorResponse():
      errorvalue()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_errorvaluei;
      u_errorvaluei.real = this->errorvalue[i];
      *(outbuffer + offset + 0) = (u_errorvaluei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_errorvaluei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_errorvaluei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_errorvaluei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->errorvalue[i]);
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
      } u_errorvaluei;
      u_errorvaluei.base = 0;
      u_errorvaluei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_errorvaluei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_errorvaluei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_errorvaluei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->errorvalue[i] = u_errorvaluei.real;
      offset += sizeof(this->errorvalue[i]);
      }
     return offset;
    }

    const char * getType(){ return GET_ERROR; };
    const char * getMD5(){ return "a53f03f634bc27bd5924537063e03a53"; };

  };

  class get_error {
    public:
    typedef get_errorRequest Request;
    typedef get_errorResponse Response;
  };

}
#endif

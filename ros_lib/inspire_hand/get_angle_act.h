#ifndef _ROS_SERVICE_get_angle_act_h
#define _ROS_SERVICE_get_angle_act_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char GET_ANGLE_ACT[] = "inspire_hand/get_angle_act";

  class get_angle_actRequest : public ros::Msg
  {
    public:

    get_angle_actRequest()
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

    const char * getType(){ return GET_ANGLE_ACT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class get_angle_actResponse : public ros::Msg
  {
    public:
      float curangle[6];

    get_angle_actResponse():
      curangle()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_curanglei;
      u_curanglei.real = this->curangle[i];
      *(outbuffer + offset + 0) = (u_curanglei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_curanglei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_curanglei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_curanglei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->curangle[i]);
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
      } u_curanglei;
      u_curanglei.base = 0;
      u_curanglei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_curanglei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_curanglei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_curanglei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->curangle[i] = u_curanglei.real;
      offset += sizeof(this->curangle[i]);
      }
     return offset;
    }

    const char * getType(){ return GET_ANGLE_ACT; };
    const char * getMD5(){ return "2329a3c808aea9d534c8a2279948da90"; };

  };

  class get_angle_act {
    public:
    typedef get_angle_actRequest Request;
    typedef get_angle_actResponse Response;
  };

}
#endif

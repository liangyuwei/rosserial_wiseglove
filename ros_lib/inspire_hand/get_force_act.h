#ifndef _ROS_SERVICE_get_force_act_h
#define _ROS_SERVICE_get_force_act_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char GET_FORCE_ACT[] = "inspire_hand/get_force_act";

  class get_force_actRequest : public ros::Msg
  {
    public:

    get_force_actRequest()
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

    const char * getType(){ return GET_FORCE_ACT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class get_force_actResponse : public ros::Msg
  {
    public:
      float curforce[6];

    get_force_actResponse():
      curforce()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_curforcei;
      u_curforcei.real = this->curforce[i];
      *(outbuffer + offset + 0) = (u_curforcei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_curforcei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_curforcei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_curforcei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->curforce[i]);
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
      } u_curforcei;
      u_curforcei.base = 0;
      u_curforcei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_curforcei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_curforcei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_curforcei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->curforce[i] = u_curforcei.real;
      offset += sizeof(this->curforce[i]);
      }
     return offset;
    }

    const char * getType(){ return GET_FORCE_ACT; };
    const char * getMD5(){ return "70074285dbeda980356fefe582262f12"; };

  };

  class get_force_act {
    public:
    typedef get_force_actRequest Request;
    typedef get_force_actResponse Response;
  };

}
#endif

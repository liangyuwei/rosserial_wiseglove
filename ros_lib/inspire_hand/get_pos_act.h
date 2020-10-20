#ifndef _ROS_SERVICE_get_pos_act_h
#define _ROS_SERVICE_get_pos_act_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char GET_POS_ACT[] = "inspire_hand/get_pos_act";

  class get_pos_actRequest : public ros::Msg
  {
    public:

    get_pos_actRequest()
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

    const char * getType(){ return GET_POS_ACT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class get_pos_actResponse : public ros::Msg
  {
    public:
      float curpos[6];

    get_pos_actResponse():
      curpos()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_curposi;
      u_curposi.real = this->curpos[i];
      *(outbuffer + offset + 0) = (u_curposi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_curposi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_curposi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_curposi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->curpos[i]);
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
      } u_curposi;
      u_curposi.base = 0;
      u_curposi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_curposi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_curposi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_curposi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->curpos[i] = u_curposi.real;
      offset += sizeof(this->curpos[i]);
      }
     return offset;
    }

    const char * getType(){ return GET_POS_ACT; };
    const char * getMD5(){ return "a70fb6e8637c623cad009e6d713de894"; };

  };

  class get_pos_act {
    public:
    typedef get_pos_actRequest Request;
    typedef get_pos_actResponse Response;
  };

}
#endif

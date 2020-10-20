#ifndef _ROS_SERVICE_set_redu_ratio_h
#define _ROS_SERVICE_set_redu_ratio_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char SET_REDU_RATIO[] = "inspire_hand/set_redu_ratio";

  class set_redu_ratioRequest : public ros::Msg
  {
    public:
      typedef int32_t _redu_ratio_type;
      _redu_ratio_type redu_ratio;

    set_redu_ratioRequest():
      redu_ratio(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_redu_ratio;
      u_redu_ratio.real = this->redu_ratio;
      *(outbuffer + offset + 0) = (u_redu_ratio.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_redu_ratio.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_redu_ratio.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_redu_ratio.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->redu_ratio);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_redu_ratio;
      u_redu_ratio.base = 0;
      u_redu_ratio.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_redu_ratio.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_redu_ratio.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_redu_ratio.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->redu_ratio = u_redu_ratio.real;
      offset += sizeof(this->redu_ratio);
     return offset;
    }

    const char * getType(){ return SET_REDU_RATIO; };
    const char * getMD5(){ return "f53cf3e807cecd6ac535ce2490110114"; };

  };

  class set_redu_ratioResponse : public ros::Msg
  {
    public:
      typedef bool _redu_ratiograb_type;
      _redu_ratiograb_type redu_ratiograb;

    set_redu_ratioResponse():
      redu_ratiograb(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_redu_ratiograb;
      u_redu_ratiograb.real = this->redu_ratiograb;
      *(outbuffer + offset + 0) = (u_redu_ratiograb.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->redu_ratiograb);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_redu_ratiograb;
      u_redu_ratiograb.base = 0;
      u_redu_ratiograb.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->redu_ratiograb = u_redu_ratiograb.real;
      offset += sizeof(this->redu_ratiograb);
     return offset;
    }

    const char * getType(){ return SET_REDU_RATIO; };
    const char * getMD5(){ return "4d1b975ad952b9874bc1e1818834aa76"; };

  };

  class set_redu_ratio {
    public:
    typedef set_redu_ratioRequest Request;
    typedef set_redu_ratioResponse Response;
  };

}
#endif

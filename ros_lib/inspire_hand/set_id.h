#ifndef _ROS_SERVICE_set_id_h
#define _ROS_SERVICE_set_id_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char SET_ID[] = "inspire_hand/set_id";

  class set_idRequest : public ros::Msg
  {
    public:
      typedef int32_t _id_type;
      _id_type id;

    set_idRequest():
      id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
     return offset;
    }

    const char * getType(){ return SET_ID; };
    const char * getMD5(){ return "c5e4a7d59c68f74eabcec876a00216aa"; };

  };

  class set_idResponse : public ros::Msg
  {
    public:
      typedef bool _idgrab_type;
      _idgrab_type idgrab;

    set_idResponse():
      idgrab(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_idgrab;
      u_idgrab.real = this->idgrab;
      *(outbuffer + offset + 0) = (u_idgrab.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->idgrab);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_idgrab;
      u_idgrab.base = 0;
      u_idgrab.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->idgrab = u_idgrab.real;
      offset += sizeof(this->idgrab);
     return offset;
    }

    const char * getType(){ return SET_ID; };
    const char * getMD5(){ return "4f3154975e1d2695a8f316a8e2000a60"; };

  };

  class set_id {
    public:
    typedef set_idRequest Request;
    typedef set_idResponse Response;
  };

}
#endif

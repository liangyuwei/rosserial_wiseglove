#ifndef _ROS_SERVICE_set_save_flash_h
#define _ROS_SERVICE_set_save_flash_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char SET_SAVE_FLASH[] = "inspire_hand/set_save_flash";

  class set_save_flashRequest : public ros::Msg
  {
    public:

    set_save_flashRequest()
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

    const char * getType(){ return SET_SAVE_FLASH; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class set_save_flashResponse : public ros::Msg
  {
    public:
      typedef bool _setsave_flash_accepted_type;
      _setsave_flash_accepted_type setsave_flash_accepted;

    set_save_flashResponse():
      setsave_flash_accepted(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_setsave_flash_accepted;
      u_setsave_flash_accepted.real = this->setsave_flash_accepted;
      *(outbuffer + offset + 0) = (u_setsave_flash_accepted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->setsave_flash_accepted);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_setsave_flash_accepted;
      u_setsave_flash_accepted.base = 0;
      u_setsave_flash_accepted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->setsave_flash_accepted = u_setsave_flash_accepted.real;
      offset += sizeof(this->setsave_flash_accepted);
     return offset;
    }

    const char * getType(){ return SET_SAVE_FLASH; };
    const char * getMD5(){ return "ce29f0181fca97433252cab2ac73bda5"; };

  };

  class set_save_flash {
    public:
    typedef set_save_flashRequest Request;
    typedef set_save_flashResponse Response;
  };

}
#endif

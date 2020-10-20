#ifndef _ROS_SERVICE_set_pos_h
#define _ROS_SERVICE_set_pos_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char SET_POS[] = "inspire_hand/set_pos";

  class set_posRequest : public ros::Msg
  {
    public:
      typedef int32_t _pos0_type;
      _pos0_type pos0;
      typedef int32_t _pos1_type;
      _pos1_type pos1;
      typedef int32_t _pos2_type;
      _pos2_type pos2;
      typedef int32_t _pos3_type;
      _pos3_type pos3;
      typedef int32_t _pos4_type;
      _pos4_type pos4;
      typedef int32_t _pos5_type;
      _pos5_type pos5;

    set_posRequest():
      pos0(0),
      pos1(0),
      pos2(0),
      pos3(0),
      pos4(0),
      pos5(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_pos0;
      u_pos0.real = this->pos0;
      *(outbuffer + offset + 0) = (u_pos0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos0.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos0);
      union {
        int32_t real;
        uint32_t base;
      } u_pos1;
      u_pos1.real = this->pos1;
      *(outbuffer + offset + 0) = (u_pos1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos1);
      union {
        int32_t real;
        uint32_t base;
      } u_pos2;
      u_pos2.real = this->pos2;
      *(outbuffer + offset + 0) = (u_pos2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos2);
      union {
        int32_t real;
        uint32_t base;
      } u_pos3;
      u_pos3.real = this->pos3;
      *(outbuffer + offset + 0) = (u_pos3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos3);
      union {
        int32_t real;
        uint32_t base;
      } u_pos4;
      u_pos4.real = this->pos4;
      *(outbuffer + offset + 0) = (u_pos4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos4);
      union {
        int32_t real;
        uint32_t base;
      } u_pos5;
      u_pos5.real = this->pos5;
      *(outbuffer + offset + 0) = (u_pos5.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos5.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos5.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos5.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos5);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_pos0;
      u_pos0.base = 0;
      u_pos0.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pos0.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pos0.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pos0.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pos0 = u_pos0.real;
      offset += sizeof(this->pos0);
      union {
        int32_t real;
        uint32_t base;
      } u_pos1;
      u_pos1.base = 0;
      u_pos1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pos1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pos1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pos1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pos1 = u_pos1.real;
      offset += sizeof(this->pos1);
      union {
        int32_t real;
        uint32_t base;
      } u_pos2;
      u_pos2.base = 0;
      u_pos2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pos2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pos2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pos2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pos2 = u_pos2.real;
      offset += sizeof(this->pos2);
      union {
        int32_t real;
        uint32_t base;
      } u_pos3;
      u_pos3.base = 0;
      u_pos3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pos3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pos3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pos3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pos3 = u_pos3.real;
      offset += sizeof(this->pos3);
      union {
        int32_t real;
        uint32_t base;
      } u_pos4;
      u_pos4.base = 0;
      u_pos4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pos4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pos4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pos4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pos4 = u_pos4.real;
      offset += sizeof(this->pos4);
      union {
        int32_t real;
        uint32_t base;
      } u_pos5;
      u_pos5.base = 0;
      u_pos5.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pos5.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pos5.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pos5.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pos5 = u_pos5.real;
      offset += sizeof(this->pos5);
     return offset;
    }

    const char * getType(){ return SET_POS; };
    const char * getMD5(){ return "44ecda5531a5154559fe37419faa32a4"; };

  };

  class set_posResponse : public ros::Msg
  {
    public:
      typedef bool _pos_accepted_type;
      _pos_accepted_type pos_accepted;

    set_posResponse():
      pos_accepted(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_pos_accepted;
      u_pos_accepted.real = this->pos_accepted;
      *(outbuffer + offset + 0) = (u_pos_accepted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pos_accepted);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_pos_accepted;
      u_pos_accepted.base = 0;
      u_pos_accepted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pos_accepted = u_pos_accepted.real;
      offset += sizeof(this->pos_accepted);
     return offset;
    }

    const char * getType(){ return SET_POS; };
    const char * getMD5(){ return "642adf9364b32587cec215516fb006b2"; };

  };

  class set_pos {
    public:
    typedef set_posRequest Request;
    typedef set_posResponse Response;
  };

}
#endif

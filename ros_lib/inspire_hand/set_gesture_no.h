#ifndef _ROS_SERVICE_set_gesture_no_h
#define _ROS_SERVICE_set_gesture_no_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char SET_GESTURE_NO[] = "inspire_hand/set_gesture_no";

  class set_gesture_noRequest : public ros::Msg
  {
    public:
      typedef int32_t _gesture_no_type;
      _gesture_no_type gesture_no;

    set_gesture_noRequest():
      gesture_no(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_gesture_no;
      u_gesture_no.real = this->gesture_no;
      *(outbuffer + offset + 0) = (u_gesture_no.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gesture_no.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gesture_no.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gesture_no.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gesture_no);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_gesture_no;
      u_gesture_no.base = 0;
      u_gesture_no.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gesture_no.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gesture_no.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gesture_no.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gesture_no = u_gesture_no.real;
      offset += sizeof(this->gesture_no);
     return offset;
    }

    const char * getType(){ return SET_GESTURE_NO; };
    const char * getMD5(){ return "ea289c543a56bf8388893db17ebece7f"; };

  };

  class set_gesture_noResponse : public ros::Msg
  {
    public:
      typedef bool _gesture_nograb_type;
      _gesture_nograb_type gesture_nograb;

    set_gesture_noResponse():
      gesture_nograb(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_gesture_nograb;
      u_gesture_nograb.real = this->gesture_nograb;
      *(outbuffer + offset + 0) = (u_gesture_nograb.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gesture_nograb);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_gesture_nograb;
      u_gesture_nograb.base = 0;
      u_gesture_nograb.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->gesture_nograb = u_gesture_nograb.real;
      offset += sizeof(this->gesture_nograb);
     return offset;
    }

    const char * getType(){ return SET_GESTURE_NO; };
    const char * getMD5(){ return "824a75c5329ea6ddcb5d80fa3550cb1c"; };

  };

  class set_gesture_no {
    public:
    typedef set_gesture_noRequest Request;
    typedef set_gesture_noResponse Response;
  };

}
#endif

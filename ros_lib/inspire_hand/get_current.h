#ifndef _ROS_SERVICE_get_current_h
#define _ROS_SERVICE_get_current_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace inspire_hand
{

static const char GET_CURRENT[] = "inspire_hand/get_current";

  class get_currentRequest : public ros::Msg
  {
    public:

    get_currentRequest()
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

    const char * getType(){ return GET_CURRENT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class get_currentResponse : public ros::Msg
  {
    public:
      float current[6];

    get_currentResponse():
      current()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_currenti;
      u_currenti.real = this->current[i];
      *(outbuffer + offset + 0) = (u_currenti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_currenti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_currenti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_currenti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current[i]);
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
      } u_currenti;
      u_currenti.base = 0;
      u_currenti.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_currenti.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_currenti.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_currenti.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current[i] = u_currenti.real;
      offset += sizeof(this->current[i]);
      }
     return offset;
    }

    const char * getType(){ return GET_CURRENT; };
    const char * getMD5(){ return "11d573dfe70ac25437cf58ad00cf741d"; };

  };

  class get_current {
    public:
    typedef get_currentRequest Request;
    typedef get_currentResponse Response;
  };

}
#endif

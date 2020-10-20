#ifndef _ROS_arm_hand_capture_DualArmDualHandStateWithImage_h
#define _ROS_arm_hand_capture_DualArmDualHandStateWithImage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "arm_hand_capture/GloveState.h"
#include "sensor_msgs/Image.h"

namespace arm_hand_capture
{

  class DualArmDualHandStateWithImage : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _left_upperarm_pose_type;
      _left_upperarm_pose_type left_upperarm_pose;
      typedef geometry_msgs::PoseStamped _left_forearm_pose_type;
      _left_forearm_pose_type left_forearm_pose;
      typedef geometry_msgs::PoseStamped _left_hand_pose_type;
      _left_hand_pose_type left_hand_pose;
      typedef arm_hand_capture::GloveState _left_glove_state_type;
      _left_glove_state_type left_glove_state;
      typedef geometry_msgs::PoseStamped _right_upperarm_pose_type;
      _right_upperarm_pose_type right_upperarm_pose;
      typedef geometry_msgs::PoseStamped _right_forearm_pose_type;
      _right_forearm_pose_type right_forearm_pose;
      typedef geometry_msgs::PoseStamped _right_hand_pose_type;
      _right_hand_pose_type right_hand_pose;
      typedef arm_hand_capture::GloveState _glove_state_type;
      _glove_state_type glove_state;
      typedef sensor_msgs::Image _image_type;
      _image_type image;

    DualArmDualHandStateWithImage():
      left_upperarm_pose(),
      left_forearm_pose(),
      left_hand_pose(),
      left_glove_state(),
      right_upperarm_pose(),
      right_forearm_pose(),
      right_hand_pose(),
      glove_state(),
      image()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->left_upperarm_pose.serialize(outbuffer + offset);
      offset += this->left_forearm_pose.serialize(outbuffer + offset);
      offset += this->left_hand_pose.serialize(outbuffer + offset);
      offset += this->left_glove_state.serialize(outbuffer + offset);
      offset += this->right_upperarm_pose.serialize(outbuffer + offset);
      offset += this->right_forearm_pose.serialize(outbuffer + offset);
      offset += this->right_hand_pose.serialize(outbuffer + offset);
      offset += this->glove_state.serialize(outbuffer + offset);
      offset += this->image.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->left_upperarm_pose.deserialize(inbuffer + offset);
      offset += this->left_forearm_pose.deserialize(inbuffer + offset);
      offset += this->left_hand_pose.deserialize(inbuffer + offset);
      offset += this->left_glove_state.deserialize(inbuffer + offset);
      offset += this->right_upperarm_pose.deserialize(inbuffer + offset);
      offset += this->right_forearm_pose.deserialize(inbuffer + offset);
      offset += this->right_hand_pose.deserialize(inbuffer + offset);
      offset += this->glove_state.deserialize(inbuffer + offset);
      offset += this->image.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "arm_hand_capture/DualArmDualHandStateWithImage"; };
    const char * getMD5(){ return "1d9d7995b76d7a628fdf03a441782be2"; };

  };

}
#endif
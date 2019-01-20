#include "forward_kinematics.h"
#include "euler_angles_to_transform.h"
#include <functional> // std::function

void forward_kinematics(
  const Skeleton & skeleton,
  std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d> > & T)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code

  T.resize(skeleton.size(),Eigen::Affine3d::Identity());

  for (int i = 0; i < skeleton.size(); ++i) {
    auto bone = skeleton[i];
    if (bone.parent_index == -1 && bone.weight_index == -1) {
      // root 
      T[i] = Eigen::Affine3d::Identity();
    } else {
      T[i] = T[bone.parent_index] * bone.rest_T *
        euler_angles_to_transform(bone.xzx) * bone.rest_T.inverse();
    }
  }

  /////////////////////////////////////////////////////////////////////////////
}

#include "transformed_tips.h"
#include "forward_kinematics.h"

Eigen::VectorXd transformed_tips(
  const Skeleton & skeleton, 
  const Eigen::VectorXi & b)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code

  Eigen::VectorXd tips(3*b.size());

  std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d>> T;
  forward_kinematics(skeleton, T);

  Eigen::Vector3d canonical_tip = Eigen::Vector3d::Zero();
  for (int i = 0; i < b.size(); ++i) {
    auto bone = skeleton[b(i)];
    canonical_tip(0) = bone.length;
    tips.segment(i, 3) = T[b(i)] * bone.rest_T * canonical_tip;
  }

  return tips;
  /////////////////////////////////////////////////////////////////////////////
}

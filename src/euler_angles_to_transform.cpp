#include "euler_angles_to_transform.h"

Eigen::Affine3d euler_angles_to_transform(
  const Eigen::Vector3d & xzx)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  Eigen::Affine3d A;
  A = Eigen::AngleAxisd(xzx(0), Eigen::Vector3d::UnitX()) *
      Eigen::AngleAxisd(xzx(1), Eigen::Vector3d::UnitZ()) *
      Eigen::AngleAxisd(xzx(2), Eigen::Vector3d::UnitX());

  return A;
  /////////////////////////////////////////////////////////////////////////////
}

#include "copy_skeleton_at.h"
Skeleton copy_skeleton_at(
  const Skeleton & skeleton, 
  const Eigen::VectorXd & A)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code
  Skeleton copy = skeleton;

  for (int i = 0; i < A.rows(); ++i) {
    copy[i].xzx = A.row(i);
  }

  return copy;
  /////////////////////////////////////////////////////////////////////////////
}

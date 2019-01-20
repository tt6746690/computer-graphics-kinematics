#include "linear_blend_skinning.h"

#include <iostream>

void linear_blend_skinning(
  const Eigen::MatrixXd & V,
  const Skeleton & skeleton,
  const std::vector<Eigen::Affine3d,Eigen::aligned_allocator<Eigen::Affine3d> > & T,
  const Eigen::MatrixXd & W,
  Eigen::MatrixXd & U)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code

  U = Eigen::MatrixXd::Zero(V.rows(), 3);

  int wcol;
  Eigen::Vector3d vi;

  for (int i = 0; i < V.rows(); ++i) {
    for (int j = 0; j < skeleton.size(); ++j) {
      wcol = skeleton[j].weight_index;
      if (wcol != -1) {
        vi = V.row(i).transpose();
        U.row(i) += W(i, wcol) * (T[j] * vi);
      }
    }
  }

  /////////////////////////////////////////////////////////////////////////////
}

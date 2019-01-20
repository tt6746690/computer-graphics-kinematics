#include "catmull_rom_interpolation.h"
#include <Eigen/Dense>

Eigen::Vector3d catmull_rom_interpolation(
  const std::vector<std::pair<double, Eigen::Vector3d> > & keyframes,
  double t)
{
  /////////////////////////////////////////////////////////////////////////////
  // Replace with your code

  // Reference:
  //    http://graphics.cs.ucdavis.edu/~joy/ecs278/notes/Catmull-Rom-Spline.pdf
  //    https://en.wikipedia.org/wiki/Cubic_Hermite_spline#Catmull%E2%80%93Rom_spline

  if (keyframes.size() == 0 ||
     t < keyframes[0].first || 
     t > keyframes[keyframes.size()-1].first)
  {
    return Eigen::Vector3d::Zero();
  }

  // identify which keyframes are used to do interpolation

  std::pair<double, Eigen::Vector3d> p0, p1, p2, p3;

  for (int i = 0; i < keyframes.size()-1; ++i) {
    if (t >= keyframes[i].first && i <= keyframes[i+1].first) {
      p1 = keyframes[i];
      p2 = keyframes[i+1];

      // duplicate control points for interpolating tangents at endpoints
      p0 = (i == 0) ? 
        keyframes[0] : keyframes[i-1];
      p3 = (i+2 == keyframes.size()) ?
        keyframes[i+1] : keyframes[i+2];

      break;
    }
  }

  const auto tangent = [](
    const std::pair<double, Eigen::Vector3d> p1,
    const std::pair<double, Eigen::Vector3d> p2){
    return (p1.second - p2.second) / (p1.first - p2.first);
  };

  Eigen::Vector3d pt;
  pt = (1 - 3*t*t + 2*t*t*t) * p1.second + 
           (3*t*t - 2*t*t*t) * p2.second + 
         (t - 2*t*t + t*t*t) * tangent(p0, p2) + 
              (-t*t + t*t*t) * tangent(p1, p3);

  return pt;
  /////////////////////////////////////////////////////////////////////////////
}

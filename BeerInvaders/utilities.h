#include <limits>

//define some useful consts
const double	MaxDouble	= (std::numeric_limits<double>::max) ();
const double	MinDouble	= (std::numeric_limits<double>::min) ();

inline bool isEqual(double a, double b)
{
  if (fabs(a-b) < 1E-12)
  {
    return true;
  }

  return false;
}

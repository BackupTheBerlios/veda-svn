#include "Point.hpp"

/* Point friends */

namespace Geometry
{

Point operator-(const Point & p1, const Point& p)
{ return (-p + p1); }

Point operator*(const double& a, const Point& p)
{ return p * a;}

double distance(const Point& p1, const Point& p2)
{ return (p1 - p2).modulus(); }

}

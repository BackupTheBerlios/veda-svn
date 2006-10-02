#ifndef MATH_
#define MATH_

#include <math.h>

namespace Geometry
{
	
/* wrapped mathematics */

inline double Rand()
{
	return static_cast<double>((rand() % 10000) * 1e-4);
}

inline double Abs(const double &a)
{
	return (a > 0) ? a : -a;
}

inline double Sqrt(const double &a)
{
	return static_cast<double>(sqrt(static_cast<double>(a)));
}

inline double Sqr(const double &a)
{
	return a*a;
}

inline double Cub(const double &a)
{
	return a*a*a;
}

/* create insane */

inline double Nan()
{
	double z = 0, y = 0;
	return y / z;
}

inline double Inf()
{
	double z =0;
	return 1 / z;
}

/* check */

inline bool isZero(const double &a)
{
	return (Abs(a) < 1e-40);
}

inline bool isInf(const double &a)
{
	return (Abs(a) > 1e+40);
}

inline bool isValid(const double &a)
{
	return ((a == a) && (Abs(a) < 1e+40));
}

/* compare */

inline int Signum(const double &a)
{
	if( a > 0 ) return 1;
	if( a < 0 ) return -1;
	return 0;
}

inline double Max(const double &a, const double &b)
{
	return ((a > b) ? a : b);
}

inline double Min(const double &a, const double &b)
{
	return ((a > b) ? b : a);
}
	
}

#endif /*MATH_*/

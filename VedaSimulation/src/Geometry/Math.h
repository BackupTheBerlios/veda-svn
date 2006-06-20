#ifndef MATH_
#define MATH_

#include <math.h>

namespace Geometry
{
	
/* wrapped mathematics */

template<class T>
inline T Rand()
{
	return static_cast<T>((rand() % 10000) * 1e-4);
}

template<class T>
inline T Abs(const T &a)
{
	return (a > 0) ? a : -a;
}

template<class T>
inline T Sqrt(const T &a)
{
	return static_cast<T>(sqrt(static_cast<double>(a)));
}

template<class T>
inline T Sqr(const T &a)
{
	return a*a;
}

template<class T>
inline T Cub(const T &a)
{
	return a*a*a;
}

/* create insane */

template<class T>
inline T Nan()
{
	T z = 0, y = 0;
	return y / z;
}

template<class T>
inline T Inf()
{
	T z =0;
	return 1 / z;
}

/* check */

template<class T>
inline bool isZero(const T &a)
{
	return (Abs(a) < 1e-40);
}

template<class T>
inline bool isInf(const T &a)
{
	return (Abs(a) > 1e+40);
}

template<class T>
inline bool isValid(const double &a)
{
	return ((a == a) && (Abs(a) < 1e+40));
}

/* compare */

template<class T>
inline int Signum(const T &a)
{
	if( a > 0 ) return 1;
	if( a < 0 ) return -1;
	return 0;
}

template<class T>
inline double Max(const T &a, const T &b)
{
	return ((a > b) ? a : b);
}

template<class T>
inline double Min(const T &a, const T &b)
{
	return ((a > b) ? b : a);
}
	
}

#endif /*MATH_*/

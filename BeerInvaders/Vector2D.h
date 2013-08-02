#pragma once

#include "utilities.h"

class Vector2D
{
public:

	double x;
	double y;

	Vector2D():x(0.0),y(0.0){}
	Vector2D(double a, double b):x(a),y(b){}

	~Vector2D(void)	{}

	//sets x and y to 0.0
	inline void		Zero(){ x=0.0; y=0.0;}

	//returns true if both x & y are zero
	bool			isZero()const{return (x*x + y*y) < MinDouble;}

	//return the length of the vector
	inline double	Length()const;

	//returns the length squared (no sqrt)
	inline double	LengthSq()const;

	//normalize the vector
	inline void		Normalize();

	//returns the dot product of this and v2
	inline double	Dot(const Vector2D& v2)const;
	
	//returns positive if v2 is clockwise of this vector
	//negative if counter clockwise
	//assumes Y axis points DOWN, X axis points RIGHT (like a window app)
	inline int		Sign(const Vector2D& v2)const;

	//returns a vector perpendicular to this
	inline Vector2D	Perp()const;

	//adjusts x and y so length of vector does not exceed max
	inline void		Truncate(double max);

	//returns distance between this vector and the one passed as a parameter
	inline double	Distance(const Vector2D& v2)const;

	//same as above but returns sq root
	inline double	DistanceSq(const Vector2D& v2)const;

	inline void		Reflect(const Vector2D& norm);

	//returns the vector that is the reverse of this vector
	inline Vector2D	GetReverse()const;

	//some vector operators
	const Vector2D& operator+=(const Vector2D& rhs)
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	const Vector2D& operator-=(const Vector2D& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;

		return *this;
	}

	const Vector2D& operator*=(const Vector2D& rhs)
	{
		x *= rhs.x;
		y -= rhs.y;

		return *this;
	}

	const Vector2D& operator/=(const Vector2D& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;

		return *this;
	}

	bool operator==(const Vector2D& rhs)const
	{
		return (isEqual(x, rhs.x) && isEqual(y, rhs.y) );
	}

	bool operator!=(const Vector2D& rhs)const
	{
		return (x != rhs.x) || (y != rhs.y);
	}
};

inline Vector2D operator*(const Vector2D &lhs, double rhs);
inline Vector2D operator*(double lhs, const Vector2D &rhs);
inline Vector2D operator-(const Vector2D &lhs, const Vector2D &rhs);
inline Vector2D operator+(const Vector2D &lhs, const Vector2D &rhs);
inline Vector2D operator/(const Vector2D &lhs, double val);
std::ostream& operator<<(std::ostream& os, const Vector2D& rhs);
std::ifstream& operator>>(std::ifstream& is, Vector2D& lhs);

inline double Vector2D::Length()const
{
	return sqrt(x * x + y * y);
}

inline double Vector2D::LengthSq()const
{
	return (x * x + y * y);
}

inline double Vector2D::Dot(const Vector2D &v2)const
{
	return x*v2.x + y*v2.y;
}

enum {clockwise = 1, anticlockwise = -1};

inline int Vector2D::Sign(const Vector2D& v2)const
{
	if (y*v2.x > x*v2.y)
	{ 
		return anticlockwise;
	}
	else 
	{
		return clockwise;
	}
}
#include <iostream>
#include "vector.h"



vector3::Vector3::Vector3(double x, double y, double z)
{
	_x = x;
	_y = y;
	_z = z;
}
	
double vector3::Vector3::getX() const
{
	return _x;
}
double vector3::Vector3::getY() const
{
	return _y;
}
double vector3::Vector3::getZ() const
{
	return _z;
}
	


vector3::Vector3 vector3::operator+(const Vector3& lft, const Vector3& rght)
{
	return Vector3{
	lft.getX() + rght.getX(),
	lft.getY() + rght.getY(),
	lft.getZ() + rght.getZ()
	};
}
void vector3::operator+=(Vector3& lft, const Vector3& rght)
{
	lft = lft + rght;
}

vector3::Vector3 vector3::operator-(const Vector3& lft, const Vector3& rght)
{
	return Vector3{
	lft.getX() - rght.getX(),
	lft.getY() - rght.getY(),
	lft.getZ() - rght.getZ()
	};
}
void vector3::operator-=(Vector3& lft, const Vector3& rght)
{
	lft = lft - rght;
}

vector3::Vector3 vector3::operator*(const Vector3& lft, const Vector3& rght)
{
	return Vector3{
	lft.getY()*rght.getZ() - lft.getZ()*rght.getY(),
	lft.getZ()*rght.getX() - lft.getX()*rght.getZ(),
	lft.getX()*rght.getY() - lft.getY()*rght.getX()
	};
}
void vector3::operator*=(Vector3& lft, const Vector3& rght)
{
	lft = lft * rght;
}

vector3::Vector3 vector3::operator*(const Vector3& lft, const int& rght)
{
	return Vector3{
	lft.getX()*rght,
	lft.getY()*rght,
	lft.getZ()*rght
	};
}
void vector3::operator*=(Vector3& lft, const int& rght)
{	
	lft = lft * rght;
}


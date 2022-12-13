#include <iostream>

namespace vector3 
{
	
class Vector3
{
private:
	double _x,_y,_z;
public:
	Vector3(double x, double y, double z);
	double getX() const;
	double getY() const;
	double getZ() const;
};

Vector3 operator+(const Vector3& lft, const Vector3& rght);
void operator+=(Vector3& lft, const Vector3& rght);
Vector3 operator-(const Vector3& lft, const Vector3& rght);
void operator-=(Vector3& lft, const Vector3& rght);
Vector3 operator*(const Vector3& lft, const Vector3& rght);
void operator*=(Vector3& lft, const Vector3& rght);
Vector3 operator*(const Vector3& lft, const int& rght);
void operator*=(Vector3& lft, const int& rght);

}


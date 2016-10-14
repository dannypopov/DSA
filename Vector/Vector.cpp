#include "Vector.h"
#include <iostream>

Vector::Vector(double x, double y, double z) :m_x(x), m_y(y), m_z(z)
{
}

double Vector::length() const
{
	return sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
}

Vector& Vector::operator+(const Vector &other)
{
	Vector result;
	result.m_x = this->m_x + other.m_x;
	result.m_y = this->m_y + other.m_y;
	result.m_z = this->m_z + other.m_z;
	return result;
}

Vector & Vector::operator*=(double scalar)
{
	this->m_x *= scalar;
	this->m_y *= scalar;
	this->m_z *= scalar;
	return *this;
}

Vector & Vector::operator-=(const Vector &other)
{
	this->m_x = -this->m_x + other.m_x;
	this->m_y = -this->m_y + other.m_y;
	this->m_z = -this->m_z + other.m_z;
	return *this;
}

double & Vector::operator[](int index)
{
	double r = 0;
	if (index == 1)
	{
		return m_x;
	}
	if (index == 2)
	{
		return m_y;
	}
	if (index == 3)
	{
		return m_z;
	}
	else
	{
		return r;
	}
}

const double & Vector::operator[](int index) const
{
	double r = 0;
	if (index == 1)
	{
		return m_x;
	}
	if (index == 2)
	{
		return m_y;
	}
	if (index == 3)
	{
		return m_z;
	}
	else
	{
		return r;
	}
}

void Vector::normalize()
{
	m_x = length() / m_x;
	m_y = length() / m_y;
	m_z = length() / m_z;
}

double Vector::dot(const Vector &other) const
{
	double dotProduct;
	dotProduct = this->m_x*other.m_x + this->m_y*other.m_y + this->m_z*other.m_z;
	return dotProduct;
}

Vector & Vector::operator^=(const Vector &other)
{

	double _x;
	double _y;
	double _z;
	_x = this->m_y*other.m_z - this->m_z*other.m_y;
	_y = this->m_z*other.m_x - this->m_x*other.m_z;
	_z = this->m_x*other.m_y - this->m_y*other.m_x;
	Vector crossProduct(_x, _y, _z);
	return crossProduct;
}

float Vector::getAngle(const Vector &other) const
{
	float angle = 0;
	angle = (this->length()*other.length())/this->dot(other);
	return angle;
}

float Vector::getTriangleArea(const Vector &other) const
{
	float area;
	Vector tmp;
	tmp = other^*this;
	area = (tmp.length()) / 2;
	return area;
}

void Vector::Print() const
{
	std::cout << "x: " << m_x << std::endl;
	std::cout << "y: " << m_y << std::endl;
	std::cout << "z: " << m_z << std::endl;
}

double operator*(Vector lhs, const Vector &other)
{
	double dotProduct;
	dotProduct = lhs.m_x*other.m_x + lhs.m_y*other.m_y + lhs.m_z*other.m_z;
	return dotProduct;
}

Vector operator^(Vector lhs, const Vector &other)
{
	double _x;
	double _y;
	double _z;
	_x = lhs.m_y*other.m_z - lhs.m_z*other.m_y;
	_y = lhs.m_z*other.m_x - lhs.m_x*other.m_z;
	_z = lhs.m_x*other.m_y - lhs.m_y*other.m_x;
	Vector crossProduct(_x, _y, _z);
	return crossProduct;
}
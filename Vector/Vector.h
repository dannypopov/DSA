#ifndef VECTOR_H
#define VECTOR_H
class Vector
{
private:
	double m_x;
	double m_y;
	double m_z;
public:
	Vector(double x = 0, double y = 0, double z = 0);
	double length() const;
	Vector& operator+(const Vector&);
	Vector& operator*=(double); // return *this
	Vector& operator-=(const Vector&); // return *this
	double& operator[](int);
	const double& operator[](int) const;
	void normalize();
	double dot(const Vector&) const;
	friend double operator*(Vector, const Vector&);
	Vector& operator^=(const Vector&);
	friend Vector operator^(Vector, const Vector&);
	float getAngle(const Vector&) const;
	float getTriangleArea(const Vector&) const;
	void Print() const;
};
#endif // !VECTOR_H


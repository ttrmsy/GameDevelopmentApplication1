#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D() :x(0.0f), y(0.0f)
{

}

Vector2D::Vector2D(float scalar) :x(scalar), y(scalar)
{

}

Vector2D::Vector2D(float mx, float my) :x(mx), y(my)
{

}

Vector2D::~Vector2D()
{

}

Vector2D& Vector2D::operator=(const Vector2D& location)
{
	this->x = location.x;
	this->y = location.y;

	return *this;
}

const Vector2D Vector2D::operator+(const Vector2D& location) const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x + location.x;
	result.y = this->y + location.y;

	return result;
}

Vector2D& Vector2D::operator+=(const Vector2D& location)
{
	this->x += location.x;
	this->y += location.y;

	return *this;
}


const Vector2D Vector2D::operator-(const Vector2D& location) const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x + location.x;
	result.y = this->y + location.y;

	return result;
}

Vector2D& Vector2D::operator-=(const Vector2D& location)
{
	this->x += location.x;
	this->y += location.y;

	return *this;
}

const Vector2D Vector2D::operator*(const float& scalar) const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x * scalar;
	result.y = this->y * scalar;

	return result;
}

const Vector2D Vector2D::operator*(const Vector2D& location) const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x * location.x;
	result.y = this->y * location.y;

	return result;
}

Vector2D& Vector2D::operator*=(const float& scalar)
{
	this->x *= scalar;
	this->y *= scalar;

	return *this;
}

Vector2D& Vector2D::operator*=(const Vector2D& location)
{
	this->x /= location.x;
	this->y *= location.y;

	return *this;
}

const Vector2D Vector2D::operator/(const float& scalar) const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x / scalar;
	result.y = this->y / scalar;

	return result;
}

const Vector2D Vector2D::operator/(const Vector2D& location) const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x / location.x;
	result.y = this->y / location.y;

	return result;
}

Vector2D& Vector2D::operator/=(const float& scalar)
{
	this->x /= scalar;
	this->y /= scalar;

	return *this;
}

Vector2D& Vector2D::operator/=(const Vector2D& location)
{
	this->x /= location.x;
	this->y /= location.y;

	return *this;
}

void Vector2D::ToInt(int* x, int* y) const
{
	*x = static_cast<int>(this->x);
	*y = static_cast<int>(this->y);
}
#include "Vec2.hpp"
#include <ostream>

Vec2::Vec2()
    : m_x(0.0)
    , m_y(0.0)
{
}

Vec2::Vec2(double x, double y)
    : m_x(x)
    , m_y(y)
{
}

std::ostream& operator<<(std::ostream& os, const Vec2& v)
{
    os << "[ " << v.m_x << " " << v.m_y << " ]";
    return os;
}

Vec2 Vec2::operator+(const Vec2& other) const

{
    return Vec2(this->m_x + other.m_x, this->m_y + other.m_y);
}

Vec2 Vec2::operator-(const Vec2& other) const

{
    return Vec2(this->m_x - other.m_x, this->m_y - other.m_y);
}

Vec2 Vec2::operator/(const double& scalar) const

{
    return Vec2(this->m_x / scalar, this->m_y / scalar);
}
Vec2 Vec2::operator*(const double& scalar) const

{
    return Vec2(this->m_x * scalar, this->m_y * scalar);
}

Vec2 operator*(const double& scalar, const Vec2& v)
{
    return Vec2(v.m_x * scalar, v.m_y * scalar);
}

Vec2& Vec2::operator+=(const Vec2& other)
{
    this->m_x += other.m_x;
    this->m_y += other.m_y;
    return *this;
}
Vec2& Vec2::operator-=(const Vec2& other)
{
    this->m_x -= other.m_x;
    this->m_y -= other.m_y;
    return *this;
}
Vec2& Vec2::operator/=(const double& scalar)
{
    this->m_x /= scalar;
    this->m_y /= scalar;
    return *this;
}
Vec2& Vec2::operator*=(const double& scalar)
{
    this->m_x += scalar;
    this->m_y += scalar;
    return *this;
}
bool Vec2::operator==(const Vec2& other) const

{
    return (this->m_x==other.m_x)&&(this->m_y==other.m_y);
}
bool Vec2::operator!=(const Vec2& other) const

{
    return !(*this==other);
}
double Vec2::cross(const Vec2& v) const
{
    return this->m_x*v.m_y-this->m_y*v.m_x;
}

#ifndef VEC2_HPP
#define VEC2_HPP
#include <ostream>
class Vec2 {
public:
    double m_x, m_y;
    Vec2();
    Vec2(double x, double y);

    // ostream overloading
    friend std::ostream& operator<<(std::ostream& os, const Vec2& v);

    // operator overloading for vector2 addition and subtraction
    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-(const Vec2& other) const;

    // operator overloading for Scalar Multiplication and Division
    Vec2 operator/(const double& scalar) const;
    Vec2 operator*(const double& scalar) const;
    friend Vec2 operator*(const double& scalar, const Vec2& v);

    Vec2& operator+=(const Vec2& other);
    Vec2& operator-=(const Vec2& other);
    Vec2& operator/=(const double& scalar);
    Vec2& operator*=(const double& scalar);

    // operator overloading for logical
    bool operator==(const Vec2& other) const;
    bool operator!=(const Vec2& other) const;

    void setValue(double x,double y);
    void clear();

    double cross(const Vec2& other) const;
    static inline double cross(const Vec2& v1,const Vec2& v2);
    double dot(const Vec2& other)const;
    static inline double dot(const Vec2& v1,const Vec2& v2);

    double getLength()const;
    static inline double getLength(const Vec2& v);
    double getDistance(const Vec2& other)const;
    static inline double getDistance(const Vec2& v1,const Vec2& v2);

    void normalization();
    static inline void normalization(Vec2& v); 
    
};


#endif

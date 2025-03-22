#ifndef VEC3_HPP
#define VEC3_HPP
#include <ostream>
class Vec3 {
public:
    double m_x, m_y,m_z;
    Vec3();
    Vec3(double x, double y,double z);

    // ostream overloading
    friend std::ostream& operator<<(std::ostream& os, const Vec3& v);

    // operator overloading for vector2 addition and subtraction
    Vec3 operator+(const Vec3& other) const;
    Vec3 operator-(const Vec3& other) const;

    // operator overloading for Scalar Multiplication and Division
    Vec3 operator/(const double& scalar) const;
    Vec3 operator*(const double& scalar) const;
    friend Vec3 operator*(const double& scalar, const Vec3& v);

    Vec3& operator+=(const Vec3& other);
    Vec3& operator-=(const Vec3& other);
    Vec3& operator/=(const double& scalar);
    Vec3& operator*=(const double& scalar);

    // operator overloading for logical
    bool operator==(const Vec3& other) const;
    bool operator!=(const Vec3& other) const;

    void setValue(double x,double y,double z);
    void clear();

    Vec3 cross(const Vec3& other) const;
    static inline Vec3 cross(const Vec3& v1,const Vec3& v2);
    double dot(const Vec3& other)const;
    static inline double dot(const Vec3& v1,const Vec3& v2);

    double getLength()const;
    static inline double getLength(const Vec3& v);
    double getDistance(const Vec3& other)const;
    static inline double getDistance(const Vec3& v1,const Vec3& v2);

    void normalization();
    static inline void normalization(Vec3& v); 
    
};


#endif

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2D
{
    private:
        double x;
        double y;

    public:
        Vector2D();
        Vector2D(double x, double y);

        double getX() const;
        double getY() const;
        double getMagnitude() const;
        double getAngle() const;

        void setX(double x);
        void setY(double y);

        Vector2D operator+ (const Vector2D& other) const;
        Vector2D operator- (const Vector2D& other) const;
        Vector2D operator* (const double n) const;
        bool operator== (const Vector2D& other) const;
        bool operator!= (const Vector2D& other) const;
        double dotProduct(const Vector2D& other) const;
        double crossProduct(const Vector2D& other) const;
        Vector2D normalized() const;
        void normalize();
        void rotate(double theta);
        Vector2D rotated(double theta);

        std::string toString() const;
    
};

#endif 
#include "Vector2D.h"
#include <iostream>
#include <cmath>

Vector2D::Vector2D() {
    x = 0;
    y = 0;
}

Vector2D::Vector2D(double x_, double y_){
    x = x_;
    y = y_;
}

double Vector2D::getX() const {return x;}
double Vector2D::getY() const {return y;}

double Vector2D::getMagnitude() const {
    return sqrt(x*x + y*y);
}

double Vector2D::getAngle() const {
    return atan2(y, x);
}

void Vector2D::setX(double x_) {x = x_;}
void Vector2D::setY(double y_) {y = y_;}

Vector2D Vector2D::operator+ (const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator- (const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

Vector2D Vector2D::operator* (const double n) const {
    return Vector2D(x*n, y*n);
}

bool Vector2D::operator== (const Vector2D& other) const {
    return (x == other.x && y == other.y);
}

bool Vector2D::operator!= (const Vector2D& other) const {
    return (x != other.x || y != other.y);
}

double Vector2D::dotProduct(const Vector2D& other) const {
    return (x * other.x) + (y * other.y);
}

double Vector2D::crossProduct(const Vector2D& other) const {
    return (x * other.y) - (y * other.x);
}

Vector2D Vector2D::normalized() const {
    double mag = getMagnitude();
    return Vector2D(x / mag, y / mag);
}

void Vector2D::normalize() {
    double mag = getMagnitude();
    setX(x / mag);
    setY(y / mag);
}

void Vector2D::rotate(double theta) {
    double x_new = x * cos(theta) - y * sin(theta);
    double y_new = x * sin(theta) + y * cos(theta);
    setX(x_new);
    setY(y_new);
}

Vector2D Vector2D::rotated(double theta) {
    double x_new = x * cos(theta) - y * sin(theta);
    double y_new = x * sin(theta) + y * cos(theta);
    return Vector2D(x_new, y_new);
}

std::string Vector2D::toString() const {
    return "x: " + std::to_string(x) + ", y: " + std::to_string(y);
}

#include "Vector.hpp"
#include <cmath>

Vector::Vector() {}

Vector::Vector(double x, double y, double z) : components{x, y, z} {}

const double &Vector::operator[](unsigned int i) const {
  return components[i];
}

double &Vector::operator[](unsigned int i) { return components[i]; }

void Vector::multiply_by_scalar(double c) {
  components[0] = c * components[0];
  components[1] = c * components[1];
  components[2] = c * components[2];
}

void Vector::divide_by_scalar(double c) {
  components[0] = components[0] / c;
  components[1] = components[1] / c;
  components[2] = components[2] / c;
}

int Vector::size() const { return 3;}
double Vector::length() const { return sqrt(length_squared()); }

double Vector::length_squared() const {
  double lengthSquared{0.0};
  lengthSquared += components[0] * components[0];
  lengthSquared += components[1] * components[1];
  lengthSquared += components[2] * components[2];
  return lengthSquared;
}

double Vector::get_x() const { return components[0]; }

double Vector::get_y() const { return components[1]; }

double Vector::get_z() const { return components[2]; }

void Vector::normalize() {
  double lengthOfVector{length()};
  // This can lead to user error.  The user doesn't know that anything is wrong
  // and they assume that the vector is normalized.  But it isn't.
  // It is better to divide by zero and let the program crash.
  if (lengthOfVector == 0) {
    return;
  } else {
    divide_by_scalar(lengthOfVector);
  }
}

Vector operator+(const Vector &v1, const Vector &v2) {
  double xComponent{v1.get_x() + v2.get_x()};
  double yComponent{v1.get_y() + v2.get_y()};
  double zComponent{v1.get_z() + v2.get_z()};

  return Vector(xComponent, yComponent, zComponent);
}

Vector operator-(const Vector &v1, const Vector &v2) {
  double xComponent{v1.get_x() - v2.get_x()};
  double yComponent{v1.get_y() - v2.get_y()};
  double zComponent{v1.get_z() - v2.get_z()};

  return Vector(xComponent, yComponent, zComponent);
}

Vector cross_product(const Vector &vector1, const Vector &vector2) {
  double resultantXComponent{vector1[1] * vector2[2] - vector2[1] * vector1[2]};
  double resultantYComponent{vector1[2] * vector2[0] - vector2[2] * vector1[0]};
  double resultantZComponent{vector1[0] * vector2[1] - vector2[0] * vector1[1]};

  Vector resultantVector{resultantXComponent, resultantYComponent,
                           resultantZComponent};
  return resultantVector;
}

double dot_product(const Vector &vector1, const Vector &vector2) {
  double product1{vector1.get_x() * vector2.get_x()};
  double product2{vector1.get_y() * vector2.get_y()};
  double product3{vector1.get_z() * vector2.get_z()};

  return product1 + product2 + product3;
}

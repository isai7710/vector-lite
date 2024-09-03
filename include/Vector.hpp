#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <stddef.h>

class Vector {
public:
  // Constructors
  Vector(size_t size);
  Vector(const Vector &other);     // Copy constructor
  Vector(Vector &&other) noexcept; // Move constructor

  ~Vector();

  // Assignment operators
  Vector &operator=(const Vector &other);     // Copy assignment
  Vector &operator=(Vector &&other) noexcept; // Move assignment

  // Access and modification
  const double &operator[](size_t index) const;
  double &operator[](size_t index);

  // Utility methods
  int size() const;

  void multiply_by_scalar(double c); // These two should be * and / operators
  void divide_by_scalar(double c);

  double length() const;
  double length_squared() const;

  void normalize();

private:
  size_t size_;
  double *data_;
};

Vector operator+(const Vector &v1, const Vector &v2);
Vector operator-(const Vector &v1, const Vector &v2);
Vector cross_product(const Vector &vector1, const Vector &vector2);
double dot_product(const Vector &vector1, const Vector &vector2);

#endif

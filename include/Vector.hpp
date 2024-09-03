#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP
#include <array>

class Vector
{
public:
  Vector();
  Vector(double x, double y, double z);

  const double& operator[](unsigned int i) const;//You need to add this so that you can use the [] in your const functions.
  double& operator[](unsigned int i);


  void multiply_by_scalar(double c);//These two should be * and / operators
  void divide_by_scalar(double c);

  int size() const;
  double length() const;
  double length_squared() const;

  void normalize();

  double get_x() const;
  double get_y() const;
  double get_z() const;

protected:
  std::array<double,3> components{0.0,0.0,0.0};
};

Vector operator+(const Vector &v1, const Vector &v2);
Vector operator-(const Vector &v1, const Vector &v2);
Vector cross_product(const Vector& vector1, const Vector& vector2); //ASK ABOUT const and &
double dot_product(const Vector& vector1, const Vector& vector2);

#endif

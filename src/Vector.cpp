#include "Vector.hpp"
#include <cmath>
#include <cstring>

// important note on data_(new double[size])
// - data_: a pointer to a double
// - new double[size]:
//    this dynamically allocates a block of memory large enough to hold 'size'
//    number of 'double' values and returns the pointer to the first element of
//    this array

// Visualization of what this does to the data_ variable:
/*    new double[size]:  [    ][    ][    ][    ]  ... (size elements)     */
/*                         ^     */
/*                         |     */
/*    data_: --------------+     */

Vector::Vector(size_t size) : size_(size), data_(new double[size]) {}

Vector::Vector(const Vector &other)
    : size_(other.size_), data_(new double[other.size_]) {
  for (size_t i = 0; i < size_; i++) {
    data_[i] = other.data_[i];
  }
}

Vector::Vector(Vector &&other) noexcept
    : size_(other.size_), data_(other.data_) {
  other.size_ = 0;
  other.data_ = nullptr;
}

Vector::~Vector() { delete[] data_; }

int Vector::size() const { return size_; }

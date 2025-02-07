/**
 * @file Vector.h
 * @author Tyson Arnold
 * @date 2025-02-07
 * @brief Vector Header File
 *
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
 private:
  int *vec_ptr;
  int vec_size, vec_capacity;

 public:
  Vector();
  Vector(const Vector &other);
  ~Vector();
  Vector& operator=(const Vector &other);

  int size();
  int capacity();
  void push_back(int element);
  void reserve(int n);
  int& operator[](unsigned int index);
};

#endif

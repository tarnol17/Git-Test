/**
 * @file Vector.cpp
 * @author Tyson Arnold
 * @date 2025-02-07
 *
 */

#include "Vector.h"

/**
 * @brief Default costructor. Initalizes an empty vector
 */
Vector::Vector(){
  vec_ptr = nullptr;
  vec_size = 0;
  vec_capacity = 0;
}

/**
 * @brief Initalizes a dynamic array of the right size and capacity
 * and copies data from other array to the new one
 *
 */
Vector::Vector(const Vector %other){
  vec_size = other.vec_size;
  vec_capacity = other.vec_capacity;
  vec_ptr = new int[vec_capacity];
  for(int i = 0; i < vec_size; i++){
    vec_ptr[i] = other.vec_ptr[i];
  }
}

/**
 * @brief Deallocates the vec+ptr
 */
Vector::~Vector(){
  delete[] vec_ptr;
}

/**
 * @brief Initalizes dynamic array of appropriate size and copies data 
 */
Vector& Vector::operator=(const Vector &other){
  if (this != &other){
    delete[] vec_ptr;
    vec_size = other vec_size;
    vec_capacity = other.vec_capacity;
    vec_ptr = new int[vec_capacity];
    for(int i =0; i < vec_size; i++){
      vec_ptr[i] = other.vec_ptr[i];
    }
    return *this;
  }
}

/**
 * @brief Returns numbers of elements in size
 */
int Vector::size(){
  return vec_size;
}

/**
 * @brief Returns number of elements in capacity
 */
int Vector::capacity(){
  return vec_capacity;
}

/**
 * @brief Store element at the end of the vector
 */
void Vector::push_back(int element){
  if(vec_size == vec_capacity){
    int new_cap = 1;
    if (vec_capacity > 0){
      new_cap = vec_capacity * 2;
    }
    reserve(new_cap);
  }
  vec_ptr[vec_size++] = element;
}

/**
 * @brief Requests that the vector capacity  be resized to contain
 * all the elements
 */
void Vector::reserve(int n){
  if (n > vec(capacity){
      int* new_ptr = new int[n];
      for(int i = 0; i < vec_size; i++){
	new_ptr[i] = vec_ptr[i];
      }
      delete[] vec_ptr;
      vec_ptr = new_ptr;
      vec_capacity = n;
    }
}
  
/**
 * @brief Returns reference to the element in at the position
 */
int& Vector::operator[](unsigned int index){
  return vec_ptr[index];
}
  



   

#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector {
    T* arr;
    unsigned int arrSize;
    unsigned int vecSize;
  public:
    Vector();
    void push(T);
    T& operator[](unsigned int);
    unsigned int size();
    bool empty();
};

#include "vector.cpp"

#endif

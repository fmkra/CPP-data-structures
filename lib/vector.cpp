#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "vector.h"

template<typename T>
Vector<T>::Vector() {
    arr = new T[1];
    arrSize = 1;
    vecSize = 0;
}

template<typename T>
void Vector<T>::push(T v) {
    if(arrSize == vecSize) {
        T* tmp = new T[2*arrSize];
        for(int i = 0; i < arrSize; i++)
            tmp[i] = arr[i];
        delete[] arr;
        arrSize *= 2;
        arr = tmp;
    }
    arr[vecSize] = v;
    vecSize++;
}

template<typename T>
T& Vector<T>::operator[](unsigned int index) {
    return arr[index];
}

template<typename T>
unsigned int Vector<T>::size() {
    return vecSize;
}

template<typename T>
bool Vector<T>::empty() {
    return vecSize == 0;
}

#endif

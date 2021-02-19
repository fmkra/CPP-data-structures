#ifndef VECTOR_CPP
#define VECTOR_CPP

template<typename T>
class Vector {
    T* arr;
    unsigned int arrSize;
    unsigned int vecSize;
  public:
    Vector() {
        arr = new T[1];
        arrSize = 1;
        vecSize = 0;
    }
    void push_back(T v) {
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
    T& operator[](unsigned int index) {
        return arr[index];
    }
    unsigned int size() const {
        return vecSize;
    }
    bool empty() const {
        return vecSize == 0;
    }
    class iterator {
        T* curr;
      public:
        iterator(const iterator& other) {
          this -> curr = other.curr;
        }
        iterator(T* pointer) {
          curr = pointer;
        }
        T operator*() {
            return *curr;
        }
        iterator& operator++() {
            curr++;
            return *this;
        }
        iterator operator++(int) {
            T tmp = *this;
            curr++;
            return tmp;
        }
        bool operator!=(const iterator& other) {
            return other.curr != this->curr;
        }
        bool operator==(const iterator& other) {
            return other.curr == this->curr;
        }
    };

    iterator begin() const {
      return iterator(arr);
    }
    iterator end() const {
      return iterator(arr+vecSize);
    }
};

#endif

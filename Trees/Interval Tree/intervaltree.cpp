#ifndef INTERVALTREE_CPP
#define INTERVALTREE_CPP
// those lines prevent 'redefinition of variable' error

#include <limits>
#include <iostream>

template <typename T>
struct IntervalTreeOperation {
  struct Sum {
    static const T identityElement = 0;
    static T operation(const T& a, const T& b) {
      return a+b;
    }
  };
  struct Max {
    static const T identityElement = std::numeric_limits<T>::min();
    static T operation(const T& a, const T& b) {
      return std::max(a,b);
    }
  };
  struct Min {
    static const T identityElement = std::numeric_limits<T>::max();
    static T operation(const T& a, const T& b) {
      return std::min(a,b);
    }
  };
  struct Product {
    static const T identityElement = 1;
    static T operation(const T& a, const T& b) {
      return a*b;
    }
  };
  struct Xor {
    static const T identityElement = 0;
    static T operation(const T& a, const T& b) {
      return a^b;
    }
  };
};

template<
  typename T,
  class Operation = typename IntervalTreeOperation<T>::Sum
>
class IntervalTree {
  unsigned int _size; // number of elements in tree
  unsigned int _width; // number of leaves (lowest power of 2 greater or equal to _size)
  unsigned int _height; // height of a tree ( log2(_width)+1 )
  T* d;

  T query(unsigned int a, unsigned int b, unsigned int v, unsigned int p, unsigned int q) {
    if(q<a || p>b) return Operation::identityElement;
    if(p>=a && q<=b) return d[v];
    unsigned int r = (p+q)/2;
    return Operation::operation(
      query(a,b,2*v,p,r),
      query(a,b,2*v+1,r+1,q)
    );
  }
public:
  // constructor from size
  IntervalTree(const unsigned int size = 0, T fill = Operation::identityElement, T fillrest = Operation::identityElement) {
    _size = size;
    _width = 1;
    _height = 1;
    while(_width<size) {
      _width*=2;
      _height++;
    }
    d = new T[2*_width];
    for(unsigned int i=0;i<_size;i++) d[_width+i]=fill;
    for(unsigned int i=_size;i<_width;i++) d[_width+i]=fillrest;
    for(unsigned int i=_width-1;i>0;i--) d[i]=Operation::operation(d[2*i],d[2*i+1]);
  }
  // constructor from array
  IntervalTree(const T* array, const unsigned int size, T fillrest = Operation::identityElement) {
    _size = size;
    _width = 1;
    _height = 1;
    while(_width<size) {
      _width*=2;
      _height++;
    }
    d = new T[2*_width];
    for(unsigned int i=0;i<_size;i++) d[_width+i]=array[i];
    for(unsigned int i=_size;i<_width;i++) d[_width+i]=fillrest;
    for(unsigned int i=_width-1;i>0;i--) d[i]=Operation::operation(d[2*i],d[2*i+1]);
  }
  T query(unsigned int p, unsigned int q) {
    return query(p,q,1,1,_width);
  }
  void set(unsigned int p, T x) {
    d[p+=_width-1]=x;
    while(p/=2) d[p]=Operation::operation(d[2*p],d[2*p+1]);
  }
  void push_back(T x) {
    if(_size++<_width) {
      set(_size,x);
      return;
    }
    T* tmp = new T[_width];
    for(unsigned int i=0;i<_width;i++) tmp[i]=d[_width+i];
    _width*=2;
    d = new T[2*_width];
    for(unsigned int i=0;i<_width/2;i++) d[_width+i]=tmp[i];
    delete[] tmp;
    d[3*_width/2]=x;
    for(unsigned int i=_width/2+1;i<_width;i++) d[_width+i]=Operation::identityElement;
    for(unsigned int i=_width-1;i>0;i--) d[i]=Operation::operation(d[2*i],d[2*i+1]);
  }
  void print() {
    unsigned int p = 2;
    for(unsigned int i=1;i<2*_width;i++) {
      std::cout<<d[i]<<" ";
      if(i==p-1) {
        std::cout<<"\n";
        p*=2;
      }
    }
  }
};

#endif

#include <cstddef>
#include <iostream>
#include <assert.h>

template<typename T>
class Matrix {
  T** m;
public:
  size_t rows,cols;

  T* operator[](int i) {
    return m[i];
  }

  Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
    m = new T*[rows];
    for(int i=0;i<rows;i++) m[i] = new T[cols];
  }
  Matrix(size_t rows, size_t cols, T fill) : rows(rows), cols(cols) {
    m = new T*[rows];
    for(int i=0;i<rows;i++) {
      m[i] = new T[cols];
      for(int j=0;j<cols;j++) m[i][j]=fill;
    }
  }
  Matrix(size_t rows, size_t cols, T** arr) : rows(rows), cols(cols) {
    m = new T*[rows];
    for(int i=0;i<rows;i++) {
      m[i] = new T[cols];
      for(int j=0;j<cols;j++) m[i][j]=arr[i][j];
    }
  }
  template<size_t rows, size_t cols>
  static Matrix fromArray(T arr[rows][cols]) {
    Matrix<T> m(rows,cols);
    for(int i=0;i<rows;i++) for(int j=0;j<cols;j++) m[i][j]=arr[i][j];
    return m;
  }
  void print() {
    for(int i=0;i<rows;i++) {
      for(int j=0;j<cols;j++) std::cout<<m[i][j]<<" ";
      std::cout<<"\n";
    }
  }

  static Matrix multiply(Matrix& a, Matrix& b) {
    assert(a.cols==b.rows);
    Matrix c(a.rows,b.cols,0);
    for(int i=0;i<a.rows;i++) {
      for(int j=0;j<b.cols;j++) {
        for(int k=0;k<a.cols;k++) {
          c[i][j] += a[i][k]*b[k][j];
        }
      }
    }
    return c;
  }
  static Matrix cinAdjacencyMatrix(unsigned int vertices, unsigned int edges) {
    Matrix<T> m(vertices,vertices,0);
    unsigned int a,b;
    while(edges--) {
      std::cin>>a>>b;
      m[a-1][b-1]=1;
    }
    return m;
  }
};

#include <bits/stdc++.h>
using namespace std;

int main() {

}

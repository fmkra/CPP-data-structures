#include "intervaltree.cpp"

int main() {
  IntervalTree<int,IntervalTreeOperation<int>::Max> a(4,0);
  a.print();
  a.push_back(4);
  a.print();
}

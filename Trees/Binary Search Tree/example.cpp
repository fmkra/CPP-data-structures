#include "../../include/bstree"
#include "../../include/bstreeprinter"
#include <iostream>

int main() {
  BSTree<int> t;
  t.insert(8);
  t.insert(4);
  t.insert(2);
  t.insert(1);
  t.insert(3);
  t.insert(6);
  t.insert(5);
  t.insert(7);
  t.insert(12);
  t.insert(10);
  t.insert(9);
  t.insert(11);
  t.insert(14);
  t.insert(13);
  t.insert(15);
  BSTreePrinter<int>::print(t);
}

#include "../../include/intervaltree"

int main() {
  int array[8] = {1,4,-2,7,0,2,3,2};
  IntervalTree<int> tree(array,8); // Sum tree created from array

  std::cout << tree.query(2,6) << "\n"; // answer is 11 (4-2+7+0+2)
  std::cout << tree.query(4,7) << "\n"; // answer is 12 (7+0+2+3)
  tree.set(5,6); // sets 5th element to 6
  std::cout << tree.query(4,7) << "\n"; // answer is 18 (7+6+2+3)
}

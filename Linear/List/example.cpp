#include "../../include/list"
#include <iostream>

int main() {
    List<int> l;
    l.push_front(3); // list: 3
    l.push_front(2); // list: 2 3
    l.push_back(4);  // list: 2 3 4
    l.push_back(5);  // list: 2 3 4 5
    l.push_front(1); // list: 1 2 3 4 5
    std::cout << l.front() << "\n"; // prints 1
    std::cout << l.back() << "\n";  // prints 5
    l.pop_front(); // list: 2 3 4 5
    l.pop_back();  // list: 2 3 4
    l.pop_front(); // list: 3 4
    std::cout << l.front() << "\n"; // prints 3
    std::cout << l.back() << "\n";  // prints 4
}

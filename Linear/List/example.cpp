#include "../../include/list"
#include <iostream>

int main() {
    List<int> l;
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);
    std::cout << l.front() << " " << l.back() << "\n";
}

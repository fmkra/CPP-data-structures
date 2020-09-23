#include "../lib/list.cpp"
#include <iostream>

int main() {
    List<int> l;
    l.push_front(2);
    std::cout << l.front() << " " << l.back();
}

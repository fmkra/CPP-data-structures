#include <iostream>
#include "../../include/queue"

Queue<int> q;

int main() {
    q.push(2); // queue: 2
    q.push(4); // queue: 4 2
    q.push(3); // queue: 3 4 2
    std::cout << q.front() << " " << q.back() << "\n"; // prints: 3 2
    q.push(1); // queue: 1 3 4 2
    q.pop();   // queue: 1 3 4
    std::cout << q.front() << " " << q.back() << "\n"; // prints: 1 4
}

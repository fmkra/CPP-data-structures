#include "../lib/stack.h"
#include <iostream>

int main() {
    Stack<int> s;

    s.push(4); // 4
    s.push(1); // 1 4
    s.pop();   // 4
    s.push(3); // 3 4
    std::cout << s.top() << "\n";
    s.push(2); // 2 3 4

    for(Stack<int>::iterator i = s.begin(); i != s.end(); ++i)
        std::cout << *i << " ";
}

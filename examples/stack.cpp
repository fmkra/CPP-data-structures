#include "../lib/stack.h" // replace ../ with path to the library folder
#include <iostream> // iostream for printing

int main() {
    Stack<int> s; // stack with int elements declaration

    s.push(4); // push 4 on the top
    // now stack looks like this: 
    //  4
    
    s.push(1); // push 1 on the top
    // now like this:
    //  1
    //  4
    
    s.push(2); // push 2 on the top
    //  2
    //  1
    //  4
    
    s.pop(); // pop the top element (2)
    //  1
    //  4
    
    s.push(3); // push 3 on the top
    //  3
    //  1
    //  4
    
    std::cout << s.top() << "\n"; // print the top element (3)
    
    s.push(5); // push 5 on the top
    //  5
    //  3
    //  1
    //  4
    
    std::cout << s.top() << "\n"; // print the top element (5)

    // printing stack using pop() and size()
    Stack<int> s1 = s; // create a copy of s, because printing using pop() removes every element from the stack
    for(int i = 0; i < s1.size(); i++) { // loop as many times as size of the stack
        std::cout << s1.top() << "\n"; // print the top element
        s1.pop(); // remove top element
    }
    
    // printing stack using pop() and empty()
    Stack<int> s2 = s; // create a copy of s, because printing using pop() removes every element from the stack
    while(!s2.empty()) { // while the stack is not empty
        std::cout << s2.top() << "\n"; // print the top element
        s2.pop(); // remove top element
    }
    
    // printing stack using iterator (recommended way)
    for(Stack<int>::iterator i = s.begin(); i != s.end(); ++i) { // create iterator, start on s.begin(), end on s.end(), and move iterator every time
        std::cout << *i << "\n"; // print the value pointed by the iterator
    }
}

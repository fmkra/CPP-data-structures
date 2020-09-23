# Basic-Data-Structures

## Table of contents
- [Stack](#stack)
  - [Template arguments](#template-arguments)
  - [Functions](#functions)
  - [Usage](#usage)
---

## Stack

### Template arguments
`T` - Type of elements.

### Functions

#### push

Return: `none`
<br>
Arguments: `T`

Pushes element with a given value on the top of a stack.

#### pop

Return: `none`
<br>
Arguments: `none`

Removes element from the top of a stack.

#### top

Return: `T`
<br>
Arguments: `none`

Gets value of the top element.

#### size

Return: `unsigned int`
<br>
Arguments: `none`

Gets size of the stack.

#### empty

Return: `bool`
<br>
Arguments: `none`

Returns whether the stack is empty.

#### begin
Return: `iterator`
<br>
Arguments: `none`

Returns iterator object to the first element.

#### end
Return: `iterator`
<br>
Arguments: `none`

Returns iterator object to the element past the last.

### Usage

Library include
```
#include "path/to/Basic-Data-Structures/lib/stack.h"
```

Stack declaration
```
Stack<int> s;
```

Basic `push`, `pop` and `top` usage
```
s.push(4);                      // stack:  4
s.push(1);                      // stack:  1 4
s.pop();                        // stack:  4
s.push(3);                      // stack:  3 4
std::cout << s.top() << "\n";   // prints: 3
s.push(2);                      // stack:  2 3 4
std::cout << s.top() << "\n";   // prints: 2
```

Printing stack using `size` and `pop`
```
for(int i = 0; i < s.size(); i++) {
    std::cout << s.top() << "\n";
    s.pop();
}
```

Printing stack using `empty` and `pop`
```
while(!s.empty()) {
    std::cout << s.top() << "\n";
    s.pop();
}
```

Printing stack using `iterator`
```
for(Stack<int>::iterator i = s.begin(); i != s.end(); ++i) {
    cout << *i << "\n";
}
```

[Full example code](examples/stack.cpp)

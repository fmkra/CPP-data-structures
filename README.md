# Basic-Data-Structures

## Table of contents
- [Stack](#stack)
  - [Template arguments](#template-arguments)
  - [Functions](#functions)
  - [Usage](#usage)
- [List](#list)
  - [Template arguments](#template-arguments-1)
  - [Functions](#functions-1)
  - [Usage](#usage-1)
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
```c++
#include "path/to/Basic-Data-Structures/lib/stack.h"
```

Stack declaration
```c++
Stack<int> s;
```

Basic `push`, `pop` and `top` usage
```c++
s.push(4);                      // stack:  4
s.push(1);                      // stack:  1 4
s.pop();                        // stack:  4
s.push(3);                      // stack:  3 4
std::cout << s.top() << "\n";   // prints: 3
s.push(2);                      // stack:  2 3 4
std::cout << s.top() << "\n";   // prints: 2
```

Printing stack using `size` and `pop`
```c++
for(int i = 0; i < s.size(); i++) {
    std::cout << s.top() << "\n";
    s.pop();
}
```

Printing stack using `empty` and `pop`
```c++
while(!s.empty()) {
    std::cout << s.top() << "\n";
    s.pop();
}
```

Printing stack using `iterator`
```c++
for(Stack<int>::iterator i = s.begin(); i != s.end(); ++i) {
    cout << *i << "\n";
}
```

[Full example code](examples/stack.cpp)




## List

### Template arguments
`T` - Type of elements.

### Functions

#### push_front

Return: `none`
<br>
Arguments: `T`

Pushes element with a given value in the front of a list.

#### push_back

Return: `none`
<br>
Arguments: `T`

Pushes element with a given value in the back of a list.

#### front

Return: `none`
<br>
Arguments: `none`

Gets value of the front element.

#### back

Return: `T`
<br>
Arguments: `none`

Gets value of the back element.

#### size

Return: `unsigned int`
<br>
Arguments: `none`

Gets size of the list.

#### empty

Return: `bool`
<br>
Arguments: `none`

Returns whether the list is empty.

#### begin
Return: `iterator`
<br>
Arguments: `none`

Returns iterator object to the front element.

#### end
Return: `iterator`
<br>
Arguments: `none`

Returns iterator object to past the back element.

### Usage

Library include
```c++
#include "path/to/Basic-Data-Structures/lib/list.h"
```

List declaration
```c++
List<int> l;
```

Basic `push_front`, `push_back`, `front` and `back` usage
```c++

```

Printing list using `iterator`
```c++
for(List<int>::iterator i = l.begin(); l != s.end(); ++l) {
    cout << *l << "\n";
}
```

[Full example code](examples/list.cpp)

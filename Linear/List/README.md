# List

## Template arguments
`T` - Type of elements.

## Functions

### push_front

Return: `none`
<br>
Arguments: `T`

Pushes element with a given value to the front.

### push_back

Return: `none`
<br>
Arguments: `T`

Pushes element with a given value to the back.

### pop_front

Return: `none`
<br>
Arguments: `none`

Removes element from the front.

### pop_back

Return: `none`
<br>
Arguments: `none`

Removes element from the back.

### front

Return: `T`
<br>
Arguments: `none`

Returns front element.

### back

Return: `T`
<br>
Arguments: `none`

Returns back element.

### size

Return: `unsigned int`
<br>
Arguments: `none`

Returns size of the list.

### empty

Return: `bool`
<br>
Arguments: `none`

Returns whether the list is empty.

### begin
Return: `iterator`
<br>
Arguments: `none`

Returns iterator object to the front element.

### end
Return: `iterator`
<br>
Arguments: `none`

Returns iterator object to past the back element.

## Usage

Library include
```c++
#include "path/to/Basic-Data-Structures/include/list"
```

List declaration
```c++
List<int> l;
```

Basic `push_front`, `push_back`, `pop_front`, `pop_back`, `front` and `back` usage
```c++
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
```

Print list using `empty`, `front` and `pop_front`
```c++
while(!l.empty()) {
    std::cout << l.front() << "\n";
    l.pop_front();
}
```

Print stack using `iterator` (recommended way)
```c++
for(List<int>::iterator i = l.begin(); i != l.end(); ++i) {
    std::cout << *i << "\n";
}
```

Print list using `iterator` with `range-based for loop` and `auto` (recommended way for C++11 and higher)
```c++
for(auto i : l) {
    std::cout << i << "\n";
}
```

[Full example code](example.cpp)

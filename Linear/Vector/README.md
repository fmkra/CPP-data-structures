# Vector

## Template arguments
`T` - Type of elements.

## Functions

### push_back
Return: `none`
<br>
Arguments: `T`

Adds an element to the back.

### operator[]
Return: `T`
<br>
Arguments: `unsigned int`

Access specified element.

### size
Return: `unsigned int`
<br>
Arguments: `none`

Returns the number of elements.

### empty
Return: `bool`
<br>
Arguments: `none`

Returns whether the vector is empty.

### begin
Return: `iterator`
<br>
Arguments: `none`

Returns an iterator to the begining.

### end
Return: `iterator`
<br>
Arguments: `none`

Returns an iterator to the end.

## Usage

Library include
```c++
#include "path/to/Basic-Data-Structures/include/vector"
```

Vector declaration
```c++
Vector<int> v;
```

Basic `push_back` and `operator[]` usage
```c++
v.push_back(3);  // vector: 3
v.push_back(7);  // vector: 3 7
v.push_back(-2); // vector: 3 7 -2
v[1] = 4;        // vector: 3 4 -2
std::cout << v[2] << "\n"; // prints -2
std::cout << v[1] << "\n"; // prints 4
```

Print vector using `size` and `operator[]`
```c++
for(int i = 0; i < v.size(); i++) {
    std::cout << v[i] << "\n";
}
```

Print vector using `iterator` with `range-based for loop` and `auto` (C++11)
```c++
for(auto i : v) {
    std::cout << i << "\n";
}
```

[Full example code](example.cpp)

# Disjoint-set

## Constructors

`()` - Constructs structure with 0 sets.
<br>
`(unsigned int)` - Constructs structure with given number of sets.

## Functions

### makeSet
Return: `unsigned int`
<br>
Arguments: `none`

Adds new element to the structure and returns its id.

### find
Return: `unsigned int`
<br>
Arguments: `unsigned int`

Returns representative's id of the element with the given id.

### merge
Return: `none`
<br>
Arguments: `unsigned int`, `unsigned int`

Merges sets to which given elements belong.

### size
Return: `unsigned int`
<br>
Arguments: `none`

Returns number of elements in the structure.

## Usage

Library include
```c++
#include "path/to/Basic-Data-Structures/include/disjoint_set"
```
Disjoint-set declaration
```c++
DisjointSet s;    // size 0
DisjointSet s(5); // size 5
```
Basic `find` and `merge` usage
```c++
// {1} {2} {3} {4} {5}
std::cout << s.find(1) == s.find(2) << "\n"; // false
s.merge(1,2); // {1} {2} => {1,2}
// {1,2} {3} {4} {5}
std::cout << s.find(1) == s.find(2) << "\n"; // true
std::cout << s.find(2) == s.find(4) << "\n"; // false
s.merge(1,4); // {1,2} {4} => {1,2,4}
// {1,2,4} {3} {5}
std::cout << s.find(2) == s.find(4) << "\n"; // true
```
[Full example code](example.cpp)

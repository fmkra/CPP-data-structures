# Basic Data Structures

## Table of content
- Linear
  - [Stack](#stack)
    - [Template arguments](#template-arguments)
    - [Functions](#functions)
    - [Usage](#usage)
  - [Queue](#queue)
    - [Template arguments](#template-arguments-1)
    - [Functions](#functions-1)
    - [Usage](#usage-1)
  - [List](#list)
    - [Template arguments](#template-arguments-2)
    - [Functions](#functions-2)
    - [Usage](#usage-2)
  - [Vector](#vector)
    - [Template arguments](#template-arguments-3)
    - [Functions](#functions-3)
    - [Usage](#usage-3)
- Trees
  - [Binary Search Tree](#binary-search-tree)
    - [Template arguments](#template-arguments-4)
    - [Functions](#functions-4)
    - [Usage](#usage-4)
  - [Interval Tree](#interval-tree)
    - [Template arguments](#template-arguments-5)
    - [Constructors](#constructors)
    - [Functions](#functions-5)
    - [Operations](#operations)
    - [Usage](#usage-5)
- Other
  - [Disjoint-set](#disjoint-set)
    - [Constructors](#constructors-1)
    - [Functions](#functions-6)
    - [Usage](#usage-6)

---

# Stack

[Documentation in separate file](Linear/Stack)

## Template arguments
`T` - Type of elements.

## Functions

### push

Return: `none`
<br>
Arguments: `T`

Pushes element with a given value on the top of a stack.

### pop

Return: `none`
<br>
Arguments: `none`

Removes element from the top of a stack.

### top

Return: `T`
<br>
Arguments: `none`

Gets value of the top element.

### size

Return: `unsigned int`
<br>
Arguments: `none`

Gets size of the stack.

### empty

Return: `bool`
<br>
Arguments: `none`

Returns whether the stack is empty.

### begin
Return: `iterator`
<br>
Arguments: `none`

Returns iterator object to the first element.

### end
Return: `iterator`
<br>
Arguments: `none`

Returns iterator object to the element past the last.

## Usage

Library include
```c++
#include "path/to/Basic-Data-Structures/include/stack"
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

Print stack using `empty`, `top` and `pop`
```c++
while(!s.empty()) {
    std::cout << s.top() << "\n";
    s.pop();
}
```

Print stack using `iterator` (recommended way)
```c++
for(Stack<int>::iterator i = s.begin(); i != s.end(); ++i) {
    std::cout << *i << "\n";
}
```

Print stack using `iterator` with `range-based for loop` and `auto` (recommended way for C++11 and higher)
```c++
for(auto i : s) {
    std::cout << i << "\n";
}
```

[Full example code](Linear/Stack/example.cpp)

---

# Queue

[Documentation in separate file](Linear/Queue)

## Template arguments
`T` - Type of elements.

## Functions

### push

Return: `none`
<br>
Arguments: `T`

Pushes element with a given value to the front.

### pop

Return: `none`
<br>
Arguments: `none`

Removes element from the back.

### front

Return: `T`
<br>
Arguments: `none`

Gets value of the front element.

### back

Return: `T`
<br>
Arguments: `none`

Gets value of the back element.

### size

Return: `unsigned int`
<br>
Arguments: `none`

Gets size of the queue.

### empty

Return: `bool`
<br>
Arguments: `none`

Returns whether the queue is empty.

## Usage

Library include
```c++
#include "path/to/Basic-Data-Structures/include/queue"
```

Queue declaration
```c++
Queue<int> q;
```

Basic `push`, `pop`, `front` and `back` usage
```c++
q.push(2); // queue: 2
q.push(4); // queue: 4 2
q.push(3); // queue: 3 4 2
std::cout << q.front() << " " << q.back() << "\n"; // prints: 3 2
q.push(1); // queue: 1 3 4 2
q.pop();   // queue: 1 3 4
std::cout << q.front() << " " << q.back() << "\n"; // prints: 1 4
```

[Full example code](Linear/Queue/example.cpp)

---

# List

[Documentation in separate file](Linear/List)

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

[Full example code](Linear/List/example.cpp)

---

# Vector

[Documentation in separate file](Linear/Vector)

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

[Full example code](Linear/Vector/example.cpp)

---

# Binary Search Tree

[Documentation in separate file](Trees/Binary%20Search%20Tree)

## Template arguments
`T` - Type of elements.

## Functions

### insert

Return type: `none`
<br>
Arguments: `T`

Inserts a given value to the tree.

### search

Return type: `bool`
<br>
Arguments: `T`

Returns whether a given value exist in the tree.

### remove

Return type: `none`
<br>
Arguments: `T`

Removes given value from the tree if it exist.

## Usage

Library include
```c++
#include "path/to/Basic-Data-Structures/include/bstree"
```

BSTree declaration
```c++
BSTree<int> l;
```

Insertion
```c++
tree.insert(2);
tree.insert(4);
tree.insert(1);
tree.insert(5);
tree.insert(3);
/*
      now tree looks like this:

        2
       / \
      1   4
         / \
        3   5
*/
```

### Printing

You can print BSTree using BSTreePrinter class.
Library include:
```c++
#include "path/to/Basic-Data-Structures/include/bstreeprinter"
```
Available functions:
```c++
static void print(BSTree<T>*);
static void print(BSTree<T>&);
```
Example:
```c++
BSTree<int> t;
// some insert operations here
BSTreePrinter<int>::print(t); // tree object passed by reference
```
or
```c++
BSTreePrinter<int>::print(&t); // tree object passed by pointer
```

[Full example code](Trees/Binary%20Search%20Tree/example.cpp)

---

# Interval Tree

[Documentation in separate file](Trees/Interval%20Tree)

## Template arguments

`T` - Type of elements
<br>
`Operation` - Struct that defines what operation tree uses [More here](#operations)

## Constructors

`()` - Constructs tree of size 0
<br>
`(unsigned int size)` - Constructs tree of a given `size`
<br>
`(unsigned int size, T fill)` - Constructs tree of a given `size` and fills it with `fill` value
<br>
`(const T* array, unsigned int size)` - Constructs tree from an `array`

## Functions

### push_back
Return: `none`
<br>
Arguments: `T`

Adds an element to the end.

### set
Return: `none`
<br>
Arguments: `unsigned int`, `T`

Changes element on a given position.

### query
Return: `T`
<br>
Arguments: `unsigned int`, `unsigned int`

Returns answer for query on interval `[p,q]`.

### size
Return: `unsigned int`
<br>
Arguments: `none`

Returns size of the tree.

### empty
Return: `bool`
<br>
Arguments: `none`

Returns whether the tree is empty.

### print
Return: `none`
<br>
Arguments: `none`

Prints whole tree using `std::cout`.


## Operations

Interval tree can do every <a href="https://en.wikipedia.org/wiki/Associative_property" target="_blank">associative operation</a>. Those are implemented operations:
- addition - `IntervalTreeOperation<T>::Sum`
- maximum - `IntervalTreeOperation<T>::Max`
- minimum - `IntervalTreeOperation<T>::Min`
- multiplication - `IntervalTreeOperation<T>::Product`
- bitwise xor - `IntervalTreeOperation<T>::Xor`

To implement custom operation, struct with `operation` method and `identityElement` attribute must be passed as the second template argument. Static function `operation` takes 2 arguments (either passed by value or reference) and returns one value. They must all be of the same type. Static constant variable `identityElement` is a value that for every x `operation(x,identityElement) = x`, for example 0 is indentity element for addition.

```c++
static T operation(T a, T b); // pass by value
static T operation(const T &a, const T &b); // pass by reference
static const T identityElement;
```

Here is an example that implements *bitwise and* operation for integers:
```c++
struct BitwiseAnd {
  static const int identityElement = 0;
  static int operation(int a, int b) {
    return a^b;
  }
};
IntervalTree<int,BitwiseAnd> tree;
```

## Usage

Library include
```c++
#include "path/to/Basic-Data-Structures/include/intervaltree"
```
Tree declaration
```c++
IntervalTree<int> tree; // Sum operation by default
IntervalTree<int,IntervalTreeOperation<int>::Sum> tree; // Sum
IntervalTree<int,IntervalTreeOperation<int>::Max> tree; // Maximum
IntervalTree<int,IntervalTreeOperation<int>::Min> tree; // Minimum
IntervalTree<int,IntervalTreeOperation<int>::Product> tree; // Product
IntervalTree<int,IntervalTreeOperation<int>::Xor> tree; // Bitwise xor

int array[8] = {1,4,-2,7,0,2,3,2};
IntervalTree<int> tree(array,8); // Sum tree created from array
```
Basic `query` and `set` usage
```c++
/*  if tree looks like this:
 *         17
 *     10       7
 *   5    5   2   5
 *  1 4 -2 7 0 2 3 2
 */
std::cout << tree.query(2,6) << "\n"; // answer is 11 (4-2+7+0+2)
std::cout << tree.query(4,7) << "\n"; // answer is 12 (7+0+2+3)
tree.set(5,6); // sets 5th element to 6
std::cout << tree.query(4,7) << "\n"; // answer is 18 (7+6+2+3)
```
[Full example code](Trees/Interval%20Tree/example.cpp)

---

# Disjoint-set

[Documentation in separate file](Disjoint-set)

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
[Full example code](Disjoint-set/example.cpp)

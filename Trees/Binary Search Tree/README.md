# Binary Search Tree

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

[Full example code](example.cpp)

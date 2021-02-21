# Interval Tree

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
[Full example code](example.cpp)

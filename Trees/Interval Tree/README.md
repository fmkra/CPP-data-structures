# Interval Tree

### Template  arguments

`T` - Type of variables stored
<br>
`Operation` - Struct that defines what operation tree uses [More here](#operations)

### Functions

#### constructor

#### push_back

Return: `none`
<br>
Arguments: `T`

Adds an element to the end.

#### set

Return: `none`
<br>
Arguments: `unsigned int`, `T`

Changes element on a given position.

#### query(unsigned int, unsigned int)

#### print()


### Operations

Interval tree can do every [associative operation](https://en.wikipedia.org/wiki/Associative_property). Those are implemented operations:
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

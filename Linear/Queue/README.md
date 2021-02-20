# Queue

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

[Full example code](example.cpp)

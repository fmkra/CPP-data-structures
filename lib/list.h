#ifndef LIST_H
#define LIST_H

#include <cstdlib>

template<typename T> // type of variable that's stored in every cell of a list
class List {
    struct Node {
        T value; // value stored in node
        Node* next; // pointer to the next element in a list
        Node* prev; // pointer to the previous element in a list
    };

    Node* first; // pointer to the first element
    Node* last;  // pointer to the last element
    unsigned int length; // number of elements in list

  public:
    List(); // constructor
    T front(); // returns value stored in the first element
    T back(); // returns value stored in the last element
    void push_front(T); // pushes given value to the front of a list, so that it will be the first element
    void push_back(T); // pushes given value to the back of a list, so that it will be the last element

    /*
     *  TODO:
     *    rbegin(), rend()
     *    size()
     *    empty()
     */

    // class iterator is used to iterate over elements of a List
    class iterator {
        Node* curr; // pointer to the current element
      public:
        iterator(Node*)
        iterator(const iterator&);
        T operator*(); // operator * is used to get value which is pointed by the iterator
        bool operator!=(const iterator&); // not equal operator overload - checks whether iterators point on different elements
        iterator& operator++(); // prefix increment operator overload - moves iterator to the next element

        /*
         *  TODO:
         *    postfix ++ operator
         *    postfix and prefix -- operator
         *    is equal to operator
         */
    };

    iterator begin(); // returns iterator to the first element
    iterator end(); // returns iterator to one past the last element
};

#include "list.cpp"

#endif

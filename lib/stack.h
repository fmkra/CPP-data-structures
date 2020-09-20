#ifndef STACK_H
#define STACK_H

template<class T>
class Stack {
    struct Node {
        T value;
        Node* next;
    };
    unsigned int length;
    Node* _top;
    Node* last;

  public:
    Stack();
    void push(T);
    void pop();
    T top();
    unsigned int size();
    bool empty();

    class iterator {
        Node* curr;
      public:
        iterator(const iterator&);
        iterator(Node*);
        T operator*();
        iterator& operator++();
        iterator operator++(int);
        bool operator!=(const iterator&);
        bool operator==(const iterator&);
    };

    iterator begin();
    iterator end();
};

#include "stack.cpp"

#endif

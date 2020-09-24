#ifndef LIST_H
#define LIST_H

#include <cstdlib>

template<typename T>
class List {
    struct Node {
        T value;
        Node* next;
        Node* prev;
    };

    Node* first;
    Node* last;
    unsigned int length;

  public:
    List();
    T front();
    T back();
    void push_front(T);
    void push_back(T);

    class iterator {
        Node* curr;
      public:
        iterator(Node*);
        iterator(const iterator&);
        T operator*();
        bool operator!=(const iterator&);
        iterator& operator++();
    };

    iterator begin();
    iterator end();
};

#include "list.cpp"

#endif

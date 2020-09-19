#ifndef STACK_CPP
#define STACK_CPP

#include "stack.h"
#include <cstddef>

template<class T>
Stack<T>::Stack() {
    length = 0;
    last = new Node();
    last -> next = NULL;
    _top = last;
}

template<typename T>
void Stack<T>::push(T _value) {
    Node* tmp = new Node();
    tmp -> value = _value;
    tmp -> next = _top;
    _top = tmp;
    length++;
}

template<typename T>
void Stack<T>::pop() {
    if(length == 0) return;
    Node* ptop = _top;
    _top = _top -> next;
    delete ptop;
    length--;
}

template<typename T>
T Stack<T>::top() {
    if(length == 0) return 0;
    return _top -> value;
}

template<typename T>
Stack<T>::iterator::iterator(const iterator& other) {
    this->curr = other.curr;
}

template<typename T>
Stack<T>::iterator::iterator(Node* node) {
    curr = node;
}

template<typename T>
T Stack<T>::iterator::operator*() {
    return curr->value;
}

template<typename T>
typename Stack<T>::iterator& Stack<T>::iterator::operator++() {
    curr = curr -> next;
    return *this;
}

template<typename T>
typename Stack<T>::iterator Stack<T>::iterator::operator++(int) {
    iterator tmp = *this;
    curr = curr -> next;
    return tmp;
}

template<typename T>
bool Stack<T>::iterator::operator!=(const iterator& other) {
    return other.curr != this->curr;
}

template<typename T>
bool Stack<T>::iterator::operator==(const iterator& other) {
    return other.curr == this->curr;
}

template<typename T>
typename Stack<T>::iterator Stack<T>::begin() {
    return iterator(_top);
}

template<typename T>
typename Stack<T>::iterator Stack<T>::end() {
    return iterator(last);
}

#endif

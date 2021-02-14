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
template<class T>
Stack<T>::Stack(const Stack<T>& other) {
    length = 0;
    last = new Node();
    last -> next = NULL;
    _top = last;
    Node* cur = other._top;
    T* tmp = new T[other.size()];
    for(int i=0;cur!=other.last;i++) {
      tmp[i] = cur->value;
      cur = cur->next;
    }
    for(int i=other.size()-1;i>=0;i--) push(tmp[i]);

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
T Stack<T>::top() const {
    if(length == 0) return 0;
    return _top -> value;
}

template<typename T>
unsigned int Stack<T>::size() const {
    return length;
}

template<typename T>
bool Stack<T>::empty() const {
    return length == 0;
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

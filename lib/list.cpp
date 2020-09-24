#ifndef LIST_CPP
#define LIST_CPP

#include "list.h"
#include <cstdlib>

template<typename T>
List<T>::List() {
    first = NULL;
    last = NULL;
    length = 0;
}

template<typename T>
T List<T>::front() {
    return first -> value;
}

template<typename T>
T List<T>::back() {
    return last -> value;
}

template<typename T>
void List<T>::push_front(T v) {
    Node* node = new Node();
    node -> value = v;
    node -> next = first;
    node -> prev = NULL;
    if(length > 0) first -> prev = node;
    else last = node;
    first = node;
    length++;
}

template<typename T>
void List<T>::push_back(T v) {
    Node* node = new Node();
    node -> value = v;
    node -> prev = last;
    node -> next = NULL;
    if(length > 0) last -> next = node;
    else first = node;
    last = node;
    length++;
}

template<typename T>
List<T>::iterator::iterator(Node* node) {
    curr = node;
}

template<typename T>
List<T>::iterator::iterator(const iterator& other) {
    this -> curr = other.curr;
}

template<typename T>
T List<T>::iterator::operator*() {
    return curr -> value;
}

template<typename T>
bool List<T>::iterator::operator!=(const iterator& other) {
    return this -> curr != other.curr;
}

template<typename T>
typename List<T>::iterator& List<T>::iterator::operator++() {
    curr = curr -> next;
    return *this;
}

template<typename T>
typename List<T>::iterator List<T>::begin() {
    return iterator(first);
}

template<typename T>
typename List<T>::iterator List<T>::end() {
    return iterator(NULL);
}

#endif

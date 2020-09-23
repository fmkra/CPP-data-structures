#ifndef LIST_CPP
#define LIST_CPP

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
    List() {
        first = NULL;
        last = NULL;
        length = 0;
    }
    T front() {
        return first -> value;
    }
    T back() {
        return last -> value;
    }
    void push_front(T v) {
        Node* node = new Node();
        node -> value = v;
        node -> next = first;
        node -> prev = NULL;
        if(length > 0) first -> prev = node;
        else last = node;
        first = node;
        length++;
    }
    void push_back(T v) {
        Node* node = new Node();
        node -> value = v;
        node -> prev = last;
        node -> next = NULL;
        if(length > 0) last -> next = node;
        else first = node;
        last = node;
        length++;
    }

    class iterator {
        Node* curr;
        public:
        iterator(Node* node) {
            curr = node;
        }
        iterator(const iterator& other) {
            this -> curr = other.curr;
        }
        T operator*() {
            return curr -> value;
        }
        bool operator!=(const iterator& other) {
            return this -> curr != other.curr;
        }
        iterator& operator++() {
            curr = curr -> next;
            return *this;
        }
    };

    iterator begin() {
        return iterator(first);
    }
    iterator end() {
        return iterator(NULL);
    }
};

#endif

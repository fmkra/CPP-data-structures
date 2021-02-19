#ifndef STACK_CPP
#define STACK_CPP

#include <cstddef>

template<typename T>
class Stack {
    struct Node {
        T value;
        Node* next;
    };
    unsigned int length;
    Node* _top;
    Node* last;

  public:
    Stack() {
        length = 0;
        last = new Node();
        last -> next = NULL;
        _top = last;
    }
    Stack(const Stack<T>& other) {
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
    void push(T _value) {
        Node* tmp = new Node();
        tmp -> value = _value;
        tmp -> next = _top;
        _top = tmp;
        length++;
    }
    void pop() {
        if(length == 0) return;
        Node* ptop = _top;
        _top = _top -> next;
        delete ptop;
        length--;
    }
    T top() const {
        if(length == 0) return 0;
        return _top -> value;
    }
    unsigned int size() const {
        return length;
    }
    bool empty() const {
        return length == 0;
    }

    class iterator {
        Node* curr;
      public:
        iterator(const iterator& other) {
            this->curr = other.curr;
        }
        iterator(Node* node) {
            curr = node;
        }
        T operator*() {
            return curr->value;
        }
        iterator& operator++() {
            curr = curr -> next;
            return *this;
        }
        iterator operator++(int) {
            iterator tmp = *this;
            curr = curr -> next;
            return tmp;
        }
        bool operator!=(const iterator& other) {
            return other.curr != this->curr;
        }
        bool operator==(const iterator& other) {
            return other.curr == this->curr;
        }
    };

    iterator begin() {
        return iterator(_top);
    }
    iterator end() {
        return iterator(last);
    }
};

#endif

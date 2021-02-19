#ifndef LIST_CPP
#define LIST_CPP

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
    List() { // constructor
        first = NULL;
        last = NULL;
        length = 0;
    }
    T front() { // returns value stored in the first element
      return first -> value;
    }
    T back() { // returns value stored in the last element
      return last -> value;
    }
    void push_front(T v) { // pushes given value to the front of a list, so that it will be the first element
      Node* node = new Node();
      node -> value = v;
      node -> next = first;
      node -> prev = NULL;
      if(length > 0) first -> prev = node;
      else last = node;
      first = node;
      length++;
    }
    void push_back(T v) { // pushes given value to the back of a list, so that it will be the last element
      Node* node = new Node();
      node -> value = v;
      node -> prev = last;
      node -> next = NULL;
      if(length > 0) last -> next = node;
      else first = node;
      last = node;
      length++;
    }

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
        iterator(Node* node) {
          curr = node;
        }
        iterator(const iterator& other) {
          this -> curr = other.curr;
        }
        T operator*() { // operator * is used to get value which is pointed by the iterator
          return curr -> value;
        }
        bool operator!=(const iterator& other) { // not equal operator overload - checks whether iterators point on different elements
          return this -> curr != other.curr;
        }
        iterator& operator++() { // prefix increment operator overload - moves iterator to the next element
          curr = curr -> next;
          return *this;
        }

        /*
         *  TODO:
         *    postfix ++ operator
         *    postfix and prefix -- operator
         *    is equal to operator
         */
    };

    iterator begin() { // returns iterator to the first element
      return iterator(first);
    }
    iterator end() { // returns iterator to one past the last element
      return iterator(NULL);
    }
};

#include "list.cpp"

#endif

#ifndef QUEUE_CPP
#define QUEUE_CPP

//#include <cstddef>

template<typename T>
class Queue {
    struct Node {
        T value;
        Node* next;
        Node(T value, Node* next = nullptr) : value(value), next(next) {}
    };
    Node* _front;
    Node* _back;
    unsigned int _length;

  public:
    Queue() {
        _length = 0;
        _front = nullptr;
        _back = nullptr;
    }
    T front() const {
        assert(_length>0);
        return _front -> value;
    }
    T back() const {
        assert(_length>0);
        return _back -> value;
    }
    void push(T value) {
        Node* node = new Node(value);
        if(this -> _front != nullptr)
            this -> _front -> next = node;
        else
            this -> _back = node;
        this -> _front = node;
        _length++;
    }
    void pop() {
        assert(_length>0);
        Node* node = _back;
        _back = _back -> next;
        delete node;
        _length--;
    }
    unsigned int size() const {
      return _length;
    }
    bool empty() const {
      return _length == 0;
    }
};

#endif

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
    T top() {
        if(length == 0) return 0;
        return _top -> value;
    }
    void print(string separator = " ") {
        for(Node* i=_top;i!=NULL;i=i->next){
            cout<<i->value<<separator;
        }
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

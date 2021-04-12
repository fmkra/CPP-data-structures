#ifndef REDBLACKTREE_CPP
#define REDBLACKTREE_CPP

#include <iostream>

template<typename T>
class RedBlackTree {
    enum Color_T {BLACK,RED};
    struct Node {
        T value;
        Node* parent;
        Node* left;
        Node* right;
        enum Color_T color;
        unsigned int count;
        unsigned int subtreesize;

        Node(
          T value,
          enum Color_T color,
          Node* parent = nullptr,
          Node* left = nullptr,
          Node* right = nullptr,
          unsigned int count = 1,
          unsigned int subtreesize = 1
        ) : value(value), color(color), parent(parent), left(left), right(right), count(count), subtreesize(subtreesize) {}

        void updateSubtreesize() {
            subtreesize = count;
            if(left != nullptr) subtreesize += left->subtreesize;
            if(right != nullptr) subtreesize += right->subtreesize;
        }
    };

    Node* getParent(Node* node) {
        return node == nullptr ? nullptr : node->parent;
    }
    Node* getGrandParent(Node* node) {
        return getParent(getParent(node));
    }
    Node* getSibling(Node* node) {
        Node* p = getParent(node);
        if(p == nullptr) return nullptr;
        return p->left == node ? p->right : p->left;
    }
    Node* getUncle(Node* node) {
        return getSibling(getParent(node));
    }
    void rotateLeft(Node* node) {
        /*
                 p                p
                 \                \
                node             nnew
               /    \     =>    /    \
              1    nnew       node   3
                  /   \      /   \
                 2    3     1    2
        */
        Node* nnew = node->right;
        Node* p = getParent(node);
        assert(nnew != nullptr);

        node->right = nnew->left; // node's right child => 2
        nnew->left = node;       // nnew's left child => node
        node->parent = nnew;      // node's parent => nnew

        if(node->right != nullptr)
            node->right->parent = node; // 2's parent => node
        if(p != nullptr) { // p's child => nnew
          if(p->left == node) p->left = nnew;
          else if(p->right == node) p->right = nnew;
        }
        nnew->parent = p; // nnew's parent => p

        node->updateSubtreesize();
        nnew->updateSubtreesize();
    }
    void rotateRight(Node* node) {
        /*
                 p                p
                 \                \
                node             nnew
               /    \     =>    /    \
             nnew   3          1    node
            /   \                  /   \
           1    2                 2    3
        */
        Node* nnew = node->left;
        Node* p = getParent(node);
        assert(nnew != nullptr);

        node->left = nnew->right; // node's left child => 2
        nnew->right = node;       // nnew's right child => node
        node->parent = nnew;      // node's parent => nnew

        if(node->left != nullptr)
            node->left->parent = node; // 2's parent => node
        if(p != nullptr) { // p's child => nnew
          if(p->left == node) p->left = nnew;
          else if(p->right == node) p->right = nnew;
        }
        nnew->parent = p; // nnew's parent => p

        node->updateSubtreesize();
        nnew->updateSubtreesize();
    }

    void insertRecurse(Node* root, Node* node) {
        if(root != nullptr) {
            root->subtreesize++;
            if(node->value == root->value) {
                root->count++;
            } else if(node->value < root->value) {
                if(root->left != nullptr) {
                    insertRecurse(root->left, node);
                    return;
                } else
                    root->left = node;
            } else {
                if(root->right != nullptr) {
                    insertRecurse(root->right, node);
                    return;
                } else
                    root->right = node;
            }
        }
        node->parent = root;
    }
    void insertRepairTree(Node* node) {
        if(getParent(node) == nullptr) {
            node->color = BLACK;
        } else if(getParent(node)->color == BLACK) {

        } else if(getUncle(node) != nullptr && getUncle(node)->color == RED) {
            getParent(node)->color = BLACK;
            getUncle(node)->color = BLACK;
            getGrandParent(node)->color = RED;
            insertRepairTree(getGrandParent(node));
        } else {
            Node* p = getParent(node);
            Node* g = getGrandParent(node);

            if(node == p->right && p == g->left) {
                rotateLeft(p);
                node = node->left;
            } else if(node == p->left && p == g->right) {
                rotateRight(p);
                node = node->right;
            }

            p = getParent(node);
            g = getGrandParent(node);

            if(node == p->left)
                rotateRight(g);
            else
                rotateLeft(g);

            p->color = BLACK;
            g->color = RED;
        }
    }
    Node* insert(Node* root, Node* node) {
        insertRecurse(root, node);
        insertRepairTree(node);
        root = node;
        while(getParent(root) != nullptr)
            root = getParent(root);
        return root;
    }

    Node* getFirstGreater(Node* node, T value) {
        if(node == nullptr) return nullptr;
        if(node->value <= value) return getFirstGreater(node->right, value);
        Node* left = getFirstGreater(node->left, value);
        if(left != nullptr) return left;
        return node;
    }

    Node* _root;
  public:
    RedBlackTree() {
        _root = nullptr;
    }
    void insert(T value) {
        _root = insert(_root, new Node(value, RED));
    }

    class iterator {
        Node* curr;
        unsigned int index;
      public:
        iterator(Node* curr = nullptr) : curr(curr) {index=0;}
        iterator(const iterator& other) {
            curr = other.curr;
            index = other.index;
        }
        bool operator==(const iterator& other) {
            return this->curr == other.curr && this->index == other.index;
        }
        bool operator!=(const iterator& other) {
            return this->curr != other.curr || this->index != other.index;
        }
        iterator& operator++() {
            index++;
            if(index == curr->count) index=0;
            else return *this;

            if(curr->right != nullptr) {
                curr = curr->right;
                while(curr->left != nullptr) curr = curr->left;
            } else {
                while(curr->parent != nullptr && curr == curr->parent->right) curr = curr->parent;
                curr = curr->parent;
            }
            return *this;
        }
        iterator operator++(int) {
            iterator tmp = *this;
            this->operator++();
            return tmp;
        }
        T operator*() {
            return curr->value;
        }
        unsigned int which() const {
            Node* node = curr;
            unsigned int sum = index;
            if(node->left != nullptr) sum += node->left->subtreesize;
            while(node->parent != nullptr) {
                if(node == node->parent->right) {
                    sum += node->parent->count;
                    if(node->parent->left != nullptr)
                        sum += node->parent->left->subtreesize;
                }
                node = node->parent;
            }
            return sum;
        }
        bool isNull() const {
            return curr == nullptr;
        }
        static int dist(const iterator& i1, const iterator& i2) {
            if(i1.isNull() || i2.isNull()) return -1;
            return i2.which() - i1.which();
        }
    };

    iterator begin() {
        Node* node = _root;
        while(node->left != nullptr) node = node->left;
        return iterator(node);
    }
    iterator end() {
        return nullptr;
    }

    iterator lower_bound(T value) {
        Node* node = _root;
        while(node != nullptr) {
            if(value == node->value) {
                if(node->left != nullptr && node->left->value == value) node = node->left;
                else break;
            } else if(value < node->value) {
                if(node->left != nullptr) node = node->left;
                else break;
            } else {
                if(node->right != nullptr) node = node->right;
                else break;
            }
        }
        if(node->value < value) return end();
        return iterator(node);
    }
    iterator upper_bound(T value) {
        Node* node = getFirstGreater(_root, value);
        if(node == nullptr) return end();
        return iterator(node);
    }

    template<typename RBTP_T>
    friend class RedBlackTreePrinter;
};

#endif

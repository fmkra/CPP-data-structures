#ifndef BSTREE_CPP
#define BSTREE_CPP

#include <cstddef>
#include <algorithm>
#include <iostream>
#include <cmath>

template<typename T>
class BSTree {
protected:
	struct Node {
		T value;
		Node* left;
		Node* right;
		Node* parent;
		
		Node() {
			left = NULL;
			right = NULL;
			parent = NULL;
		}
		Node(T v, Node* p) {
			Node();
			value = v;
			parent = p;
		}
		
		void insert(T v) {
			if(v < value) {
				if(left == NULL)
					left = new Node(v, this);
				else
					left -> insert(v);
			} else {
				if(right == NULL)
					right = new Node(v, this);
				else
					right -> insert(v);
			}
		}
		Node* findNode(T v) {
			if(v == value) return this;
			if(v < value) {
				if(left == NULL) return NULL;
				return left -> findNode(v);
			} else {
				if(right == NULL) return NULL;
				return right -> findNode(v);
			}
		}
		bool search(T v) {
			return findNode(v) != NULL;
		}
	};
	
	public: // tmp
	Node* root;
	
public:
	BSTree() {
		root = NULL;
	}
	void insert(T v) {
		if(root == NULL)
			root = new BSTree<T>::Node(v, NULL);
		else
			root -> insert(v);
	}
	bool search(T v) {
		if(root == NULL) return false;
		else return root -> search(v);
	}

	void remove(T v) {
		// TODO if root is NULL
		Node* node = root -> findNode(v);
		// TODO if didn't find a node
		// no children
		if(node -> left == NULL && node -> right == NULL) {
			if(node -> parent != NULL) { // if not a root
				if(node -> parent -> left == node) {
					node -> parent -> left = NULL;
				} else {
					node -> parent -> right = NULL;
				}
			}
			delete node;
			return;
		}

		// 1 child

		if(node -> right == NULL) { // if deleted node has left child
			node -> left -> parent = node -> parent;
			if(node -> parent -> left == node) {
				node -> parent -> left = node -> left;
			} else {
				node -> parent -> right = node -> left;
			}
			delete node;
			return;
		}
		if(node -> left == NULL) { // if deleted node has left child
			node -> right -> parent = node -> parent;
			if(node -> parent -> left == node) {
				node -> parent -> left = node -> right;
			} else {
				node -> parent -> right = node -> right;
			}
			delete node;
			return;
		}

		// 2 children
		Node* swap = node -> right;
		while(swap -> left != NULL) swap = swap -> left;
		node -> value = swap -> value;

		if(swap -> parent != NULL) { // if not a root
			if(swap -> parent -> left == swap) {
				swap -> parent -> left = NULL;
			} else {
				swap -> parent -> right = NULL;
			}
		}
		delete swap;
	}

	// necessary to use BSTreePrinter
	template<typename BSTP_T>
	friend class BSTreePrinter;
};
#endif

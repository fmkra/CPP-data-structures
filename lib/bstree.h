#ifndef BSTREE_H
#define BSTREE_H

#include <cstddef>
#include <algorithm>
#include <iostream>
#include <cmath>

template<typename T>
class BSTree {
	struct Node {
		T value;
		Node* left;
		Node* right;
		Node* parent;

		Node();
		Node(T, Node*);
		void insert(T);
		Node* findNode(T);
		bool search(T);
	};

	public: // tmp
	Node* root;

public:
	BSTree();
	void insert(T);
	bool search(T);
  void remove(T);

	// necessary to use BSTreePrinter
	template<typename BSTP_T>
	friend class BSTreePrinter;
};

#include "bstree.cpp"
#endif

#ifndef BSTREEPRINTER_CPP
#define BSTREEPRINTER_CPP

#include "bstree.h"
#include <iostream>
#include <cstddef>


template<typename T>
unsigned int BSTreePrinter<T>::getDepth(typename BSTree<T>::Node* node) {
	if(node -> left == NULL && node -> right == NULL) return 1;
	if(node -> left == NULL) return getDepth(node -> right) + 1;
	if(node -> right == NULL) return getDepth(node -> left) + 1;
	return std::max(getDepth(node -> right), getDepth(node -> left)) + 1;
}

template<typename T>
void BSTreePrinter<T>::printValue(typename BSTree<T>::Node* node, unsigned int noDigits) {
	int myv = node -> value;
	int nomd = 0;
	while(myv) {
		nomd++;
		myv/=10;
	}
	int nta = noDigits-nomd;
	std::cout<<(node -> value);
	for(int i=0;i<nta;i++) std::cout<<" ";
}

template<typename T>
void BSTreePrinter<T>::printDepth(typename BSTree<T>::Node* node, unsigned int depth, unsigned int spaces, unsigned int noDigits) {
	if(depth > 1) {
		if(node -> left == NULL) {
			for(int i=0;i<pow(2,depth-2);i++) {
				for(int j=0;j<noDigits;j++) std::cout<<" ";
				for(int j=0;j<spaces;j++) std::cout<<" ";
			}
		}
		else printDepth(node -> left, depth - 1, spaces, noDigits);
		if(node -> right == NULL) {
			for(int i=0;i<pow(2,depth-2);i++) {
				for(int j=0;j<noDigits;j++) std::cout<<" ";
				for(int j=0;j<spaces;j++) std::cout<<" ";
			}
		}
		else printDepth(node -> right, depth - 1, spaces, noDigits);
		return;
	}
	printValue(node, noDigits);
	for(int j=0;j<spaces;j++) std::cout<<" ";
}

template<typename T>
T* BSTreePrinter<T>::getMax(typename BSTree<T>::Node* node) {
	if(node -> right == NULL) return &(node -> value);
	return getMax(node -> right);
}

template<typename T>
void BSTreePrinter<T>::printTree(typename BSTree<T>::Node*& root) {
	int max = 0;
	T m = *getMax(root);
	while(m) {
		max++;
		m/=10;
	}

	int depth = getDepth(root);
	for(int i=0;i<depth;i++) {
		int x = pow(2,depth-i)-1;
		x*=max;
		for(int j=0;j<x/2;j++) std::cout<<" ";
		printDepth(root, i+1,x,max);
		std::cout<<"\n";
	}
}

template<typename T>
void BSTreePrinter<T>::print(BSTree<T>* tree) {
	printTree(tree -> root);
}

template<typename T>
void BSTreePrinter<T>::print(BSTree<T>& tree) {
	printTree(tree.root);
}

#include "bstreeprinter.h"
#endif

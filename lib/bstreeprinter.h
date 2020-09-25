#ifndef BSTREEPRINTER_H
#define BSTREEPRINTER_H

#include "bstree.h"

template<typename T>
class BSTreePrinter {
  	static unsigned int getDepth(typename BSTree<T>::Node*);
  	static void printValue(typename BSTree<T>::Node*, unsigned int);
  	static void printDepth(typename BSTree<T>::Node*, unsigned int, unsigned int, unsigned int);
  	static T* getMax(typename BSTree<T>::Node*);
  	static void printTree(typename BSTree<T>::Node*&);
	public:
    static void print(BSTree<T>*);
  	static void print(BSTree<T>&);
};


#include "bstreeprinter.cpp"
#endif

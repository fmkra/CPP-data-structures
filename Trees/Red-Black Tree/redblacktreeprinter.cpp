#ifndef REDBLACKTREEPRINTER_CPP
#define REDBLACKTREEPRINTER_CPP

#include "redblacktree.cpp"
#include <iostream>
#include <string>
#include <cstddef>

template<typename T>
class RedBlackTreePrinter {
    static unsigned int getWidthToPrint(typename RedBlackTree<T>::Node* node) {
        if(node == nullptr) return 0;
        unsigned int width = 0;
        for(T i = node->value;i;i/=10) width++;
        return width +
          (node->left != nullptr ? getWidthToPrint(node->left) : 0)+
          (node->right != nullptr ? getWidthToPrint(node->right) : 0);
    }
    static unsigned int getDepth(typename RedBlackTree<T>::Node* node) {
        if(node == nullptr) return 0;
        return 1 + max(getDepth(node->left), getDepth(node->right));
    }
    static void printDepth(typename RedBlackTree<T>::Node* node, unsigned int d, std::string* out, unsigned int mx) {
        unsigned int numberWidth = 0;
        for(T i = node->value;i;i/=10) numberWidth++;

        unsigned int paddingBefore = getWidthToPrint(node->left);
        for(unsigned int i=0;i<paddingBefore;i++) out[d]+=" ";

        std::string p = "";
        for(unsigned int i=0;i<numberWidth;i++) p+=" ";
        std::string s = "";
        for(T i = node->value;i;i/=10) s = (char)(i%10+'0') + s;
        out[d]+=s;

        unsigned int paddingAfter = getWidthToPrint(node->right);
        for(unsigned int i=0;i<paddingAfter;i++) out[d]+=" ";
        if(node->left != nullptr) printDepth(node->left,d+1,out,mx);
        for(unsigned int i=d+1;i<mx;i++) out[i]+=p;
        if(node->right != nullptr) printDepth(node->right,d+1,out,mx);
    }
  public:
    static void print(const RedBlackTree<T>& tree) {
        unsigned int h = getDepth(tree._root);
        string out[h];
        printDepth(tree._root, 0, out, h);
        for(unsigned int i=0;i<h;i++) std::cout << out[i] << "\n";
    }
};

#endif

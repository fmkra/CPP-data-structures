#include <bits/stdc++.h>
#include "redblacktreeprinter.cpp"
using namespace std;

int main() {
    RedBlackTree<int> t;
    t.insert(1);
    t.insert(1);
    t.insert(2);
    t.insert(2);
    t.insert(2);
    t.insert(3);
    t.insert(5);
    t.insert(2);
    t.insert(2);
    t.insert(2);
    t.insert(2);
    t.insert(2);
    t.insert(2);
    t.insert(2);
    t.insert(2);
    t.insert(2);
    t.insert(2);
    t.insert(2);
    t.insert(2);
    RedBlackTreePrinter<int>::print(t);
    for(RedBlackTree<int>::iterator i = t.begin(); i != t.end(); ++i) {
        cout<<(*i)<<" "<<i.which()<<"\n";
    }
    cout<<"\n";
    for(int i=0;i<=6;i++) cout<<i<<" "<<(*t.upper_bound(i))<<"\n";
}

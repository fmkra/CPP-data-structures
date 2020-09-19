#include <bits/stdc++.h>
#include "lib/stack.h"
using namespace std;

int main() {
  Stack<int> s;
  s.push(3);
  s.push(2);
  s.push(1);
  s.push(4);
  for(Stack<int>::iterator i = s.begin(); i != s.end(); ++i) {
    cout<<*i<<" ";
  }
}

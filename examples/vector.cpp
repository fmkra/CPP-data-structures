#include <iostream>
#include "../lib/vector.h"
using namespace std;

int main() {
    Vector<int> v;
    v.push(1);
    v.push(3);
    cout << v[0] << " " << v[1] << "\n";
    v[0] = 21;
    v[1] = 34;
    cout << v[0] << " " << v[1] << "\n";
}

#include <iostream>
#include "../../include/vector"

int main() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(3);
    std::cout << v[0] << " " << v[1] << "\n";
    v[0] = 21;
    v[1] = 34;
    std::cout << v[0] << " " << v[1] << "\n";
    v.push_back(2);
    for(int i : v) std::cout << i << " "; std::cout << "\n";
}

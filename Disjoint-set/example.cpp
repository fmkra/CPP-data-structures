#include <iostream>
#include "../include/disjoint_set"

DisjointSet s(5); // size 5

int main() {
	// {1} {2} {3} {4} {5}
	std::cout << (s.find(1) == s.find(2)) << "\n"; // false
	s.merge(1,2); // {1} {2} => {1,2}
	// {1,2} {3} {4} {5}
	std::cout << (s.find(1) == s.find(2)) << "\n"; // true
	std::cout << (s.find(2) == s.find(4)) << "\n"; // false
	s.merge(1,4); // {1,2} {4} => {1,2,4}
	// {1,2,4} {3} {5}
	std::cout << (s.find(2) == s.find(4)) << "\n"; // true
}

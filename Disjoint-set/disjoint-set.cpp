#ifndef DISJOINT_SET_CPP
#define DISJOINT_SET_CPP

#include <vector>

class DisjointSet {
	std::vector<unsigned int> parent;
	std::vector<unsigned int> noChildren;

public:
	DisjointSet(unsigned int _size = 0) {
		parent.push_back(0);
		noChildren.push_back(0);
		for(unsigned int i=1;i<=_size;i++) {
			parent.push_back(i);
			noChildren.push_back(1);
		}
	}

	unsigned int makeSet() {
		unsigned int id = parent.size();
		parent.push_back(id);
		noChildren.push_back(1);
		return id;
	}
	unsigned int find(unsigned int a) {
		if(parent[a] != a) parent[a] = find(parent[a]);
		return parent[a];
	}
	void merge(unsigned int a, unsigned int b) {
		a = find(a);
		b = find(b);

		if(a==b) return;

		if(noChildren[a] < noChildren[b]) {
			parent[a] = b;
			noChildren[b] += noChildren[a];
		} else {
			parent[b] = a;
			noChildren[a] += noChildren[b];
		}
	}
  unsigned int size() const {
    return parent.size()-1;
  }
};

#endif

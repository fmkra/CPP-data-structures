#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <vector>
#include <stack>

class Graph {
protected:
  unsigned int n;
  std::vector<unsigned int>* g;
private:
  void topologicalSortDfs(std::vector<unsigned int>& output, bool* visited, unsigned int v) {
    visited[v]=1;
    unsigned int n = getNoNeighbours(v);
    for(unsigned int i=0;i<n;i++) {
      unsigned int u = getNeighbour(v,i);
      if(!visited[u]) topologicalSortDfs(output, visited, u);
    }
    output.push_back(v);
  }
public:
  Graph(unsigned int n) : n(n) {
    g = new std::vector<unsigned int>[n+1];
  }
  unsigned int getNoVertices() {
    return n;
  }
  unsigned int getNoNeighbours(unsigned int v) {
    return g[v].size();
  }
  unsigned int getNeighbour(unsigned int v, unsigned int n) {
    return g[v][n];
  }

  virtual void addEdge(unsigned int, unsigned int) = 0;

  std::vector<unsigned int> topologicalSort() {
    std::vector<unsigned int> output;
    unsigned int n = getNoVertices();

    bool* visited = new bool[n+1];
    for(unsigned int i=1;i<=n;i++) visited[i]=0;

    for(unsigned int i=1;i<=n;i++) {
      if(!visited[i]) {
        topologicalSortDfs(output, visited, i);
      }
    }

    delete[] visited;
    return output;
  }
};

class UndirectedGraph :public Graph {
public:
  UndirectedGraph(unsigned int n) : Graph(n) {}

  virtual void addEdge(unsigned int vertex1, unsigned int vertex2) {
    g[vertex1].push_back(vertex2);
    g[vertex2].push_back(vertex1);
  }
};

class DirectedGraph :public Graph {
public:
  DirectedGraph(unsigned int n) : Graph(n) {}

  virtual void addEdge(unsigned int vertex1, unsigned int vertex2) {
    g[vertex1].push_back(vertex2);
  }
};

#endif

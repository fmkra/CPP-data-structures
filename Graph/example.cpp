#include <iostream>
#include "graph.cpp"
using namespace std;

UndirectedGraph g1(4);
DirectedGraph g2(4);

int main() {
  g1.addEdge(1,3);
  g1.addEdge(2,3);
  g1.addEdge(2,4);

  g2.addEdge(1,3);
  g2.addEdge(2,3);
  g2.addEdge(2,4);

  auto v1 = g1.topologicalSort();
  for(auto i : v1) cout<<i<<" "; cout<<"\n";

  auto v2 = g2.topologicalSort();
  for(auto i : v2) cout<<i<<" "; cout<<"\n";
}

#ifndef TWOSAT_CPP
#define TWOSAT_CPP

#include <vector>

class TwoSAT {
  std::vector<std::vector<unsigned int> > g;
  std::vector<std::vector<unsigned int> > gt;
  bool* vis;
  unsigned int currentComponent;
  unsigned int* component;
  std::vector<unsigned int> tsort;

  void dfs1(unsigned int v) {
    if(vis[v]) return;
    vis[v]=1;
    for(unsigned int u : g[v]) dfs1(u);
    tsort.push_back(v);
  }
  void dfs2(unsigned int v) {
    if(component[v]) return;
    component[v]=currentComponent;
    for(unsigned int u : gt[v]) dfs2(u);
  }

public:
  void addAlternative(unsigned int firstArg, unsigned int secondArg, bool invertFirstArg = 0, bool invertSecondArg = 0) {
    while(g.size() < 2*firstArg+2 || g.size() < 2*secondArg+2) {
      g.push_back(std::vector<unsigned int>());
      gt.push_back(std::vector<unsigned int>());
    }
    g[(2*firstArg+1)^invertFirstArg].push_back((2*secondArg)^invertSecondArg);
    g[(2*secondArg+1)^invertSecondArg].push_back((2*firstArg)^invertFirstArg);
    gt[(2*secondArg)^invertSecondArg].push_back((2*firstArg+1)^invertFirstArg);
    gt[(2*firstArg)^invertFirstArg].push_back((2*secondArg+1)^invertSecondArg);
  }

  std::vector<bool> solve2SAT() {
    unsigned int n = g.size();
    vis = new bool[n];
    component = new unsigned int[n];
    std::vector<bool> output;
    for(unsigned int i=0;i<n;i++) vis[i]=component[i]=0;
    for(unsigned int i=0;i<n;i++) if(!vis[i]) dfs1(i);
    for(unsigned int i=n;i>0;i--) if(!component[tsort[i-1]]) {
      ++currentComponent;
      dfs2(tsort[i-1]);
    }
    tsort.clear();
    for(unsigned int i=0;i<n;i+=2) {
      if(component[i]==component[i+1]) return std::vector<bool>();
      output.push_back(component[i]<component[i+1]);
    }
    return output;
  }
};

#endif

#include <bits/stdc++.h>
using namespace std;

int n;
int* arr;
int* _next;
vector<int> *t;
int lv = 1;
int m;
int p;
int q;
int x;
map<int,int> _map;
int INF = numeric_limits<int>::max();

int query(int a, int b, int v, int p, int q, int x) {
  if(p>b || q<a) return 0;
  if(p>=a && q<=b) return (t[v].end()-upper_bound(t[v].begin(),t[v].end(),x));
  int r = (p+q)/2;
  return query(a,b,2*v,p,r,x) + query(a,b,2*v+1,r+1,q,x);
}
int query(int a, int b, int x) {
  return query(a,b,1,1,lv,x);
}

int main() {
    cin>>n;
    arr = new int[n+1];
    _next = new int[n+1];
    for(int i=1;i<=n;i++) cin>>arr[i];
    while(lv<n) lv*=2;
    t = new vector<int>[2*lv];

    for(int i=n;i>=1;i--) {
      if(_map.find(arr[i])==_map.end()) _next[i]=INF;
      else _next[i]=_map[arr[i]];
      _map[arr[i]]=i;
    }

    for(int i=0;i<n;i++) t[lv+i].push_back(_next[i+1]);
    for(int i=lv-1;i>0;i--) {
      for(int j : t[2*i]) t[i].push_back(j);
      for(int j : t[2*i+1]) t[i].push_back(j);
      sort(t[i].begin(),t[i].end());
    }

    cin>>m;
    while(m--) {
        cin>>p>>q;
        cout<<query(p,q,q)<<"\n";
    }
}

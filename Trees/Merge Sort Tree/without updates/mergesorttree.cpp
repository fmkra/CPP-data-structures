#include <bits/stdc++.h>

template<typename T>
bool MergeSortTreeDefaultComparator(const T& a, const T& b) {
  return a<b;
}

template<typename T, bool(*Comparator)(const T&, const T&) = MergeSortTreeDefaultComparator<T> >
class MergeSortTree {
  unsigned int _size;
  unsigned int _width;
  unsigned int _height;
  std::vector<T>* d;

  unsigned int query(unsigned int a, unsigned int b, unsigned int v, unsigned int p, unsigned int q, T x) {
    if(q<a || p>b) return 0;
    if(p>=a && q<=b) return d[v].end()-upper_bound(d[v].begin(),d[v].end(),x);
    unsigned int s = (p+q)/2;
    return query(a,b,2*v,p,s,x) + query(a,b,2*v+1,s+1,q,x);
  }
public:
  MergeSortTree(const T* array, unsigned int size) {
    _size = size;
    _height=1;
    _width=1;
    while(_width<size) {
      _width*=2;
      _height++;
    }
    d = new std::vector<T>[2*_width];
    for(unsigned int i=0;i<_size;i++) d[_width+i].push_back(array[i]);
    for(unsigned int i=_width-1;i>0;i--) {
      unsigned int ps = d[2*i].size();
      unsigned int qs = d[2*i+1].size();
      unsigned int p = 0;
      unsigned int q = 0;
      while(p<ps || q<qs) {
        if(q==qs || p<ps && d[2*i][p]<d[2*i+1][q]) d[i].push_back(d[2*i][p++]);
        else d[i].push_back(d[2*i+1][q++]);
      }
    }
  }
  unsigned int query(unsigned int p, unsigned int q, T x) {
    return query(p,q,1,1,_width,x);
  }
};

int main() {
  int arr[8] = {1,3,9,5,0,7,2,2};
  MergeSortTree<int> m(arr,8);
  m.print();
  int q;
  cin>>q;
  int a,b,c;
  while(q--) {
    cin>>a>>b>>c;
    cout<<m.query(a,b,c)<<"\n";
  }
}

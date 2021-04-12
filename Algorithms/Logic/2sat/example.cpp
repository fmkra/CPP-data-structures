#include <iostream>
#include "2sat.cpp"
using namespace std;

int main() {
  TwoSAT sat;
  sat.addAlternative(0,1,false,false);
  sat.addAlternative(0,1,false,true);
  sat.addAlternative(0,1,true,false);
  sat.addAlternative(0,1,true,true);
  cout<<"answer: ";
  for(auto i : sat.solve2SAT()) cout<<i<<" ";
  cout<<"\n";
}

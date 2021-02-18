/*
    This is brute-force approach for solving the problem to find number of elements greater than given x on an interval
    It's not a recommended way to solve that problem, it's only for time complexity comparasion and merge sort tree answer check

    Memory complexity: O(n)
    Time complexity:
      - Preprocessing - O(n)
      - Query - O(n)
      - Update - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int n; // number of elements in array
int* arr; // array
int m; // number of queries
int p; // interval left bound (closed interval)
int q; // interval right bound (closed interval)
int x; // value for which we want to find number of elements greater than it

int main() {
    cin>>n; // get number of elements
    arr = new int[n+1]; // create array
    for(int i=1;i<=n;i++) cin>>arr[i]; // get array elements

    cin>>m; // get number of queries
    while(m--) {
        cin>>p>>q>>x; // get arguments for query

        int ans=0; // initialise answer variable
        for(int i=p;i<=q;i++) // for every element in given interval
            if(arr[i]>x) ans++; // increment answer if the element is greater than x
        cout<<ans<<"\n"; // print the answer
    }
}

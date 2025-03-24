#include <bits/stdc++.h>
#define ll long long 
using namespace std;
map <pair<int,int>,int> mps;
string a[1002323];
int n;
int d[1000423]; // 0 -> 1000423 - 1 
int main() 
{
    cin >> n;
    for (int i = 1; i <= n; i++){
      int x ,y;
      cin >> x >> y ;
      mps[make_pair(x,y)]++; // O(log(size))
    }
    for (auto x : mps){
      // x.first -> (x.first).first , (x.first).second 
      // x.second 
      cout << "(" << x.first.first << "," << x.first.second << ")" << " -> " << x.second << "\n";
    }
    return 0;
}
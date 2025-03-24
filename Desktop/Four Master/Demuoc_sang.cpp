#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int lp[N + 10] , a[N], n;
void sieve(int lim){ // No phan tich duoc trong gioi han <= 10^7
  for (int i = 1; i <= lim; i++) lp[i] = i;
  lp[1] = 1e9;
  for (int i = 2; i * i <= lim; i++){
    if (lp[i] == i){
      for (int j = i * i; j <= lim; j += i)
        if (lp[j] == j) lp[j] = i;
    }
  }
  // lp[i] luu tsnt nn cua i => i luon luon chia het lp[i] 
}
int demuoc(vector<pair<int,int>> res){
  int dem = 1;
  for (int i = 0; i < res.size(); i++){
    // res[i] la mot cai pair 
    // res[i].first luu tsnt 
    // res[i].second luu so mu tuong ung voi tsnt res[i].first 
    dem = dem * (res[i].second + 1);
  }
  return dem;
}
vector <pair<int,int>> factor(int x){ 
  // O(n) * O(sqrt(a[i])) > TLE 
  // O(n) * O(log2(a[i])) > AC 
  // sqrt(10^6) = 10^3 
  // log2(10^6) = 20 
  vector <pair<int,int>> res ;
  while (x > 1){
    int u = lp[x] , d = 0; // lay duoc trong O(1) ? lam sao lay duoc trong O(1) ?
    while (x % u == 0){ // khong chia het -> trong x het tsnt u
      d++;
      x /= u;
    }
    // pair <int,int> tmp; tmp.first = u; tmp.second = d;
    // res.push_back(tmp);
    res.push_back(make_pair(u,d));
  }
  return res;
}
int main() 
{
    cin >> n;
    sieve(1000000);
    int ans = 0;
    for (int i = 1; i <= n; i++){
      int x; cin >> x;
      cout << demuoc(factor(x)) << "\n";
      ans = ans + demuoc(factor(x));
    }
    cout << ans;   
    return 0;
}
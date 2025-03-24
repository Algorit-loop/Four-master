#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 2e5 + 1000;
int a[N], n, dp[N];
int main() 
{
  // freopen("dpliq1.inp","r",stdin);
  //freopen("dpliq1.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // a[i] <= 10^9 
    // > < so sanh ve gia tri 
    // 10 7 2 1 6 6 
    // 5    44 2 1 3 3
    for (int i = 1; i <= n; i++){
      dp[i] = 1;
      for (int j = 1; j < i; j++){
        if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    int u =  *max_element(dp + 1,dp + 1 + n);
    int pos = -1, gt = -1;
    for (int i = 1; i <= n; i++) if (dp[i] == u) pos = i, gt = a[i];
    vector <int> v;
    v.push_back(pos);
    u -= 1;
    gt = a[pos];
    for (int i = pos-1; i >= 1; i--){
      if (dp[i] == u && a[i] < gt){
        v.push_back(i);
        gt = a[i];
        u -= 1;
      }
    }
    reverse(v.begin(),v.end());
    cout << v.size() << "\n";
    for (auto x : v) cout << x << " ";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// deque 
int a[(int)2e6 + 1] , n,k, dp[2000004];
int main() 
{
    cin >> n;
    int k = 2;
    for (int i = 0; i < n; i++) cin >> a[i];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) dp[i] = 1e9;
    for (int i = 1; i <= n; i++){
      int get = 1e9;
      for (int j = max(0,i - k); j < i; j++){
        if (a[j] == 0) get = min(get,dp[j]);
      }
      dp[i] = min(dp[i], get + 1);
    }
    if (dp[n] == 1e9) cout << -1; else cout << dp[n];
    return 0;
}
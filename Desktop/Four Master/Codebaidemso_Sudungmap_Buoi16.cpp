#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 2e5 + 100;
map <ll,ll> mps;
map <ll,bool> kt;
ll a[N],n,pre[N];
int main() 
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    ll ans = -1e18;
    for (int i = 1; i <= n; i++){
      // co thang a[i] nao da xuat hien truoc do chua ?
      if (kt[a[i]] == false){
        kt[a[i]] = true;
        mps[a[i]] = pre[i-1];
        continue;
      }
      // kt[a[i]] = true ????
      ans = max(ans, pre[i] - mps[a[i]]);
      mps[a[i]] = min(mps[a[i]],pre[i-1]);
    }
    cout << ans;
    return 0;
}
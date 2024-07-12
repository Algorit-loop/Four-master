#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll mod = 1e9 + 7;
ll power(ll a, ll b, ll c){
  ll res = 1;
  a = a % c;
  for (; b > 0; b >>= 1 , a = a * a % mod){
    if (b & 1) res = res * a % mod;
  }
  return res;
}
ll sum(ll l, ll r){
  ll u = (r - l + 1) % mod;
  ll v = (l + r) % mod;
  return u * v % mod * power(2,mod-2,mod) % mod;
}
ll g(ll n){
  ll ans = 0, d = 1;
  while (d <= n){
    ll gt = (n / d);
    ll c = n / gt;
    ans = (ans + sum(d%mod,c%mod)*(gt%mod)%mod) % mod;
    d = c + 1;
  }
  return ans;
}
int main() 
{
    ll l , r;
    cin >> l >> r;
    cout << (g(r) - g(l - 1) + mod) % mod;
    return 0;
}

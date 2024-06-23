#include <bits/stdc++.h>
#define ll long long 
using namespace std;
map <pair<int,int>,int> mps;
string a[1002323];
int n;
int d[1000423]; // 0 -> 1000423 - 1 
ll mul(ll a, ll b, ll c){ // O(logb)
  if (b == 0) return 0;
  if (b == 1) return a % c;
  ll t = mul(a,b/2,c);
  t = (t + t) % c;
  // t < c 
  // t + t < 2c 
  // c <= MAX_LL / 2 
  // 9e18
  if (b % 2 == 0) return t; 
  else return (t + a) % c;
}
ll power(ll a, ll b, ll c){ // O(log2(b) * log2(c))
  if (b == 0) return 1 % c;
  if (b == 1) return a % c;
  ll t = power(a,b/2,c);
  // t < c
  t = mul(t,t,c); // log2(t) // t < c 
  if (b%2==0) return t; else return mul(t,a,c);
}
// (10^18)^(10^18) % (10^18)
// a % b = (a1 + a2) % b | a1 + a2 = a 
int main() 
{

}
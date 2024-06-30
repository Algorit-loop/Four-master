#include <iostream>
using namespace std;
int f[100003],n;
int pre[1000004];
int main() 
{
  // dua em ve ben do 
    cin >> n >> k;
    f[0] = 1;
    pre[0] = 1; 
    for (int i = 1; i <= n; i++){
      // -> f[i - k] + f[i - k + 1] + f[i - k + 2] + .. + f[i - 1]
      // pre[i - 1] - pre[i - k - 1];
      if (i - k - 1 >= 0) f[i] = pre[i - 1] - pre[i - k - 1]; else f[i] = pre[i - 1];
      pre[i] = pre[i - 1] + f[i];
    }
    // 1 <= n , k <= 20 -> quay lui 
    // dpt O(n * k) -> O(n) -> dp 
    // 1 <= n,k <= 10^6 -> dp + prefix sun 
    // 1 <= n <= 10^18 , 1 <= k <= 50 -> 3* (multi matrix)
    cout << f[n];
    return 0;
}
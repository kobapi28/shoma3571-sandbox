#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  int k,x;
  cin >> k >> x;

  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  bool twoTimes = false;

  // k: クーポンの枚数
  // x: クーポンによって引かれる金額
  while (k > 0) {
    // 大きい順にソート
    sort(a.begin(), a.end());
    // reverse(a.begin(),a.end());

    if (twoTimes) {
      for (int i=n-1; i>=0; i--) {
        a[i] = 0;
        k--;
        if (k == 0) {
          break;
        }
      }
    } else {
      for (int i=n-1; i>=0; i--) {
        int usable_ticket = a[i] / x;
        int use_ticket = min(k, usable_ticket);
        a[i] = max(a[i] - use_ticket * x, 0);
        k -= use_ticket;

        if (k == 0) {
          break;
        }
      } 
    }
    twoTimes = true;
  }


  ll sum = 0;
  for (int i=0; i<n; i++) {
    sum += a[i];
  }

  cout << sum << endl;
}
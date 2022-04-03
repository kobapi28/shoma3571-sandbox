#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// vector<ll> a(2*100000);
// vector<ll> b(2*100000);

// bool ok = false;



// bool check(ll x, ll y, ll k) {
//   return abs(x-y) <= k;
// }

// void dfs(ll i, ll n, ll k, ll z) {
//   if (ok) {
//     return;
//   }
//   // 最後まで辿り着いた場合
//   if (i == n-1) {
//     ok = true;
//     return;
//   }

//   if (check(z, a[i+1], k)) dfs(i+1, n, k, a[i+1]);
//   if (check(z, b[i+1], k)) dfs(i+1, n, k, b[i+1]);
// }

// int main() {
//   ll n, k;
//   cin >> n >> k;

  

//   for(int i=0; i<n; i++) {
//     cin >> a[i];
//   }
//   for(int i=0; i<n; i++) {
//     cin >> b[i];
//   }

//   dfs(0, n, k, a[0]);
//   if (!ok) {
//     dfs(0, n, k, b[0]);
//   }
  

//   if (ok) {
//     cout << "Yes" << endl;
//   } else {
//     cout << "No" << endl;
//   }
// }

int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  vector<ll> b(n);

  vector<bool> check_a(n);
  vector<bool> check_b(n);
  

  for(int i=0; i<n; i++) {
    cin >> a[i];
    check_a[i] = false;
  }
  for(int i=0; i<n; i++) {
    cin >> b[i];
    check_b[i] = false;
  }


  check_a[0] = true;
  check_b[0] = true;




  for (int i=1; i<n; i++) {
    if (!check_a[i-1] && !check_b[i-1]) {
      cout << "No" << endl;
      return 0;
    }


    if (check_a[i-1] && abs(a[i-1]-a[i]) <= k) {
      check_a[i] = true;
    }
    if (check_a[i-1] && abs(a[i-1]-b[i]) <= k) {
      check_b[i] = true;
    }
    if (check_b[i-1] && abs(b[i-1]-a[i]) <= k) {
      check_a[i] = true;
    }
    if (check_b[i-1] && abs(b[i-1]-b[i]) <= k) {
      check_b[i] = true;
    }
  }

  if (check_a[n-1] || check_b[n-1]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
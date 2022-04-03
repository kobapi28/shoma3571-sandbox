#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n,m;
  cin >> n >> m;

  vector<ll> a(n);
  vector<ll> b(m);

  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  for (int i=0; i<m; i++) {
    cin >> b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());


  for (int i=0; i<m; i++) {
    ll x = b[i];
    for (int j=0; j<a.size(); j++) {
      if (x == a[j]) {
        a.erase(a.begin() + j);
        break;
      }
      if (j==a.size()-1) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;


}
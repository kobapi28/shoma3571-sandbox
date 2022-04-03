#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;

  vector<ll> a(n);
  vector<ll> b(n);
  map<int, int> mp;

  for (int i=0; i<n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  for (int i=0; i<n; i++) {
    cin >> b[i];
  }

  int equal = 0;
  for (int i=0; i<n; i++) {
    if (a[i] == b[i]) equal++;
  }

  int num = 0;

  for (int i=0; i<n; i++) {
    if (mp.count(b[i])) num++;
  }

  cout << equal << endl;
  cout << num - equal << endl;


}
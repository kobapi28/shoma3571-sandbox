#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll q;
  cin >> q;
  vector<ll> a;

  for (ll i=0; i<q; i++) {
    int p; cin >> p;
    if (p==1) {
      ll x; cin >> x;
      // aにxを追加
      a.push_back(x);
    } else {
      ll x, k;
      cin >> x >> k;
      sort(a.begin(), a.end());

      if (p==2) {
        // aのx以下の要素のうち大きい方からk番目の値を出力
        // x以下の要素がk個ない場合は-1

      } else {
        // aのx以上の要素のうち小さい方からk番目の値を出力。
        // x以上の要素がk個ない場合は-1
      }
    }
  }
}
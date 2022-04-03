#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<tuple<ll, ll, char>> d(n);
  vector<ll> x(n);
  vector<ll> y(n);

  for (int i=0; i<n; i++) {
    cin >> x[i] >> y[i];
  }

  string s;
  cin >> s;

  for (int i=0; i<n; i++) {
    d[i] = make_tuple(x[i], y[i], s[i]);
  }

  sort(d.begin(), d.end());


  // // for debug
  // for (int i=0; i<n; i++) {
  //   cout << d[i].first << " " << d[i].second << endl;
  // }



  vector<tuple<ll, ll, char>> right;
  vector<tuple<ll, ll, char>> left;

  for (int i=0; i<n; i++) {
    if (get<2>(d[i]) == 'R') {
      right.push_back(d[i]);
    } else {
      left.push_back(d[i]);
    }
  }




  // y座標が同じ人なら衝突の可能性あり
  // 右に向いていく人
  for (int i=0; i<right.size(); i++) {
    // 左に向いていく人
    for (int j=0; j<left.size(); j++) {
      // y座標が同じ
      if (get<1>(right[i]) == get<1>(left[j])){
        // x座標が右にいくやつの方が小さいとき
        if (get<0>(right[i]) < get<0>(left[j])) {
          // ぶつかるパターン
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int value = 998244353;

int main() {
  ll n;
  cin >> n;

  vector<ll> eachNumber(10);
  for (int i=1; i<10; i++) {
    eachNumber[i] = 1;
  }

  vector<ll> eachBefore(10);

  ll ans = 0;
  for (int i=1; i<n; i++) {
    for (int j=1; j<10; j++) {
      eachBefore[j] = eachNumber[j];
    }
    for (int j=1; j<10; j++) {
      if (j == 1) {
        eachNumber[j] = eachBefore[j] + eachBefore[j+1];
      } else if (j == 9) {
        eachNumber[j] = eachBefore[j] + eachBefore[j-1];
      } else {
        eachNumber[j] = eachBefore[j] + eachBefore [j-1] + eachBefore[j+1];
      }
      eachNumber[j] = eachNumber[j] % value;
    }
  }

  for (int i=1; i<10; i++) {
    ans += eachNumber[i];
    ans = ans % value;
  }

  cout << ans % value << endl;
}
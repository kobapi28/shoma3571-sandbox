#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> s(n);
  vector<int> ans(n);

  for (int i=0; i<n; i++) {
    cin >> s[i];
  } 
  for (int i=0; i<n; i++) {
    cin >> ans[i];
  }

  long long nowTime = ans[0];
  for (int i=1; i<n; i++) {
    if (ans[i] < (nowTime + s[i-1])) {
      // ansの更新はなし
      nowTime = ans[i];
    } else {
      ans[i] = nowTime + s[i-1];
      nowTime += s[i-1];
    }
  }

  if (ans[0] > ans[n-1]+s[n-1]) ans[0] = ans[n-1]+s[n-1];
  nowTime = ans[0];
  for (int i=1; i<n; i++) {
    if (ans[i] < (nowTime + s[i-1])) {
      // ansの更新はなし
      nowTime = ans[i];
    } else {
      ans[i] = nowTime + s[i-1];
      nowTime += s[i-1];
    }
  }





  for (int i=0; i<n; i++) {
    cout << ans[i] << endl;
  }
}